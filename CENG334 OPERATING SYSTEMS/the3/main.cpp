#include "helper.h"

/* Global */
struct ext2_super_block superBlock;
struct ext2_block_group_descriptor groupDesc;
struct ext2_inode *root_inode = nullptr;
vector<ext2_block_group_descriptor> groupDescriptors;
vector<vector<ext2_inode>> inodes;
vector<vector<bool>> inodeBitmaps;
vector<vector<bool>> blockBitmaps;

int fileImage;
int blockSize, inodeSize, numGroups, last_bg_inodes = 0;

/***********************************************************/

void getSuperBlock(struct ext2_super_block *superBlock)
{
    // Read the super block
    lseek(fileImage, EXT2_BOOT_BLOCK_SIZE, SEEK_SET);
    read(fileImage, superBlock, sizeof(struct ext2_super_block));
}

void getGroupDescriptors(vector<ext2_block_group_descriptor> &groupDescriptors)
{
    // Resize the groupDescriptors vector to hold all descriptors
    groupDescriptors.resize(numGroups);

    // Iterate over block groups
    for (int groupIndex = 0; groupIndex < numGroups; groupIndex++)
    {
        int groupDescOffset = 0;

        // Calculate the offset of the block group descriptor
        // If the block size is greater than the sum of the boot block and super block sizes,
        // the block group descriptor table starts at the block size offset
        // Otherwise, the block group descriptor table starts at the sum of the boot block and super block sizes
        // This change is newly added to support the more than 2KB block size
        if (blockSize > EXT2_BOOT_BLOCK_SIZE + EXT2_SUPER_BLOCK_SIZE)
        {
            groupDescOffset = blockSize + groupIndex * sizeof(struct ext2_block_group_descriptor);
        }
        else
        {
            groupDescOffset = EXT2_BOOT_BLOCK_SIZE + EXT2_SUPER_BLOCK_SIZE + groupIndex * sizeof(struct ext2_block_group_descriptor);
        }

        // Read the block group descriptor
        lseek(fileImage, groupDescOffset, SEEK_SET);
        read(fileImage, &groupDescriptors[groupIndex], sizeof(struct ext2_block_group_descriptor));
    }
}

void fillInodes()
{
    int inodesPerGroup = superBlock.inodes_per_group;

    // Resize the inodes vector to hold all block groups
    inodes.resize(numGroups);

    // Read each block group's inode table
    for (int groupIndex = 0; groupIndex < numGroups; groupIndex++)
    {
        // Calculate the offset of the inode table for this group
        int inodeTableOffset = BLOCK_OFFSET(groupDescriptors[groupIndex].inode_table);

        // Calculate number of inodes in this group (handle last group having fewer inodes)
        int inodesInGroup = (groupIndex == numGroups - 1) ? (superBlock.inode_count - groupIndex * inodesPerGroup) : inodesPerGroup;

        // Resize the current group's vector to hold all inodes
        inodes[groupIndex].resize(inodesInGroup);

        // Seek to the inode table and read it
        lseek(fileImage, inodeTableOffset, SEEK_SET);
        read(fileImage, inodes[groupIndex].data(), inodesInGroup * sizeof(struct ext2_inode));
    }
}

struct ext2_inode *getExactInode(const int &inodeNum)
{
    // Calculate the block group and inode number
    int block_group = (inodeNum - 1) / superBlock.inodes_per_group;
    int inode = (inodeNum - 1) % superBlock.inodes_per_group;

    // Return the inode
    return &inodes[block_group][inode];
}

bool is_dot_or_dotdot(const char *name)
{
    return (strcmp(name, ".") == 0 || strcmp(name, "..") == 0);
}

bool check_permission(const struct ext2_inode *inode)
{
    return (inode->gid & EXT2_I_UID) == EXT2_I_UID;
}

bool checkNameIfLostAndFound(const char *name)
{
    if (strcmp(name, "lost+found") == 0)
    {
        return true;
    }
    return false;
}

