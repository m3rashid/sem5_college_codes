#include <bits/stdc++.h>
using namespace std;

class Account {
   private:
    int acc;
    float balance;

   public:
    Account() {
        cout << "Enter the account number:  ";
        cin >> acc;
        cout << "Enter balance: ";
        cin >> balance;
    }

    Account(int acc_number) {
        acc = acc_number;
        balance = 0.0;
    }

    Account(int acc_number, float amount) {
        acc = acc_number;
        balance = amount;
    }

    void print() {
        cout << "Your account number: " << acc << endl;
        cout << "Your balance: " << balance << endl;
        cout << endl;
    }

    void transfer(Account *a, int amount) {
        if (a->balance < amount) {
            cout << "You broke" << endl;
            return;
        }
        a->balance -= amount;
        this->balance += amount;
        cout << "Amount " << amount << " transfered from " << a->acc << " to " << this->acc << endl;
    }
};

int main() {
    Account acc1;
    Account acc2(5679);
    Account acc3(5670, 20000);

    acc1.print();
    acc2.print();
    acc3.print();

    acc1.transfer(&acc2, 200);

    acc1.print();
    acc2.print();

    return 0;
}

/**
 * Topics in the class
 *
 * Deconstructor
 * Nameless objects
 * Copy constructors
 * Dynamic Initialization through constructor
 * constructor with dynamic operation
 */