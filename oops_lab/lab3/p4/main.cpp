#include <iostream>

#include "menu.h"
#include "student.h"
using namespace std;

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    int max_students;
    cout << "Enter max number of students: ";
    cin >> max_students;

    Student school[max_students];
    int student_count = 0;

    Student st;
    int choice;

    while (true) {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (student_count >= max_students) {
                    cout << "Cannot add student" << endl;
                } else {
                    st.getData(school, &student_count);
                }
                break;
            case 2:
                st.showAll(school, student_count);
                break;
            case 3:
                st.sortAndDisplay(school, student_count);
                break;
            case 4:
                st.searchStudent(school, student_count);
                break;
            case 5:
                st.updateStudent(school, student_count);
                break;
            case 6:
                st.deleteStudent();
                break;
            case 7:
                st.findRichest(school, student_count);
                break;
            case 8:
                cout << "Exiting the program" << endl;
                exit(0);
            case 9:
                print_menu();
                break;
            default:
                cout << "Invalid Entry, try again" << endl;
                cout << "Inputs can be one of" << endl;
                print_menu();
        }
    }

    return 0;
}
