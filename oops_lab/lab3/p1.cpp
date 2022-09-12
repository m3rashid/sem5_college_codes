#include <iostream>
using namespace std;

class Student {
   public:
    int id;
    string name;
    int marks;
    int money;
    bool is_broke;

    void getData() {
        cout << "Enter student id: ";
        cin >> this->id;
        cout << "Enter name: ";
        cin >> this->name;
        cout << "Enter marks: ";
        cin >> this->marks;
        cout << "Enter money: ";
        cin >> this->money;
        if (this->money <= 0) {
            this->is_broke = true;
        } else {
            this->is_broke = false;
        }
    }

    void showData() {
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "Marks: " << this->marks << endl;
        cout << "Money: " << this->money << endl;
        if (this->money <= 0) {
            cout << this->name << " is broke" << endl;
        } else {
            cout << this->name << " is not broke" << endl;
        }
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    Student st;
    st.getData();
    st.showData();

    return 0;
}
