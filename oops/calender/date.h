#ifndef _DATE_
#define _DATE_

#include <bits/stdc++.h>

#pragma once
#include "statics.h"
using namespace std;

class Date {
   private:
    int year;
    int month;
    int day;
    int week;

   public:
    Date(int day, int month, int year) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->week = 0;
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    int getWeek() {
        return week;
    }

    // calculate the day of the week
    string dayOfWeek(Date date) {
        if (date.month == 1 || date.month == 2) {
            date.month += 12;
            date.year--;
        }
        int d = (date.day + 2 * date.month + 3 * (date.month + 1) / 5 + date.year + date.year / 4 - date.year / 100 + date.year / 400) % 7;
        return weekName[d];
    }
};

#endif
