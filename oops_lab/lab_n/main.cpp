#include <string.h>

#include <iostream>
using namespace std;

class PackageDetails {
   public:
    string name;
    string address;
    string city;
    string state;
    int zip;
};

class Package {
    PackageDetails sender;
    PackageDetails receiver;

   protected:
    int weight;
    int cost_per_weight;

    PackageDetails take_input() {
        PackageDetails person;
        cout << "Name: ";
        getline(cin, person.name, '\n');
        cout << "Address: ";
        getline(cin, person.address, '\n');
        cout << "City: ";
        getline(cin, person.city, '\n');
        cout << "State: ";
        getline(cin, person.state, '\n');
        cout << "Zip: ";
        cin >> person.zip;

        return person;
    }

    int get_cost_per_weight(PackageDetails sender, PackageDetails receiver) {
        if (sender.zip == receiver.zip) return 5;
        if (sender.city == receiver.city) return 10;
        if (sender.state == receiver.state) return 20;
        return 50;
    }

   public:
    void get_data() {
        PackageDetails from, to;
        cout << endl
             << "========== Enter sender details ==========" << endl;
        this->sender = take_input();

        cin.ignore();
        cout << endl
             << "========== Enter receiver details ==========" << endl;
        this->receiver = take_input();

        do {
            cout << endl
                 << "Enter package weight: ";
            cin >> this->weight;
        } while (this->weight <= 0);

        this->cost_per_weight = get_cost_per_weight(this->sender, this->receiver);
    }

    Package() {
        this->weight = 0;
        this->cost_per_weight = 0;
    }

    int calculate_cost() {
        return (this->weight * this->cost_per_weight);
    }
};

class TwoDayPackage : public Package {
    int flat_fee;

   public:
    void set_fees(int fee) {
        this->flat_fee = fee;
    }

    TwoDayPackage(int fee = 50) {
        this->set_fees(fee);
    }

    int calculate_cost() {
        return ((this->weight * this->cost_per_weight) + this->flat_fee);
    }
};

class OvernightPackage : public Package {
    int overnight_fee;

   public:
    void set_fees(int fee) {
        this->overnight_fee = fee;
    }

    OvernightPackage(int fee = 20) {
        this->set_fees(fee);
    }

    int calculate_cost() {
        return (this->weight * (this->cost_per_weight + this->overnight_fee));
    }
};

void menu() {
    cout << endl
         << "========== MENU ==========" << endl;
    cout << "Enter 1 for Normal Package" << endl;
    cout << "Enter 2 for Two Day Package" << endl;
    cout << "Enter 3 for Overnight Package" << endl;
    cout << "Enter 4 for this menu" << endl;
    cout << "Enter 0 to exit" << endl;
    cout << "==============================" << endl
         << endl;
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    int choice;
    Package pack;
    TwoDayPackage td_pack;
    OvernightPackage ov_pack;

    menu();

    while (1) {
        cout << "Enter choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                pack.get_data();
                cout << "Cost for package: " << pack.calculate_cost() << endl;
                cout << endl;
                break;

            case 2:
                td_pack.get_data();
                td_pack.set_fees(25);
                cout << "Cost for two-day-package: " << td_pack.calculate_cost() << endl;
                cout << endl;
                break;

            case 3:
                ov_pack.get_data();
                ov_pack.set_fees(10);
                cout << "Cost for overnight-package: " << ov_pack.calculate_cost() << endl;
                cout << endl;
                break;

            case 4:
                menu();
                break;

            case 0:
                exit(0);
                break;

            default:
                cout << "Invalid choice entered" << endl;
        }
    }

    return 0;
}
