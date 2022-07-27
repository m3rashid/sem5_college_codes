#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b) {
    return a + b;
}

template <class T>
T diff(T a, T b) {
    return a - b;
}

template <class T>
T mul(T a, T b) {
    return a * b;
}

template <class T>
T div(T a, T b) {
    if (b == 0) {
        cout << "Cannot divide by zero" << endl;
        return a;
    }
    return a / b;
}

template <class T>
void handleOperation(T a, T b, char op) {
    switch (op) {
        case '+':
            cout << "Sum of the numbers: " << sum<T>(a, b) << endl;
            break;
        case '-':
            cout << "Difference of the numbers: " << diff<T>(a, b) << endl;
            break;
        case '*':
            cout << "Product of the numbers: " << mul<T>(a, b) << endl;
            break;
        default:
            cout << "Quotient of the numbers: " << div<T>(a, b) << endl;
            break;
    }
}
