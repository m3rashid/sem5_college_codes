#include <bits/stdc++.h>
using namespace std;

class Point {
   private:
    int x;
    int y;

   public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << '(' + to_string(this->x) + ", " + to_string(this->y) + ')' << endl;
    }

    void operator<<(int n) {
        this->x = this->x - n;
    }

    void operator>>(int n) {
        this->x = this->x + n;
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    Point p1 = Point(10, 20);
    p1.print();

    p1 << 5;
    p1.print();

    Point p2 = Point();
    p2.print();

    p2 >> 10;
    p2.print();

    return 0;
}
