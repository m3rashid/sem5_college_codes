#include <bits/stdc++.h>
using namespace std;

class Complex {
    int real;
    int img;

   public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }
    Complex operator+=(Complex c) {
        real += c.real;
        img += c.img;
        return *this;
    }

    Complex operator-=(Complex c) {
        real -= c.real;
        img -= c.img;
        return *this;
    }

    Complex operator*=(Complex c) {
        int r = real;
        real = real * c.real - img * c.img;
        img = r * c.img + img * c.real;
        return *this;
    }

    Complex operator/=(Complex c) {
        int r = real;
        real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
        img = (img * c.real - r * c.img) / (c.real * c.real + c.img * c.img);
        return *this;
    }

    friend ostream &operator<<(ostream &out, Complex &c);
};

ostream &operator<<(ostream &out, Complex &c) {
    out << c.real << " + " << c.img << "i";
    return out;
}

int main() {
    Complex c1(2, 3), c2(4, 5);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    c1 += c2;
    cout << endl
         << "c1 += c2 = " << c1 << endl;
    c1 -= c2;
    cout << endl
         << "c1 -= c2 = " << c1 << endl;
    c1 *= c2;
    cout << endl
         << "c1 *= c2 = " << c1 << endl;
    c1 /= c2;
    cout << endl
         << "c1 /= c2 = " << c1 << endl;
}