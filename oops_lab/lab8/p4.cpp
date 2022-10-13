#include <bits/stdc++.h>
using namespace std;

class Point {
   private:
    int x, y;
    static int pointNum;

   public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << '(' + to_string(this->x) + ", " + to_string(this->y) + ')' << endl;
    }

    void* operator new(size_t size) {
        cout << "Overloading new operator with size: " << size << endl;
        void* p = ::operator new(size);
        return p;
    };

    void operator delete(void* p) {
        cout << "Overloading delete operator " << endl;
        free(p);
    };
};

int Point::pointNum = 0;

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    cout << "Creating two points p1 and p2" << endl;
    Point* p1 = new Point(1, 2);
    Point* p2 = new Point(3, 2);

    cout << "Deleting p1 and p2" << endl;
    delete (p1);
    delete (p2);

    return 0;
}
