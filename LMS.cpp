#include <bits/stdc++.h>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(const string& title, const string& author, int year) : title(title), author(author), year(year) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added to the library.\n";
    }

    void listBooks() const {
        cout << "Listing all books in the library:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << endl;
        }
    }

    void searchBook(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Book found:\n";
                cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book with title '" << title << "' not found.\n";
        }
    }

    void removeBook(const string& title) {
        auto it = std::remove_if(books.begin(), books.end(), [&title](const Book& book) { return book.getTitle() == title; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book removed from the library.\n";
        } else {
            cout << "Book with title '" << title << "' not found.\n";
        }
    }
};

int main() {
    Library library;

    // Add some initial books to the library
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    int choice;
    while (true) {
        cout << "Library Management System Menu:\n";
        cout << "1. List all books\n";
        cout << "2. Search book by title\n";
        cout << "3. Remove book\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program...\n";
                return 0;
            case 1:
                library.listBooks();
                break;
            case 2:
                {
                    string title;
                    cout << "Enter title of the book to search: ";
                    cin.ignore();
                    getline(cin, title);
                    library.searchBook(title);
                }
                break;
            case 3:
                {
                    string title;
                    cout << "Enter title of the book to remove: ";
                    cin.ignore();
                    getline(cin, title);
                    library.removeBook(title);
                }
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
