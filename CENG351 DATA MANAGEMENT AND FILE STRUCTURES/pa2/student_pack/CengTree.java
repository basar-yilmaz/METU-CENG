import java.util.ArrayList;
import java.util.Stack;

public class CengTree {
    public CengTreeNode root;
    // Any extra attributes...

    public CengTree(Integer order) {
        CengTreeNode.order = order;

        // create empty root
        this.root = new CengTreeNodeLeaf(null);
    }

    public void addBook(CengBook book) {
        Integer bookID = book.getBookID();

        // start from root to find the place to be inserted
        CengTreeNode currentNode = this.root;

        // traverse to the leaf node
        while (currentNode.type != CengNodeType.Leaf) {

            // we are in an internal node
            CengTreeNodeInternal internalNode = (CengTreeNodeInternal) currentNode;
            int placeHolder = 0;
            for (int i = 0; i < internalNode.keyCount(); i++) {
                if (bookID >= internalNode.keyAtIndex(i)) {
                    // move to the next key
                    placeHolder++;
                } else if (bookID < internalNode.keyAtIndex(i)) {
                    // traverse down the tree
                    currentNode = internalNode.getAllChildren().get(placeHolder);
                    break;
                }
            }
            if (placeHolder == internalNode.keyCount()) {
                currentNode = internalNode.getAllChildren().get(placeHolder);
            }
        }

        // leaf node to be placed in
        CengTreeNodeLeaf leafNode = (CengTreeNodeLeaf) currentNode;

        // find proper index to insert
        int insertIndex = 0;
        for (int i = 0; i < leafNode.bookCount(); i++) {
            if (bookID >= leafNode.bookKeyAtIndex(i)) {
                insertIndex++;
            } else {
                break;
            }
        }

        // insert the book to the leaf node
        leafNode.insertBookAtIndex(book, insertIndex);

        // check if leaf node is full + 1

        // we will handle copy up in the handleLeafOverflow function
        if (leafNode.bookCount() > 2 * CengTreeNode.order) {
            handleLeafOverflow(leafNode);
        }

    }

    public ArrayList<CengTreeNode> searchBook(Integer bookID) {
        CengTreeNode currentNode = this.root;
        ArrayList<Object[]> visitedNodes = new ArrayList<>();
        int level = 0;
        // if (currentNode.type == CengNodeType.Leaf) {
        // visitedNodes.add(new Object[] { currentNode, level++ });
        // }
        while (currentNode.type != CengNodeType.Leaf) {
            visitedNodes.add(new Object[] { currentNode, level++ });
            currentNode = traverseTree(bookID, (CengTreeNodeInternal) currentNode);
        }

        CengTreeNodeLeaf leafNode = (CengTreeNodeLeaf) currentNode;

        int placeHolder = 0;
        for (; placeHolder < leafNode.bookCount(); placeHolder++) {
            if (bookID == leafNode.bookKeyAtIndex(placeHolder)) {
                break;
            }
        }

        placeHolder = placeHolder == leafNode.bookCount() ? -31 : placeHolder;

        if (placeHolder == -31) {
            System.out.printf("Could not find %d.%n", bookID);
            return null;
        }

        // print out the structre
        printIndex(visitedNodes, level, bookID, placeHolder, leafNode);

        ArrayList<CengTreeNode> visitedNodes2 = new ArrayList<>();
        for (Object[] node : visitedNodes) {
            visitedNodes2.add((CengTreeNode) node[0]);
        }
        return visitedNodes2;
    }

