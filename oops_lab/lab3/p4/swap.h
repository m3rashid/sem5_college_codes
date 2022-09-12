#ifndef SWAP_H_
#define SWAP_H_

#include <iostream>

#include "student.h"
using namespace std;

void swap_student(Student school[], int i, int j) {
    Student temp = school[i];
    school[i] = school[j];
    school[j] = temp;
}

#endif