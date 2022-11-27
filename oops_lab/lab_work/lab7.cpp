#include <iostream>
#define USD_TO_INR 80
using namespace std;

class Dollar;

class Rupee {
    double value;

   public:
    Rupee(double v = 0) {
        value = v;
    }

    Rupee(Dollar &d);

    double getValue() const { return value; }
};

class Dollar {
    double value;

   public:
    Dollar(double v = 0) {
        value = v;
    }

    Dollar(Rupee &r);

    double getValue() const { return value; }
};

// rupee to dollar constructor
Rupee::Rupee(Dollar &d) {
    value = d.getValue() * USD_TO_INR;
}

// dollar to rupee constructor
Dollar::Dollar(Rupee &r) {
    value = r.getValue() / USD_TO_INR;
}

int main() {
    double rupeeValue;
    cout << "Enter the value in Rupees: ";
    cin >> rupeeValue;
    Rupee r1(rupeeValue);
    Dollar d1 = r1;
    cout << "The value in Dollars is: " << d1.getValue() << endl;

    cout << endl;
    double dollarValue;
    cout << "Enter the value in Dollars: ";
    cin >> dollarValue;
    Dollar d2(dollarValue);
    Rupee r2 = d2;
    cout << "The value in Rupees is: " << r2.getValue() << endl;
    return 0;
}