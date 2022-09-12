#include <iostream>
using namespace std;

class Student {
   public:
    int id;
    string name;
    int marks;
    int money;
    bool is_broke;

    void getData(Student school[], int *student_count) {
        cout << endl;
        cout << "========== Enter student details ==========" << endl;
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

        int count = *student_count;
        school[count] = *this;
        *student_count += 1;
    }

    void showData() {
        cout << endl;
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

    void showAll(Student school[], int student_count) {
        cout << endl;
        cout << "| ------ | -------------------- | --------- | --------- | ---------- |" << endl;
        cout << "| - ID - | ------ NAME -------- | - MARKS - | - MONEY - | - STATUS - |" << endl;
        cout << "| ------ | -------------------- | --------- | --------- | ---------- |" << endl;
        for (int i = 0; i < student_count; i++) {
            string broke = school[i].is_broke ? "broke" : "rich";
            cout << "| -  " << school[i].id << " - |        " << school[i].name << "        |    " << school[i].marks << "     |     " << school[i].money << "     |  " << broke << "     |" << endl;
            cout << "| ------ | -------------------- | --------- | --------- | ---------- |" << endl;
        }
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    int max_students;
    cout << "Enter max number of students: ";
    cin >> max_students;

    Student school[max_students];
    int student_count = 0;
    while (max_students--) {
        Student st;
        st.getData(school, &student_count);
    }

    Student st;
    st.showAll(school, student_count);

    return 0;
}
