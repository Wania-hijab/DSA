#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    string bookId;
    string bookName; 
    double bookPrice;
    string bookAuthor; 
    string bookISBN;

public:
    // Default constructor
    Book() : bookId(""), bookName(""), bookPrice(0.0), bookAuthor(""), bookISBN("") {}

    // Parameterized constructor
    Book(string id, string name, double price, string author, string isbn)
        : bookId(id), bookName(name), bookPrice(price), bookAuthor(author), bookISBN(isbn) {}

    // Getters
    string getBookId() const { return bookId; }
    string getBookName() const { return bookName; }
    double getBookPrice() const { return bookPrice; }
    string getBookAuthor() const { return bookAuthor; }
    string getBookISBN() const { return bookISBN; }

    // Setters
    void setBookId(string id) { bookId = id; }
    void setBookName(string name) { bookName = name; }
    void setBookPrice(double price) { bookPrice = price; }
    void setBookAuthor(string author) { bookAuthor = author; }
    void setBookISBN(string isbn) { bookISBN = isbn; }
};


class Node {
private:
    Book book; 
    Node* next;
    Node* prev;

public:
    // Default constructor
    Node() : next(NULL), prev(NULL) {}

    // Parameterized constructor
    Node(Book b) : book(b), next(NULL), prev(NULL) {}

    // Getters
    Book getBook() const { return book; }
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }

    // Setters
    void setBook(Book b) { book = b; }
    void setNext(Node* n) { next = n; }
    void setPrev(Node* p) { prev = p; }
};


class BookList {
private:
    Node* head;  // Head of the list

public:
    BookList() : head(NULL) {}

    // Add a book to the list
    void addBook(string bookId, string bookName, double bookPrice, string bookAuthor, string bookISBN) {
        Book newBook(bookId, bookName, bookPrice, bookAuthor, bookISBN);
        Node* newNode = new Node(newBook);

        if (head == NULL) {
            head = newNode;
            head->setNext(head);  // Circular: next points to head
            head->setPrev(head);  // Circular: prev points to head
        } else {
            Node* last = head->getPrev();  // Get the last node
            last->setNext(newNode);
            newNode->setPrev(last);
            newNode->setNext(head);  // Circular link
            head->setPrev(newNode);  // Head's prev is the new last node
        }
        cout << "Book added successfully." << endl;
    }

    // Remove a book by bookId
    void removeBook(string bookId) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->getBook().getBookId() == bookId) {
                if (current == head && head->getNext() == head) {  // Only one node
                    delete current;
                    head = NULL;
                } else {
                    current->getPrev()->setNext(current->getNext());
                    current->getNext()->setPrev(current->getPrev());
                    if (current == head) head = current->getNext();  // Update head if needed
                }
                delete current;
                cout << "Book removed successfully." << endl;
                return;
            }
            current = current->getNext();
        } while (current != head);
        cout << "Book not found!" << endl;  // Invalid bookId
    }

    // Update a book by bookId
    void updateBook(string bookId, string bookName, double bookPrice, string bookAuthor, string bookISBN) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->getBook().getBookId() == bookId) {
                Book updatedBook(bookId, bookName, bookPrice, bookAuthor, bookISBN);
                current->setBook(updatedBook);
                cout << "Book updated successfully." << endl;
                return;
            }
            current = current->getNext();
        } while (current != head);
        cout << "Book not found!" << endl;
    }

    // Print all books
    void printBooks() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << "Book ID: " << current->getBook().getBookId()
                 << ", Name: " << current->getBook().getBookName()
                 << ", Price: " << current->getBook().getBookPrice()
                 << ", Author: " << current->getBook().getBookAuthor()
                 << ", ISBN: " << current->getBook().getBookISBN() << endl;
            current = current->getNext();
        } while (current != head);
    }

    // Print a specific book by bookId
    void printBook(string bookId) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->getBook().getBookId() == bookId) {
                cout << "Book ID: " << current->getBook().getBookId()
                     << ", Name: " << current->getBook().getBookName()
                     << ", Price: " << current->getBook().getBookPrice()
                     << ", Author: " << current->getBook().getBookAuthor()
                     << ", ISBN: " << current->getBook().getBookISBN() << endl;
                return;
            }
            current = current->getNext();
        } while (current != head);
        cout << "Book not found!" << endl;
    }
};

int main() {
    cout << "----OPERATIONS ON DOUBLY CIRCULAR LINKED LIST FOR BOOKS----" << endl << endl;

    BookList bookList;

    // Step 1: Call addBook method 10 times
    bookList.addBook("1", "Book1", 10.99, "Author1", "ISBN1");
    bookList.addBook("2", "Book2", 15.99, "Author2", "ISBN2");
    bookList.addBook("3", "Book3", 20.99, "Author3", "ISBN3");
    bookList.addBook("4", "Book4", 25.99, "Author4", "ISBN4");
    bookList.addBook("5", "Book5", 30.99, "Author5", "ISBN5");
    bookList.addBook("6", "Book6", 35.99, "Author6", "ISBN6");
    bookList.addBook("7", "Book7", 40.99, "Author7", "ISBN7");
    bookList.addBook("8", "Book8", 45.99, "Author8", "ISBN8");
    bookList.addBook("9", "Book9", 50.99, "Author9", "ISBN9");
    bookList.addBook("10", "Book10", 55.99, "Author10", "ISBN10");

    // Step 2: Call printBook method 1 time (e.g., for bookId "1")
    cout << "Printing book with ID '1':" << endl;
    bookList.printBook("1");

    // Step 3: Call removeBook method 2 times (one valid, one invalid)
    cout << "Removing book with ID '1' (valid):" << endl;
    bookList.removeBook("1");  // Valid bookId
    cout << "Removing book with ID '999' (invalid):" << endl;
    bookList.removeBook("999");  // Invalid bookId

    // Step 4: Call printBook method 1 time (e.g., for bookId "2")
    cout << "Printing book with ID '2':" << endl;
    bookList.printBook("2");

    // Step 5: Call updateBook method followed by printBook
    cout << "Updating book with ID '2':" << endl;
    bookList.updateBook("2", "UpdatedBook2", 60.99, "UpdatedAuthor2", "UpdatedISBN2");
    cout << "Printing updated book with ID '2':" << endl;
    bookList.printBook("2");

    return 0;
}

