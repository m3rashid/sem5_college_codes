#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int binaryToDecimal(string bin) {
    int decimal = 0;
    int lastIntdex = bin.length() - 1;
    for (int i = lastIntdex; i >= 0; i--) {
        decimal += (bin[i] - '0') * pow(2, lastIntdex - i);
    }
    return decimal;
}

string decimalToBinary(int decimal) {
    string bin = "";
    while (decimal != 0) {
        bin.push_back(decimal % 2 + '0');
        decimal /= 2;
    }
    int j = bin.length() - 1;
    int i = 0;

    while (i < j) {
        swap(bin[i], bin[j]);
        i++;
        j--;
    }
    return bin;
}