    public void printTree() {

        Stack<Object[]> stack = new Stack<>();

        // create a pair of node and level
        // we will stack dfs from root to leaf
        stack.push(new Object[] { this.root, 0 });

        while (!stack.isEmpty()) {
            Object[] currentPair = stack.pop();
            CengTreeNode currentNode = (CengTreeNode) currentPair[0];
            int currentLevel = (int) currentPair[1];
            String tab = "";

            // prepare tab
            for (int i = 0; i < currentLevel; i++)
                tab += "\t";

            if (currentNode.getType() == CengNodeType.Internal) {
                // at this point we know currentNode is an internal node
                int keyCount = ((CengTreeNodeInternal) currentNode).keyCount();

                // start index tag
                System.out.printf("%s<index>%n", tab);

                for (int i = 0; i < keyCount; i++) {
                    System.out.printf("%s%s%n", tab, ((CengTreeNodeInternal) currentNode).keyAtIndex(i));
                }
                // end index tag
                System.out.printf("%s</index>%n", tab);

                // push children to stack
                for (int i = keyCount; i >= 0; i--) {
                    CengTreeNode childNode = ((CengTreeNodeInternal) currentNode).getAllChildren().get(i);
                    if (childNode != null) {
                        stack.push(new Object[] { childNode, currentLevel + 1 });
                    }
                }
            } else {
                // at this point we know currentNode is a leaf node
                int keyCount = ((CengTreeNodeLeaf) currentNode).bookCount();

                // start data tag
                System.out.printf("%s<data>%n", tab);

                for (int i = 0; i < keyCount; i++) {
                    System.out.printf("%s<record>%s</record>%n", tab,
                            ((CengTreeNodeLeaf) currentNode).getBookAtIndex(i).fullName());
                }
                // end data tag
                System.out.printf("%s</data>%n", tab);
            }
        }
    }

    // Any extra functions...

    public void handleLeafOverflow(CengTreeNodeLeaf leafNode) {
        // split the leaf node
        CengTreeNodeLeaf rightNode = new CengTreeNodeLeaf(leafNode.getParent());
        CengTreeNodeLeaf leftNode = new CengTreeNodeLeaf(leafNode.getParent());

        // move half of the books to the new leaf node
        int bookCount = leafNode.bookCount();
        int rightHalf = bookCount / 2;

        // store the middle key
        int copyUpKey = leafNode.bookKeyAtIndex(rightHalf);

        // fill the right node
        for (int i = rightHalf; i < bookCount; i++) {
            rightNode.insertBookAtIndex(leafNode.getBookAtIndex(i), i - rightHalf);
        }

        // fill the left node
        for (int i = 0; i < rightHalf; i++) {
            leftNode.insertBookAtIndex(leafNode.getBookAtIndex(i), i);
        }

        CengTreeNodeInternal parent = (CengTreeNodeInternal) leafNode.getParent();

        if (parent != null) {
            parent = this.setNonNullParent(parent, leftNode, rightNode, leafNode, copyUpKey);
        } else {
            parent = new CengTreeNodeInternal(null);
            this.root = parent;

            parent = this.setNullParent(parent, leftNode, rightNode);
            leftNode.setParent(parent);
            rightNode.setParent(parent);
        }

        // check if parent is full + 1
        if (parent.keyCount() > 2 * CengTreeNode.order) {
            handleInternalOverflow(parent);
        }
    }

    public CengTreeNodeInternal setNullParent(CengTreeNodeInternal internalNode, CengTreeNodeLeaf leftNode,
            CengTreeNodeLeaf rightNode) {
        internalNode.getKeys().add(rightNode.bookKeyAtIndex(0));
        internalNode.getAllChildren().add(0, leftNode);
        internalNode.getAllChildren().add(1, rightNode);

        return internalNode;

    }

    public CengTreeNodeInternal setNonNullParent(CengTreeNodeInternal internalNode, CengTreeNodeLeaf leftNode,
            CengTreeNodeLeaf rightNode, CengTreeNodeLeaf leafNode, int copyUpKey) {
        internalNode.getKeys().add(internalNode.getAllChildren().indexOf(leafNode), copyUpKey);
        internalNode.getAllChildren().add(internalNode.getAllChildren().indexOf(leafNode) + 1, rightNode);
        internalNode.getAllChildren().set(internalNode.getAllChildren().indexOf(leafNode), leftNode);

        return internalNode;

    }

