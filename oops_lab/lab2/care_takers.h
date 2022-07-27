#include <bits/stdc++.h>
using namespace std;

class CareTaker {
   public:
    int empId;
    string name;
    string designation;

    CareTaker(int empId, string name, string designation) {
        this->empId = empId;
        this->name = name;
        this->designation = designation;
    };
};

class CareTakerMgmt {
   public:
    vector<CareTaker> careTakers;

    CareTakerMgmt() {}

    void addCareTaker(int empId, string name, string designation) {
        CareTaker careTaker = CareTaker(empId, name, designation);
        careTakers.push_back(careTaker);
        cout << "CareTaker Added" << endl;
    }

    void removeCareTaker(int empId) {
        bool removed = false;
        for (auto x : careTakers) {
            if (x.empId == empId) {
                remove(careTakers.begin(), careTakers.end(), x);
                removed = true;
                break;
            }
        }
        if (removed) {
            cout << "CareTaker Removed" << endl;
        } else {
            cout << "CareTaker not found" << endl;
        }
    }

    void showAllCareTakers() {
        int i = 1;
        for (auto x : careTakers) {
            cout << "=== Details for CareTaker " << i << " ===" << endl;
            cout << "Employee Id: " << x.empId << endl;
            cout << "Name: " << x.name << endl;
            cout << "Designation: " << x.designation << endl;
            cout << endl;
            i++;
        }
    }
};