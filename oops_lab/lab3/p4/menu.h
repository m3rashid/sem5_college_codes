#ifndef MENU_H_
#define MENU_H_

#include <iostream>

#pragma once
#include "student.h"
using namespace std;

void print_menu() {
    cout << "========== Help Menu ==========" << endl;
    cout << "\t1\t\tAdd Student" << endl;
    cout << "\t2\t\tDisplay all students" << endl;
    cout << "\t3\t\tSort and Display all students" << endl;
    cout << "\t4\t\tSearch student" << endl;
    cout << "\t5\t\tUpdate student" << endl;
    cout << "\t6\t\tDelete student" << endl;
    cout << "\t7\t\tFind the richest" << endl;
    cout << "\t8\t\tExit the program" << endl;
    cout << "\t9\t\tPrint the help menu" << endl;
}

#endif