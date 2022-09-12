#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>

#pragma once
#include "swap.h"
using namespace std;

class Student {
   public:
    int id;
    string name;
    int marks;
    int money;
    bool is_broke;
    bool deleted;

    Student() {
        this->deleted = false;
    }

    void deleteStudent() {
        this->deleted = true;
    }

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
        if (this->deleted) {
            cout << "Student no more exists in the school" << endl;
            return;
        }
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
            if (school[i].deleted) continue;

            string broke = school[i].is_broke ? "broke" : "rich";
            cout << "| -  " << school[i].id << " - |        " << school[i].name << "        |    " << school[i].marks << "     |     " << school[i].money << "     |  " << broke << "     |" << endl;
            cout << "| ------ | -------------------- | --------- | --------- | ---------- |" << endl;
        }
    }

    void sortByID(Student school[], int student_count) {
        for (int i = 0; i < student_count - 1; i++) {
            for (int j = 0; j < student_count - i - 1; j++) {
                if (school[j].id > school[j + 1].id) {
                    swap_student(school, j, j + 1);
                }
            }
        }
    }

    void sortByName(Student school[], int student_count) {
        for (int i = 0; i < student_count - 1; i++) {
            for (int j = 0; j < student_count - i - 1; j++) {
                if (school[j].name > school[j + 1].name) {
                    swap_student(school, j, j + 1);
                }
            }
        }
    }

    void sortByMoney(Student school[], int student_count) {
        for (int i = 0; i < student_count - 1; i++) {
            for (int j = 0; j < student_count - i - 1; j++) {
                if (school[j].money > school[j + 1].money) {
                    swap_student(school, j, j + 1);
                }
            }
        }
    }

    Student searchByID(Student school[], int student_count, int id) {
        Student st;
        bool found = false;
        for (int i = 0; i < student_count; i++) {
            if (school[i].id == id) {
                st = school[i];
                found = true;
            }
        }
        if (!found) {
            st.deleted = true;
        }
        return st;
    }

    Student searchByName(Student school[], int student_count, string name) {
        Student st;
        bool found = false;
        for (int i = 0; i < student_count; i++) {
            if (school[i].name == name) {
                st = school[i];
                found = true;
            }
        }
        if (!found) {
            st.deleted = true;
        }
        return st;
    }

    void sortAndDisplay(Student school[], int student_count) {
        int criteria;
        cout << "===== Criteria =====" << endl;
        cout << "\t1\t\tID\n\t2\t\tName\n\t3\t\tMoney" << endl;
        cout << "Enter sort criteria: ";
        cin >> criteria;

        if (criteria == 1) {
            sortByID(school, student_count);
        } else if (criteria == 2) {
            sortByName(school, student_count);
        } else if (criteria == 3) {
            sortByMoney(school, student_count);
        } else {
            cout << "Invalid Criteria" << endl;
            return;
        }
        this->showAll(school, student_count);
    }

    void searchStudent(Student school[], int student_count) {
        int criteria;
        cout << "===== Criteria =====" << endl;
        cout << "\t1\t\tID\n\t2\t\tName" << endl;
        cout << "Enter sort criteria: ";
        cin >> criteria;

        Student st;

        if (criteria == 1) {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            st = searchByID(school, student_count, id);
        } else if (criteria == 2) {
            string name;
            cout << "Enter Student Name: ";
            cin >> name;
            st = searchByName(school, student_count, name);
        } else {
            cout << "Invalid Criteria" << endl;
            return;
        }

        if (st.deleted) {
            cout << "Student not found in the school" << endl;
            return;
        }
        st.showData();
    }

    void findRichest(Student school[], int student_count) {
        sortByMoney(school, student_count);
        school[student_count - 1].showData();
    }

    void updateStudent(Student school[], int student_count) {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        Student st = searchByID(school, student_count, id);
        if (st.deleted) {
            cout << "Student not found in the school" << endl;
            return;
        }
        st.deleteStudent();

        Student st2;
        st2.getData(school, &student_count);
    }
};

#endif