    public void handleInternalOverflow(CengTreeNodeInternal internalNode) {
        int keyCount = internalNode.keyCount();
        CengTreeNodeInternal parent = (CengTreeNodeInternal) internalNode.getParent();

        // Split the internal node
        int pushUpKey = internalNode.keyAtIndex(keyCount / 2);

        // Create new internal node (right)
        CengTreeNodeInternal newInternalNodeRight = internalNode.createAndMoveKeys(keyCount / 2, keyCount);

        // create new internal node (left)
        CengTreeNodeInternal newInternalNodeLeft = internalNode.createAndMoveKeysToLeft(keyCount / 2);

        // Insert the pushed-up key to the parent
        if (parent != null) {
            this.setNullParentInternal(parent, newInternalNodeLeft, newInternalNodeRight, internalNode, pushUpKey);
        } else {
            // Create a new root if the current node is the root
            parent = new CengTreeNodeInternal(null);

            // parent must be the root
            this.root = parent;
            parent = this.setNonNullParentInternal(parent, newInternalNodeLeft, newInternalNodeRight, pushUpKey);

            // set parent
            newInternalNodeLeft.setParent(parent);
            newInternalNodeRight.setParent(parent);
        }

        // Check if the parent is full + 1
        if (parent.keyCount() > 2 * CengTreeNode.order) {
            handleInternalOverflow(parent);
        }
    }

    public CengTreeNodeInternal setNullParentInternal(CengTreeNodeInternal parent,
            CengTreeNodeInternal newInternalNodeLeft, CengTreeNodeInternal newInternalNodeRight,
            CengTreeNodeInternal internalNode, int pushUpKey) {
        parent.getKeys().add(parent.getAllChildren().indexOf(internalNode), pushUpKey);
        parent.getAllChildren().add(parent.getAllChildren().indexOf(internalNode) + 1, newInternalNodeRight);

        // overwrite the old child
        parent.getAllChildren().set(parent.getAllChildren().indexOf(internalNode), newInternalNodeLeft);
        return parent;
    }

    public CengTreeNodeInternal setNonNullParentInternal(CengTreeNodeInternal parent,
            CengTreeNodeInternal newInternalNodeLeft, CengTreeNodeInternal newInternalNodeRight,
            int pushUpKey) {
        // add key
        parent.getKeys().add(pushUpKey);
        // add child respectively left, right
        parent.getAllChildren().add(0, newInternalNodeLeft);
        parent.getAllChildren().add(1, newInternalNodeRight);
        return parent;
    }

    private void printIndex(ArrayList<Object[]> nodeList, int level, int bookID, int placeHolder,
            CengTreeNodeLeaf leafNode) {
        if (nodeList.isEmpty()) {
            System.out.printf("<record>%s</record>%n",
                    ((CengTreeNodeLeaf) this.root).getBookAtIndex(placeHolder).fullName());
            return;
        }

        int currentLevel = 0;
        for (Object[] node : nodeList) {
            CengTreeNode currentNode = (CengTreeNode) node[0];
            currentLevel = (int) node[1];
            String tab = "";

            if (currentNode.getType() != CengNodeType.Leaf) {
                CengTreeNodeInternal internalNode = (CengTreeNodeInternal) currentNode;
                int keyCount = internalNode.keyCount();

                for (int j = 0; j < currentLevel; j++) {
                    tab += "\t";
                }
                System.out.printf("%s<index>%n", tab);

                for (int j = 0; j < keyCount; j++) {
                    System.out.printf("%s%s%n", tab, internalNode.keyAtIndex(j));
                }
                System.out.printf("%s</index>%n", tab);
            }
        }

        String tab = "";
        for (int j = 0; j < currentLevel + 1; j++) {
            tab += "\t";
        }
        System.out.printf("%s<record>%s</record>%n", tab, leafNode.getBookAtIndex(placeHolder).fullName());
    }

    /**
     * Traverses the tree to find the child node associated with the given key.
     *
     * @param key          The key to search for.
     * @param internalNode The internal node to start the traversal from.
     * @return The child node associated with the given key.
     */
    private CengTreeNode traverseTree(int key, CengTreeNodeInternal internalNode) {
        int pos = 0;
        // traverse to the leaf node
        while (internalNode.getKeys().size() > pos) {
            if (key >= internalNode.keyAtIndex(pos)) {
                pos += 1;
            } else {
                break;
            }
        }
        return internalNode.getAllChildren().get(pos);
    }
}
