
#include <bits/stdc++.h>

#include "calender.h"
#include "date.h"
using namespace std;

int main() {
    Calender calender;

    Date d1 = Date(27, 9, 2022);
    Date d2 = Date(31, 10, 2022);
    Date d3 = Date(10, 11, 2022);
    Date d4 = Date(21, 12, 2022);

    cout << calender.daysBetween(d1, d2) << endl;

    return 0;
}
