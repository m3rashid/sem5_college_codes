#include <bits/stdc++.h>
using namespace std;

class Pattern {
   public:
    int n;

    void takeInput();
    int* addressOfN() { return &this->n; }

    int addressOfN(bool addr) {
        if (addr) return -1;
        return this->n;
    }

    void print(int n = 0, char ch = '*') {
        if (n <= 0) n = this->n;
        if (n <= 0) {
            cout << "Invalid n :(\nExiting the program...." << endl;
            return;
        }

        int mid = n - 1;
        for (int i = 0; i < (2 * n) - 1; i++) {
            int j = 0;
            for (j = 0; j < abs(mid - i); j++) cout << "  ";
            cout << ch << " ";
            if (i < n) {
                for (j = 0; j < (2 * i) - 1; j++) cout << "  ";
                if (j == ((2 * i) - 1)) cout << ch << " ";
            } else {
                for (j = 0; j < (2 * ((2 * mid) - i)) - 1; j++) cout << "  ";
                if (j == (2 * ((2 * mid) - i)) - 1) cout << ch;
            }

            cout << endl;
        }
    }
};

inline void Pattern::takeInput() {
    cout << "Enter n: ";
    cin >> this->n;
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    Pattern pattern = Pattern();
    pattern.takeInput();
    pattern.print();
    cout << pattern.addressOfN() << endl;
    cout << "The value of n: " << pattern.addressOfN(false) << endl;

    return 0;
}