bool checkInode(const struct ext2_inode *inode)
{
    return (inode->mode & 0xf000) == EXT2_I_DTYPE;
}

void printFS(const struct ext2_inode *inode, int level = 1)
{
    if (((inode->mode) & 0xf000) == EXT2_I_DTYPE)
    {
        int8_t block[blockSize];

        for (int i = 0; i < EXT2_NUM_DIRECT_BLOCKS; i++)
        {
            if (inode->direct_blocks[i] == 0)
                continue;

            lseek(fileImage, BLOCK_OFFSET(inode->direct_blocks[i]), SEEK_SET);
            read(fileImage, block, blockSize);

            int8_t *ptr = block;
            while (ptr < block + blockSize)
            {
                ext2_dir_entry *entry = (ext2_dir_entry *)ptr;

                // Allocate memory for the directory entry on the heap
                int entrySize = sizeof(ext2_dir_entry) + (int)entry->name_length + 1;
                ext2_dir_entry *heapEntry = (ext2_dir_entry *)malloc(entrySize);

                if (heapEntry != nullptr)
                {
                    // Copy the entire directory entry to the heap
                    memcpy(heapEntry, ptr, entrySize);

                    if (is_dot_or_dotdot(heapEntry->name))
                    {
                        ptr += entry->length;
                        free(heapEntry);
                        continue;
                    }
                    for (int j = 0; j < level; j++)
                    {
                        cout << "-";
                    }

                    heapEntry->name[(int)(heapEntry->name_length)] = '\0'; // Ensure null-terminated string

                    cout << " " << heapEntry->name;

                    ext2_inode *entry_inode = getExactInode(heapEntry->inode);

                    if (checkInode(entry_inode))
                    {
                        // if it is a directory
                        cout << "/" << endl;
                        if (!checkNameIfLostAndFound(heapEntry->name))
                        {
                            printFS(entry_inode, level + 1);
                        }
                    }
                    else
                    {
                        // if it is a file
                        cout << endl;
                    }

                    ptr += entry->length;

                    free(heapEntry);
                }
                else
                {
                    // Handle memory allocation failure
                    cerr << "Failed to allocate memory for directory entry" << endl;
                    break;
                }
            }
        }
    }
}

void get_dir(int inode_num)
{
    struct ext2_dir_entry *entry;
    unsigned int size;
    unsigned char block[blockSize];

    lseek(fileImage, BLOCK_OFFSET(getExactInode(inode_num)->direct_blocks[0]), SEEK_SET);
    read(fileImage, block, blockSize); /* read block from disk*/

    unsigned char *ptr = block;
    while (ptr < block + blockSize)
    {
        entry = (struct ext2_dir_entry *)ptr;

        print_dir_entry(entry, entry->name);

        size = entry->length;
        ptr += size;
    }
}

void parseRootInode()
{
    uint8_t block[blockSize];

    lseek(fileImage, BLOCK_OFFSET(root_inode->direct_blocks[0]), SEEK_SET);
    read(fileImage, block, blockSize);

    uint8_t *ptr = block;

    ext2_dir_entry *entry = (ext2_dir_entry *)ptr;

    cout << "- root/" << endl;

    printFS(getExactInode(entry->inode), 2);

    // print_dir_entry(entry, entry->name);
}

void printInodeBitmaps()
{
    for (int i = 0; i < inodeBitmaps.size(); ++i)
    {
        cout << "The bitmap of group " << i << ": ";
        for (int j = 0; j < inodeBitmaps[i].size(); ++j)
        {
            cout << inodeBitmaps[i][j];
        }
        cout << endl;
    }
}

