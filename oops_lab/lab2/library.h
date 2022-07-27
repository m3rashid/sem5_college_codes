#include <bits/stdc++.h>

#include "books.h"
#include "subscriptions.h"
using namespace std;

class Library {
   public:
    vector<Book> books;
    vector<Book> issued_books;
    vector<Subscription> subscriptions;

    Library() {}

    Book getBook(int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].bookId == bookId) {
                return books[i];
            }
        }
        return Book(-1, -1, "", "");
    };

    void addBook(int bookId, int type, string name = "", string author = "") {
        Book book = Book(bookId, type, name, author);
        books.push_back(book);
        cout << "Book Added" << endl;
    }

    void issueBook(int bookId) {
        Book book = getBook(bookId);
        if (book.bookId == -1) {
            cout << "Book not found" << endl;
            return;
        }
        issued_books.push_back(book);
        cout << "Book Issued" << endl;
    }

    void showIssuedBooks() {
        int i = 1;
        for (auto x : issued_books) {
            cout << "=== Details for Book " << i << " ===" << endl;
            cout << "Book Id: " << x.bookId << endl;
            cout << "Book Type: " << x.bookType << endl;
            cout << "Name: " << x.name << endl;
            cout << "Author: " << x.author << endl;
            cout << endl;
            i++;
        }
    }

    void removeBook(int bookId) {
        bool removed = false;
        for (auto x : books) {
            if (x.bookId == bookId) {
                remove(books.begin(), books.end(), x);
                removed = true;
                break;
            }
        }
        if (removed) {
            cout << "Book Removed" << endl;
        } else {
            cout << "Book Not Found" << endl;
        }
    }

    void showAllBooks() {
        int i = 1;
        for (auto x : books) {
            cout << "=== Details for Book " << i << " ===" << endl;
            cout << "Name: " << x.name << endl;
            cout << "Author: " << x.author << endl;
            cout << "Book Id: " << x.bookId << endl;
            cout << "Book Type: " << x.bookType << endl;
            cout << endl;
            i++;
        }
    }

    void addSubscription(int type) {
        Subscription sub = Subscription(type);
        subscriptions.push_back(sub);
        cout << "Subscription added" << endl;
    }

    void showAllSubscriptions() {
        int i = 1;
        for (auto x : subscriptions) {
            cout << x.type << endl;
            i++;
        }
        cout << endl;
    }

    void removeSubscription(int type) {
        bool removed = false;
        for (auto x : subscriptions) {
            if (x.type_int == type) {
                remove(subscriptions.begin(), subscriptions.end(), x);
                removed = true;
                break;
            }
        }
        if (removed) {
            cout << "Subscription removed" << endl;
        } else {
            cout << "Subscription not found" << endl;
        }
    }
};
