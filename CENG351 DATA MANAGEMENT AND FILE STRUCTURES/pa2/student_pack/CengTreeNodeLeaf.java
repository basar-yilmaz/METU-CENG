import java.util.ArrayList;

public class CengTreeNodeLeaf extends CengTreeNode {
    private ArrayList<CengBook> books;
    // TODO: Any extra attributes

    public CengTreeNodeLeaf(CengTreeNode parent) {
        super(parent);
        this.type = CengNodeType.Leaf; // set the type of the node extended from parent class
        this.books = new ArrayList<CengBook>();
    }

    // GUI Methods - Do not modify
    public int bookCount() {
        return books.size();
    }

    public Integer bookKeyAtIndex(Integer index) {
        if (index >= this.bookCount()) {
            return -1;
        } else {
            CengBook book = this.books.get(index);

            return book.getBookID();
        }
    }

    // Extra Functions
    public void insertBookAtIndex(CengBook book, Integer index) {
        this.books.add(index, book);
    }

    public CengBook getBookAtIndex(int index) {
        return this.books.get(index);
    }
}