void fillInodeBitmaps()
{
    for (int i = 0; i < numGroups; ++i)
    {
        // Calculate the size of the inode bitmap
        int bitmapSize = static_cast<int>(ceil(static_cast<double>(superBlock.inodes_per_group) / 8));

        // Allocate memory for the bitmap
        uint8_t *bitmap = new uint8_t[bitmapSize];
        memset(bitmap, 0, bitmapSize);

        // Seek to the bitmap location
        lseek(fileImage, BLOCK_OFFSET(groupDescriptors[i].inode_bitmap), SEEK_SET);

        // Read the bitmap
        read(fileImage, bitmap, bitmapSize);

        // Store the bitmap bits
        vector<bool> inodeBitmap;
        for (int j = 0; j < bitmapSize; ++j)
        {
            for (int k = 0; k < 8; ++k)
            { // Iterate over each bit
                inodeBitmap.push_back((bitmap[j] >> k) & 1);
            }
        }

        // Store the inode bitmap for this group
        inodeBitmaps.push_back(inodeBitmap);

        // Free allocated memory
        delete[] bitmap;
    }
}

vector<vector<bool>> fixInodeBitmaps()
{
    vector<vector<bool>> fixedInodeBitmaps;
    fixedInodeBitmaps.resize(numGroups);

    int inodesPerGroup = superBlock.inodes_per_group;
    for (int i = 0; i < numGroups; ++i)
    {
        fixedInodeBitmaps[i].resize(inodesPerGroup);
        for (int j = 0; j < inodesPerGroup; ++j)
        {
            if ((inodes[i][j].link_count != 0 && inodes[i][j].deletion_time == 0 ||
                 i == 0 && j <= 10))
            {
                fixedInodeBitmaps[i][j] = true;
            }
        }
    }

    return fixedInodeBitmaps;
}

void writeInodeBitmaps()
{

    for (int i = 0; i < groupDescriptors.size(); ++i)
    {
        // Calculate the size of the inode bitmap
        int bitmapSize = static_cast<int>(ceil(static_cast<double>(superBlock.inodes_per_group) / 8));

        // Allocate memory for the bitmap
        uint8_t *bitmap = new uint8_t[bitmapSize];
        memset(bitmap, 0, bitmapSize);

        // Write the bitmap bits
        int bitIndex = 0;
        for (int j = 0; j < bitmapSize; ++j)
        {
            for (int k = 0; k < 8; ++k)
            { // Iterate over each bit

                if (bitIndex < inodeBitmaps[i].size())
                {
                    bitmap[j] |= (inodeBitmaps[i][bitIndex] << k);
                    ++bitIndex;
                }
                else
                {
                    break; // All bits written, exit loop
                }
            }
        }

        // Seek to the bitmap location
        lseek(fileImage, BLOCK_OFFSET(groupDescriptors[i].inode_bitmap), SEEK_SET);

        // Write the bitmap
        write(fileImage, bitmap, bitmapSize);

        // Free allocated memory
        delete[] bitmap;
    }
}

void printBlockBitmaps()
{
    for (int i = 0; i < blockBitmaps.size(); ++i)
    {
        int cnt = 0;
        cout << "The bitmap of group " << i << ": ";
        for (int j = 0; j < blockBitmaps[i].size(); ++j)
        {
            // if (j == 255 && i == blockBitmaps.size() - 1)
            // {
            //     cout << "here i am ";
            // }
            if (j % 64 == 0)
                cout << endl;
            if (!blockBitmaps[i][j])
                cnt++;
            cout << blockBitmaps[i][j];
        }
        cout << " Group cnt: " << cnt << endl;
    }
}

void fillBlockBitmaps()
{
    for (int i = 0; i < numGroups; ++i)
    {
        int bitmapSize = static_cast<int>(ceil(static_cast<double>(superBlock.blocks_per_group) / 8));

        uint8_t *bitmap = new uint8_t[bitmapSize];
        memset(bitmap, 0, bitmapSize);

        lseek(fileImage, BLOCK_OFFSET(groupDescriptors[i].block_bitmap), SEEK_SET);
        read(fileImage, bitmap, bitmapSize);

        vector<bool> blockBitmap;
        for (int j = 0; j < bitmapSize; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {
                blockBitmap.push_back((bitmap[j] >> k) & 1);
                // if ((bitmap[j] >> k) & 1)
                // {
                //     cout << "Group: " << i << " Block: " << j * 8 + k << endl;
                // }
            }
        }

        blockBitmaps.push_back(blockBitmap);

        delete[] bitmap;
    }
}

