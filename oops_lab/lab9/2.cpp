#include <bits/stdc++.h>
using namespace std;

#define RUPEE_RATE 80.0

class Rupee {
   private:
    double rupee;

   public:
    Rupee () { rupee = 0.0; }
    Rupee (double r) { rupee = r; }

    double value () { return rupee; }
    void takeInput () {
        cout << "Enter money (in rs): ";
        cin >> rupee;
    }
    void print () { cout << "Rupees: " << rupee << endl; }
};

class Dollar {
   public:
    double dollar;

   public:
    Dollar () { dollar = 0.0; }
    Dollar (double d) { dollar = d; }
    Dollar (Rupee r) { dollar = r.value() / RUPEE_RATE; }
    operator Rupee() { return Rupee(dollar * RUPEE_RATE); }

    double value () { return dollar; }
    void takeInput () {
        cout << "Enter money (in $): ";
        cin >> dollar;
    }
    void print () { cout << "Dollars: " << dollar << endl; }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    int choice;
    while (true) {
        cout << "Enter 0 to convert dollar to rupee" << endl;
        cout << "Enter 1 to convert rupee to dollar" << endl;
        cout << "Enter any other key to exit" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 0) {
            Dollar d1;
            d1.takeInput();
            Rupee r1;
            r1 = d1;
            r1.print();
        } else if (choice == 1) {
            Rupee r2;
            r2.takeInput();
            Dollar d2;
            d2 = r2;
            d2.print();
        } else break;
    }

    return 0;
}