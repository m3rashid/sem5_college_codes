#include <bits/stdc++.h>
using namespace std;

class Media {
   public:
    string title;
    string publication;

    virtual void read();
    virtual void display();
};

class Book : public Media {
   public:
    int pages;

    void read() override;
    void display() override;
};

class Tape : public Media {
   public:
    int time;

    void read() override;
    void display() override;
};

void Media::read() {
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter publication: ";
    cin >> publication;
}

void Media::display() {
    cout << "Title: " << title << endl;
    cout << "Publication: " << publication << endl;
}

void Book::read() {
    Media::read();
    cout << "Enter pages: ";
    cin >> pages;
}

void Book::display() {
    Media::display();
    cout << "Pages: " << pages << endl;
}

void Tape::read() {
    Media::read();
    cout << "Enter time: ";
    cin >> time;
}

void Tape::display() {
    Media::display();
    cout << "Time: " << time << endl;
}

int main() {
    Media *book = new Book();
    Media *tape = new Tape();

    cout << endl
         << "Enter details of book" << endl;
    book->read();

    cout << endl
         << "Enter details of tape" << endl;
    tape->read();

    cout << endl
         << "Details of book" << endl;
    book->display();

    cout << endl
         << "Details of tape" << endl;
    tape->display();
}