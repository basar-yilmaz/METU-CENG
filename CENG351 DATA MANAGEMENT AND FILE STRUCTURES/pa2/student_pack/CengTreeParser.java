import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class CengTreeParser {
    public static ArrayList<CengBook> parseBooksFromFile(String filename) {
        ArrayList<CengBook> bookList = new ArrayList<CengBook>();

        // You need to parse the input file in order to use GUI tables.
        // TODO: Parse the input file, and convert them into CengBooks
        String line = null;
        String[] wholeInput = null;

        try {
            File my_file = new File(filename);
            Scanner my_reader = new Scanner(my_file);

            while (my_reader.hasNext()) {

                // read line
                line = my_reader.nextLine();

                wholeInput = line.split("[|]");

                bookList.add(new CengBook(Integer.parseInt(wholeInput[0]),
                        wholeInput[1],
                        wholeInput[2],
                        wholeInput[3]));

            }
            // close scanner
            my_reader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
        }

        return bookList;
    }

    public static void startParsingCommandLine() throws IOException {
        // TODO: Start listening and parsing command line -System.in-.
        // There are 4 commands:
        // 1) quit : End the app, gracefully. Print nothing, call nothing, just break
        // off your command line loop.
        // 2) add : Parse and create the book, and call
        // CengBookRunner.addBook(newlyCreatedBook).
        // 3) search : Parse the bookID, and call CengBookRunner.searchBook(bookID).
        // 4) print : Print the whole tree, call CengBookRunner.printTree().

        // Commands (quit, add, search, print) are case-insensitive.

        Scanner my_scanner = new Scanner(System.in);

        while (true) {
            String inpLine = my_scanner.nextLine();
            String[] wholeInput = inpLine.split("[|]");
            String command = wholeInput[0].toLowerCase();

            if (command.equals("quit")) {
                return;
            } else if (command.equals("add")) {
                CengBookRunner.addBook(new CengBook(Integer.parseInt(wholeInput[1]),
                        wholeInput[2],
                        wholeInput[3],
                        wholeInput[4]));
            } else if (command.equals("search")) {
                CengBookRunner.searchBook(Integer.parseInt(wholeInput[1]));
            } else if (command.equals("print")) {
                CengBookRunner.printTree();
            }
        }
    }
}
