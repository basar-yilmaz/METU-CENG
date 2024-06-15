import java.util.ArrayList;

public class CengTreeNodeInternal extends CengTreeNode {
    private ArrayList<Integer> keys;
    private ArrayList<CengTreeNode> children;

    public CengTreeNodeInternal(CengTreeNode parent) {
        super(parent);
        this.type = CengNodeType.Internal;
        this.keys = new ArrayList<Integer>();
        this.children = new ArrayList<CengTreeNode>();
    }

    // GUI Methods - Do not modify
    public ArrayList<CengTreeNode> getAllChildren() {
        return this.children;
    }

    public Integer keyCount() {
        return this.keys.size();
    }

    public Integer keyAtIndex(Integer index) {
        if (index >= this.keyCount() || index < 0) {
            return -1;
        } else {
            return this.keys.get(index);
        }
    }

    // Extra Functions
    public ArrayList<Integer> getKeys() {
        return this.keys;
    }

    /**
     * Creates a new internal node and moves keys and child nodes to the new node.
     *
     * @param midPoint The midpoint index.
     * @param keyCount The number of keys.
     * @return The newly created internal node.
     */
    public CengTreeNodeInternal createAndMoveKeys(int midPoint, int keyCount) {
        CengTreeNodeInternal newInternalNode = new CengTreeNodeInternal(this.getParent());

        // Move keys to the new internal node
        for (int i = midPoint + 1; i < keyCount; i++) {
            newInternalNode.keys.add(this.keyAtIndex(i));
        }

        // set parent - child relationship
        for (int i = midPoint + 1; i <= keyCount; i++) {
            this.children.get(i).setParent(newInternalNode);
            newInternalNode.children.add(i - midPoint - 1, this.children.get(i));
        }

        return newInternalNode;
    }

    /**
     * Creates a new internal node by moving keys to the left.
     *
     * @param midPoint The index at which to split the keys.
     * @return The newly created internal node.
     */
    public CengTreeNodeInternal createAndMoveKeysToLeft(int midPoint) {
        CengTreeNodeInternal newInternalNodeLeft = new CengTreeNodeInternal(this.getParent());

        // Move keys to the new internal node
        for (int i = 0; i < midPoint; i++) {
            newInternalNodeLeft.keys.add(this.keyAtIndex(i));
        }

        // Set parent-child relationship
        for (int i = 0; i <= midPoint; i++) {
            CengTreeNode child = this.children.get(i);
            child.setParent(newInternalNodeLeft);
            newInternalNodeLeft.children.add(i, child);
        }

        return newInternalNodeLeft;
    }
}
