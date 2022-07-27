#include <bits/stdc++.h>

#include "books.h"
#include "care_takers.h"
#include "inventory_static.h"
#include "library.h"
#include "subscriptions.h"
#include "users.h"
using namespace std;

void Menu() {
    cout << "Enter 0 to show this menu again" << endl;
    cout << "Enter 1 to add a book" << endl;
    cout << "Enter 2 to show all books" << endl;
    cout << "Enter 3 to remove a book" << endl;
    cout << "Enter 4 to issue book" << endl;
    cout << "Enter 5 to show issued books" << endl;

    cout << "Enter 6 to add subscription" << endl;
    cout << "Enter 7 to show active subscriptions" << endl;
    cout << "Enter 8 to remove a subscription" << endl;

    cout << "Enter 9 to add item to the inventory" << endl;
    cout << "Enter 10 to show all items in the inventory" << endl;
    cout << "Enter 11 to remove an item from the inventory" << endl;

    cout << "Enter 12 to add a care taker" << endl;
    cout << "Enter 13 to show all care takers" << endl;
    cout << "Enter 14 to remove a care taker" << endl;

    cout << "Enter -1 to vandalize the library" << endl;
}

int main() {
    // vars for books
    int bookId;
    int bookType;
    string name;
    string author;

    // vars for subscription
    int subscription_type;

    // vars for inventory
    int itemId;
    int type;
    int count;

    // for care takers
    int empId;
    string designation;

    // program start
    int choice;
    Library library = Library();
    Inventory inventory = Inventory();
    CareTakerMgmt careTakerMgmt = CareTakerMgmt();
    Menu();

    while (true) {
        switch (choice) {
            case 0:
                Menu();
                break;

            case 1:
                cout << "Enter bookId<int>, type<int>, name<string>, author<string> of the book" << endl;
                cin >> bookId >> bookType >> name >> author;
                library.addBook(bookId, bookType, name, author);
                break;

            case 2:
                library.showAllBooks();
                break;

            case 3:
                cout << "Enter bookId<int> of the book to be removed" << endl;
                cin >> bookId;
                library.removeBook(bookId);

            case 4:
                cout << "Enter bookId<int> of the book to be issued" << endl;
                cin >> bookId;
                library.issueBook(bookId);
                break;

            case 5:
                library.showIssuedBooks();
                break;

            case 6:
                cout << "Enter type<int> of subscription: ";
                cin >> subscription_type;
                library.addSubscription(subscription_type);
                break;

            case 7:
                library.showAllSubscriptions();
                break;

            case 8:
                cout << "Enter type<int> of subscription to be removed: ";
                cin >> subscription_type;
                library.removeSubscription(subscription_type);
                break;

            case 9:
                cout << "Enter itemId, type and count for the inventory item" << endl;
                cin >> itemId, type >> count;
                inventory.addItem(itemId, type, count);
                break;

            case 10:
                inventory.showInventory();
                break;

            case 11:
                cout << "Enter itemId of the item to be removed" << endl;
                cin >> itemId;
                inventory.removeItem(itemId);
                break;

            case 12:
                cout << "Enter employeeId, name and designation of the care taker" << endl;
                cin >> empId >> name >> designation;
                careTakerMgmt.addCareTaker(empId, name, designation);
                break;

            case 13:
                careTakerMgmt.showAllCareTakers();
                break;

            case 14:
                cout << "Enter employeeId of the care taker to be removed" << endl;
                cin >> empId;
                careTakerMgmt.removeCareTaker(empId);
                break;

            case -1:
                cout
                    << "Exiting the program"
                    << endl;
                exit(0);
                break;

            default:
                cout
                    << "Bad user input, enter 0 to show menu" << endl;
        }
    }

    return 0;
}
