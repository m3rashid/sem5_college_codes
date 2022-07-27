#include <bits/stdc++.h>
using namespace std;

class Book {
   public:
    int bookId;
    string bookType;
    string name;
    string author;

    Book(int bookId, int type, string name = "", string author = "") {
        this->bookId = bookId;
        this->name = name;
        this->author = author;

        switch (type) {
            case 0:
                this->bookType = "Fiction";
                break;
            case 1:
                this->bookType = "Text Book (Non-Fiction)";
                break;
            case 2:
                this->bookType = "Non Course Book (Non-Fiction)";
                break;
            case 3:
                this->bookType = "Magazines";
                break;
            default:
                this->bookType = "Miscellaneous";
        }
    };
};