void markBlockAsUsed(vector<vector<bool>> &blockBitmaps, uint32_t blockNumber)
{
    int group = blockNumber / superBlock.blocks_per_group;
    int index = blockNumber % superBlock.blocks_per_group;
    blockBitmaps[group][index] = true;
}

void markMetadataBlocks(vector<vector<bool>> &blockBitmaps)
{
    // Mark the superblock as used (first block of the filesystem)
    markBlockAsUsed(blockBitmaps, 0);

    // print out the block numbers of inode bitmaps
    for (int i = 0; i < numGroups; i++)
    {
        int block_bitmap_off = groupDescriptors[i].block_bitmap;

        int block_group_off = i * superBlock.blocks_per_group;
        while (block_group_off < block_bitmap_off)
        {
            markBlockAsUsed(blockBitmaps, block_group_off);
            block_group_off++;
        }
    }

    // Mark block and inode bitmaps and inode tables
    for (int group = 0; group < numGroups; group++)
    {
        markBlockAsUsed(blockBitmaps, groupDescriptors[group].block_bitmap);
        markBlockAsUsed(blockBitmaps, groupDescriptors[group].inode_bitmap);

        int inodeTableStart = groupDescriptors[group].inode_table;
        int inodeTableEnd = inodeTableStart + (superBlock.inodes_per_group * inodeSize + blockSize - 1) / blockSize;

        for (int block = inodeTableStart; block < inodeTableEnd; block++)
        {
            markBlockAsUsed(blockBitmaps, block);
        }
    }
}

void traverseIndirectBlocks(uint32_t block, int level, vector<vector<bool>> &blockBitmaps)
{
    if (block == 0)
        return; // No block to traverse

    markBlockAsUsed(blockBitmaps, block);

    uint32_t blocksPerIndirect = blockSize / sizeof(uint32_t);
    uint32_t indirectBlocks[blocksPerIndirect];

    lseek(fileImage, BLOCK_OFFSET(block), SEEK_SET);
    read(fileImage, indirectBlocks, blockSize);

    for (uint32_t i = 0; i < blocksPerIndirect; i++)
    {
        if (indirectBlocks[i] != 0)
        {
            if (level == 0)
            {
                markBlockAsUsed(blockBitmaps, indirectBlocks[i]);
            }
            else
            {
                traverseIndirectBlocks(indirectBlocks[i], level - 1, blockBitmaps);
            }
        }
    }
}

void markInodeBlocksAsUsed(const ext2_inode &inode, vector<vector<bool>> &blockBitmaps)
{
    // Mark direct blocks
    for (int i = 0; i < EXT2_NUM_DIRECT_BLOCKS; i++)
    {
        if (inode.direct_blocks[i] != 0)
        {
            markBlockAsUsed(blockBitmaps, inode.direct_blocks[i]);
        }
    }

    // Handle indirect blocks
    if (inode.single_indirect != 0)
    {
        traverseIndirectBlocks(inode.single_indirect, 0, blockBitmaps);
    }
    if (inode.double_indirect != 0)
    {
        traverseIndirectBlocks(inode.double_indirect, 1, blockBitmaps);
    }
    if (inode.triple_indirect != 0)
    {
        traverseIndirectBlocks(inode.triple_indirect, 2, blockBitmaps);
    }
}

