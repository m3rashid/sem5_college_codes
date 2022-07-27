#include <cmath>
#include <iostream>
#include <string>

#include "helpers.h"
using namespace std;

int main() {
    cout << "Enter two binary numbers: ";
    string a, b;
    cin >> a >> b;

    int da = binaryToDecimal(a);
    int db = binaryToDecimal(b);

    cout << "Sum of the numbers: " << decimalToBinary(da + db) << endl;

    return 0;
}
