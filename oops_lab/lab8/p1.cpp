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

    double calculateDistance(Point p) {
        return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
    }

    string operator&&(Point p) {
        if (this->x == p.x && this->y == p.y) return "true";
        return "false";
    }

    Point operator!() {
        return Point(-this->x, -this->y);
    }

    Point operator||(Point p) {
        return Point(this->x + p.x, this->y + p.y);
    }

    string print() {
        string res = '(' + to_string(this->x) + ", " + to_string(this->y) + ')';
        return res;
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    Point p1 = Point(1, 2);
    Point p2 = Point(3, 4);

    cout << "Point 1: " << p1.print() << endl;
    cout << "Point 2: " << p2.print() << endl;

    cout << "If p1 and p2 are equal: " << (p1 && p2) << endl;
    cout << "Distance between p1 and p2: " << p1.calculateDistance(p2) << " units" << endl;
    cout << "Negation of p1: " << (!p1).print() << endl;
    cout << "Add p1 and p2: " << (p1 || p2).print() << endl;

    return 0;
}
