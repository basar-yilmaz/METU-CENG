#ifndef HELPER_H
#define HELPER_H

//#include "identifier.h"
#include "ext2fs.h"
#include "ext2fs_print.h"
#include "ext2fs_print.c"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <unistd.h>
#include <fcntl.h>
#include <vector>
#include <cmath> // For ceil

using namespace std;

#define BLOCK_OFFSET(block) (blockSize + (block - 1) * blockSize)

/* Prototypes */
void init();
void info();
void getSuperBlock(struct ext2_super_block *superBlock);
void getGroupDescriptors(vector<ext2_block_group_descriptor> &groupDescriptors);

struct ext2_inode *getExactInode(const int &inodeNum);

void printInodeBitmaps();
void fillInodeBitmaps();
vector<vector<bool>> fixInodeBitmaps();
void writeInodeBitmaps();

void printBlockBitmaps();
void fillBlockBitmaps();
void markBlockAsUsed(vector<vector<bool>> &blockBitmaps, uint32_t blockNumber);
void markMetadataBlocks(vector<vector<bool>> &blockBitmaps);
void traverseIndirectBlocks(uint32_t block, int level, vector<vector<bool>> &blockBitmaps);
void markInodeBlocksAsUsed(const ext2_inode &inode, vector<vector<bool>> &blockBitmaps);
void writeBlockBitmaps();

void printFS(const struct ext2_inode *inode, int level);
void parseRootInode();

uint32_t findMissingBlock(ext2_inode &inode, int index);
bool isValidBlock(uint32_t block);
uint32_t *readBlock(uint32_t block);
void writeBlock(uint32_t block, uint32_t *buffer);
void verifyIndirectPointers(ext2_inode &inode, uint32_t block, int level);
void verifyDirectPointers(ext2_inode &inode);
void verifyAndCorrectInodes();
#endif // HELPER_H
