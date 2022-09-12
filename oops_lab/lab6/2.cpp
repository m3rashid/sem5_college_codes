#include <bits/stdc++.h>
using namespace std;

class B {
   private:
    int x2, y2;

   public:
    B() {
        cout << "Enter x2: ";
        cin >> this->x2;
        cout << "Enter y2: ";
        cin >> this->y2;
    }

    friend class A;
};

class A {
   private:
    int x1, y1;

   public:
    A() {
        cout << "Enter x1: ";
        cin >> this->x1;
        cout << "Enter y1: ";
        cin >> this->y1;
    }

    double getDist(B);
};

double A::getDist(B b) {
    int xx = pow((this->x1 - b.x2), 2);
    int yy = pow((this->y1 - b.y2), 2);
    return sqrt(xx + yy);
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    A a = A();
    B b = B();
    cout << "Distance between A and B: " << a.getDist(b) << endl;

    return 0;
}
