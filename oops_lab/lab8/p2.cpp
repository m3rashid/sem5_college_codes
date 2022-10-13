#include <bits/stdc++.h>
using namespace std;

class Point {
   public:
    int x;
    int y;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void print() {
        cout << '(' + to_string(this->x) + ", " + to_string(this->y) + ')' << endl;
    }
};

class Points {
   private:
    Point points[10] = {};
    int size = 0;

   public:
    int getSize() { return this->size; }

    Point &operator[](int i) { return points[i]; }

    void addPoint(Point p) { points[size++] = p; }

    void removePoint(int index) {
        for (int i = index; i < size - 1; i++) points[i] = points[i + 1];
        size--;
    }

    void printAll() {
        for (int i = 0; i < size; i++) points[i].print();
        cout << endl;
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    Points points = Points();

    points.addPoint(Point(3, 1));
    points.addPoint(Point(3, 1));
    points.addPoint(Point(4, 3));
    points.addPoint(Point(5, 6));
    points.addPoint(Point(6, 7));

    points.printAll();

    if (points.getSize() > 0) {
        points[0].print();
    }

    return 0;
}
