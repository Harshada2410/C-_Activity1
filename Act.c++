#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    int id;
    string title, author;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
    }

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "\nLibrary Books:\n";
        for (Book &book : books) {
            book.display();
        }
    }

    void searchBook() {
        int searchId;
        cout << "Enter Book ID to search: ";
        cin >> searchId;

        for (Book &book : books) {
            if (book.id == searchId) {
                cout << "Book Found:\n";
                book.display();
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.displayBooks(); break;
            case 3: library.searchBook(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
