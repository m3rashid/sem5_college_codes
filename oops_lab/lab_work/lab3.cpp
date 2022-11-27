#include <bits/stdc++.h>
using namespace std;

class Time {
   public:
    int hours;
    int minutes;

    Time(int hours, int minutes) {
        this->hours = hours;
        this->minutes = minutes;
    }
};

Time addTime(Time t1, Time t2) {
    int hours = t1.hours + t2.hours;
    int minutes = t1.minutes + t2.minutes;

    if (minutes >= 60) {
        hours++;
        minutes -= 60;
    }

    return Time(hours, minutes);
}

int main() {
    int h1, m1, h2, m2;

    cout << "Enter hours and minutes for time 1: ";
    cin >> h1 >> m1;
    cout << "Enter hours and minutes for time 2: ";
    cin >> h2 >> m2;

    Time t1(h1, m1);
    Time t2(h2, m2);

    Time t3 = addTime(t1, t2);

    cout << "Time 1: " << t1.hours << ":" << t1.minutes << endl;
    cout << "Time 2: " << t2.hours << ":" << t2.minutes << endl;
    cout << "Added Time: " << t3.hours << ":" << t3.minutes << endl;
}