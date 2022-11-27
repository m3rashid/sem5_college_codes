#include <bits/stdc++.h>
using namespace std;

class Base {
    string name;
    string address;

   public:
    Base(string name, string address) {
        this->name = name;
        this->address = address;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public Base {
    float percentageMarks;

   public:
    Student(string name, string address, float percentageMarks) : Base(name, address) {
        this->percentageMarks = percentageMarks;
    }

    void print() {
        Base::print();
        cout << "Percentage Marks: " << percentageMarks << endl;
    }
};

class Staff : public Base {
    float salary;

   public:
    Staff(string name, string address, float salary) : Base(name, address) {
        this->salary = salary;
    }

    void print() {
        Base::print();
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    string name;
    string address;
    float percentageMarks;
    float salary;

    cout << "Enter details of student" << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter percentage marks: ";
    cin >> percentageMarks;
    Student s(name, address, percentageMarks);

    cout << endl;
    cout << "Enter details of staff" << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter salary: ";
    cin >> salary;
    Staff st(name, address, salary);

    cout << endl;
    cout << "Details of student" << endl;
    s.print();
    cout << endl;
    cout << "Details of staff" << endl;
    st.print();

    return 0;
}