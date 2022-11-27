#include <bits/stdc++.h>
using namespace std;

class Base {
   public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
    virtual void pureVirtualFunc() = 0;
};

class Derived : public Base {
   public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    virtual ~Derived() {
        cout << "Derived destructor" << endl;
    }
    void pureVirtualFunc() override {
        cout << "Pure Virtual Function" << endl;
    }

    friend ostream &operator<<(ostream &os, const Derived &d);
};

ostream &operator<<(ostream &os, const Derived &d) {
    os << "Overloading through friend function" << endl;
    return os;
}

int main() {
    // // pure virtual function
    // Base *b1 = new Derived();
    // b1->pureVirtualFunc();

    // // pointer to derived class
    // Derived *d1 = new Derived();
    // d1->pureVirtualFunc();

    // // virtual destructor
    // Derived *d2 = new Derived();
    // Base *b2 = d2;
    // delete b2;

    // overloading through friend function
    Derived d3;
    cout << d3 << endl;
}