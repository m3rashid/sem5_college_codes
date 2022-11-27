#include <iostream>
using namespace std;

class Student {
   public:
    string name;
    int enrollId;
    int marks;

    void getData() {
        cout << "Enter enrollId: ";
        cin >> this->enrollId;
        cout << "Enter name: ";
        cin >> this->name;
        cout << "Enter marks: ";
        cin >> this->marks;
    }

    void display() {
        cout << this->name << " (" << this->enrollId << ") "
             << "got " << this->marks << " marks" << endl;
    }
};

int main() {
    Student students[3];

    for (int i = 0; i < 3; i++) {
        students[i] = Student();
        cout << "\nEnter details for student" << i + 1 << endl;
        students[i].getData();
    }

    for (int i = 0; i < 3; i++) {
        students[i].display();
    }

    return 0;
}
