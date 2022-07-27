#include <iostream>

#include "helpers.h"
using namespace std;

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    int flag;
    cout << "Enter type of data => (0 for int, 1 for float) and any other to exit" << endl;

    while (true) {
        cout << "Type: ";
        cin >> flag;
        if (flag != 0 && flag != 1) {
            cout << "Terminating program ..." << endl;
            break;
        }

        double a, b;
        if (flag == 0) {
            a = (int)a;
            b = (int)b;
        }
        cout << "Enter the numbers: ";
        cin >> a >> b;

        char op;
        cout << "Enter operation sign to perform operations and any other character to exit" << endl;
        while (true) {
            cout << "Operation ( +, -, *, / ): ";
            cin >> op;

            if (op != '+' && op != '-' && op != '*' && op != '/') {
                cout << "Invalid Operation" << endl;
                break;
            }
            if (flag == 0) {
                handleOperation<int>(a, b, op);
            } else {
                handleOperation<double>(a, b, op);
            }
        }
    }

    return 0;
}
