#ifndef _CALENDER_
#define _CALENDER_

#include <bits/stdc++.h>

#pragma once
#include "statics.h"
using namespace std;

class Calender {
   private:
    int year;
    int month;
    int day;
    int week;

   public:
    Calender() {
        year = 0;
        month = 0;
        week = 0;
        day = 0;
    }

    // calculate the number of days in a month
    int daysInMonth(int month, int year) {
        if (month == 2) {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                return 29;
            } else {
                return 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    // calculate the number of days in a year
    int daysInYear(int year) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            return 366;
        } else {
            return 365;
        }
    }

    // calculate the number of days between two dates
    int daysBetween(Date d1, Date d2) {
        int day1 = d1.getDay(), day2 = d2.getDay();
        int month1 = d1.getMonth(), month2 = d2.getMonth();
        int year1 = d1.getYear(), year2 = d2.getYear();

        int days = 0;
        if (year1 == year2) {
            if (month1 == month2) {
                days = day2 - day1;
            } else {
                for (int i = month1; i < month2; i++) {
                    days += daysInMonth(i, year1);
                }
                days = days - day1 + day2;
            }
        } else {
            for (int i = year1; i < year2; i++) {
                days += daysInYear(i);
            }
            for (int i = month1; i <= 12; i++) {
                days -= daysInMonth(i, year1);
            }
            days += day1;
            for (int i = 1; i < month2; i++) {
                days += daysInMonth(i, year2);
            }
            days += day2;
        }
        return days;
    }
};

#endif