void writeBlockBitmaps()
{
    for (int i = 0; i < numGroups; ++i)
    {
        int bitmapSize = static_cast<int>(ceil(static_cast<double>(superBlock.blocks_per_group) / 8));

        uint8_t *bitmap = new uint8_t[bitmapSize];
        memset(bitmap, 0, bitmapSize);

        int bitIndex = 0;
        for (int j = 0; j < bitmapSize; ++j)
        {
            for (int k = 0; k < 8; ++k)
            {

                if (bitIndex < blockBitmaps[i].size())
                {

                    bitmap[j] |= (blockBitmaps[i][bitIndex] << k);
                    ++bitIndex;
                }
                else
                {
                    break;
                }
            }
        }

        lseek(fileImage, BLOCK_OFFSET(groupDescriptors[i].block_bitmap), SEEK_SET);
        write(fileImage, bitmap, bitmapSize);

        delete[] bitmap;
    }
}

vector<vector<bool>> fixBlockBitmaps()

{
    vector<vector<bool>> blockBitmaps(numGroups);
    int blocksPerGroup = superBlock.blocks_per_group;

    // Initialize block bitmaps to false (free)
    for (int i = 0; i < numGroups; i++)
    {
        blockBitmaps[i].resize(blocksPerGroup, false);
    }

    // Mark metadata blocks as used
    markMetadataBlocks(blockBitmaps);

    // Mark used blocks based on inodes
    for (int group = 0; group < numGroups; group++)
    {
        for (int inode = 0; inode < superBlock.inodes_per_group; inode++)
        {
            const ext2_inode &currentInode = inodes[group][inode];
            if (inodeBitmaps[group][inode] && currentInode.block_count_512 != 0)
            {
                markInodeBlocksAsUsed(currentInode, blockBitmaps);
            }
        }
    }

    return blockBitmaps;
}

void info()
{
    cout << "Block size: " << EXT2_UNLOG(superBlock.log_block_size) << endl;
    cout << "Number of block groups: " << numGroups << endl;
    cout << "Number of inodes: " << superBlock.inode_count << endl;
    cout << "Number of inodes per group: " << superBlock.inodes_per_group << endl;
    cout << "Number of blocks per group: " << superBlock.blocks_per_group << endl;
    cout << "Last block inode count: " << superBlock.inodes_per_group - last_bg_inodes << endl;

    for (int i = 0; i < numGroups; i++)
    {
        cout << "BGD free inode count: " << groupDescriptors[i].free_inode_count << " # ";
        cout << "BGD free block count: " << groupDescriptors[i].free_block_count << endl;
    }
}

void init()
{
    // Read superblock from image
    getSuperBlock(&superBlock);

    // Get block size
    blockSize = EXT2_UNLOG(superBlock.log_block_size);

    // Get inode size
    inodeSize = superBlock.inode_size;

    // Get number of groups
    numGroups = (superBlock.inode_count + superBlock.inodes_per_group - 1) / superBlock.inodes_per_group;

    // Read group descriptor from image
    getGroupDescriptors(groupDescriptors);

    // Read inode table from image
    fillInodes();

    // Fill inode bitmaps
    fillInodeBitmaps();

    // Fill block bitmaps
    fillBlockBitmaps();

    // Set the root inode
    root_inode = getExactInode(EXT2_ROOT_INODE);

    // calculate last block group's inode count
    last_bg_inodes = superBlock.inode_count % superBlock.inodes_per_group;
}

int main(int argc, char *argv[])
{
    // Check if the user provided the correct number of arguments
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << " <image_file> <identifier_bytes...>" << endl;
        return 1;
    }

    // Identifier (ne işime yarıcak bi bilsem)
    // uint8_t *identifier = parse_identifier(argc, argv);

    // Read the image file
    fileImage = open(argv[1], O_RDWR);
    if (fileImage < 0)
    {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    init();

    inodeBitmaps = fixInodeBitmaps();
    writeInodeBitmaps();

    blockBitmaps = fixBlockBitmaps();
    writeBlockBitmaps();
    parseRootInode();

    close(fileImage);
    // delete[] identifier;
    return 0;
}
