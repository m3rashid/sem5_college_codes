#include <bits/stdc++.h>
using namespace std;

class NewString {
   private:
    string str;

   public:
    NewString() { str = ""; }
    NewString(string s) { str = s; }
    void print() { cout << str << endl; }
    operator string() { return str; }
};

int main() {
    string msg = "Rashid";
    NewString str = msg;

    str.print();

    NewString a("hello");
    string b;
    b = a;
    cout << b << endl;

    return 0;
}
