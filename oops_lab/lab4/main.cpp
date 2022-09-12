#include <bits/stdc++.h>
using namespace std;

struct Book {
    int id;
    string name;
    string author;
    int cost;
    int quantity;
};

struct Magazine {
    int id;
    string name;
    string pub_month;
    int quantity;
};

struct Employee {
    int id;
    string name;
    string designation;
    int salary;
};

class Formatter {
   public:
    void addSpaces(int max_size, int current_size) {
        for (int i = -2; i < (max_size - current_size); i++) {
            cout << " ";
        }
    }

    void printBooks(vector<Book> books) {
        int max_name = 0, max_author = 0;

        for (auto x : books) {
            max_name = max(max_name, (int)x.name.size());
            max_author = max(max_author, (int)x.author.size());
        }

        for (auto x : books) {
            cout << x.id << "\t";
            cout << x.name;
            addSpaces(max_name, (int)x.name.size());
            cout << x.author;
            addSpaces(max_author, (int)x.author.size());
            cout << x.cost << "\t" << x.quantity << endl;
        }
    }

    void printMagazines(vector<Magazine> magazines) {
        int max_name = 0, max_pub_month = 0;

        for (auto x : magazines) {
            max_name = max(max_name, (int)x.name.size());
            max_pub_month = max(max_pub_month, (int)x.pub_month.size());
        }

        for (auto x : magazines) {
            cout << x.id << "\t";
            cout << x.name;
            addSpaces(max_name, (int)x.name.size());
            cout << x.pub_month;
            addSpaces(max_pub_month, (int)x.pub_month.size());
            cout << x.quantity << endl;
        }
    }

    void printEmployees(vector<Employee> employees) {
        int max_name = 0, max_designation = 0;

        for (auto x : employees) {
            max_name = max(max_name, (int)x.name.size());
            max_designation = max(max_designation, (int)x.designation.size());
        }

        for (auto x : employees) {
            cout << x.id << "\t";
            cout << x.name;
            addSpaces(max_name, (int)x.name.size());
            cout << x.designation;
            addSpaces(max_designation, (int)x.designation.size());
            cout << x.salary << endl;
        }
    }
};

class Library {
   private:
    vector<Book> books;
    vector<Magazine> magazines;
    vector<Employee> employees;

   public:
    int getAssetCount() {
        return (this->books.size() + this->magazines.size());
    }

    int getEmployeeCount() {
        return this->employees.size();
    }

    vector<Book> getAllBooks() {
        return this->books;
    }

    vector<Magazine> getAllMagazine() {
        return this->magazines;
    }

    vector<Employee> getAllEmployees() {
        return this->employees;
    }

    void addBook() {
        Book book;
        cout << "\n========== Enter book details ==========" << endl;
        cout << "ID: ";
        cin >> book.id;
        for (auto x : this->books) {
            if (x.id == book.id) {
                cout << "ID conflict occured, enter other id" << endl;
                cout << "ID: ";
                cin >> book.id;
                break;
            }
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, book.name, '\n');
        cout << "Author: ";
        getline(cin, book.author, '\n');
        cout << "Cost: ";
        cin >> book.cost;
        cout << "Quantity: ";
        cin >> book.quantity;
        this->books.push_back(book);
        cout << "Added successfully" << endl;
    }

    void addMagazine() {
        Magazine magazine;
        cout << "\n========== Enter magazine details ==========" << endl;
        cout << "ID: ";
        cin >> magazine.id;
        for (auto x : this->magazines) {
            if (x.id == magazine.id) {
                cout << "ID conflict occured, enter other id" << endl;
                cout << "ID: ";
                cin >> magazine.id;
                break;
            }
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, magazine.name, '\n');
        cout << "Publication month: ";
        getline(cin, magazine.pub_month, '\n');
        cout << "Quantity: ";
        cin >> magazine.quantity;
        this->magazines.push_back(magazine);
        cout << "Added successfully" << endl;
    }

    void addEmployee() {
        Employee employee;
        cout << "\n========== Enter employee details ==========" << endl;
        cout << "ID: ";
        cin >> employee.id;
        for (auto x : this->employees) {
            if (x.id == employee.id) {
                cout << "ID conflict occured, enter other id" << endl;
                cout << "ID: ";
                cin >> employee.id;
                break;
            }
        }
        cout << "Name: ";
        cin.ignore();
        getline(cin, employee.name, '\n');
        cout << "Designation: ";
        getline(cin, employee.designation, '\n');
        cout << "Salary: ";
        cin >> employee.salary;
        this->employees.push_back(employee);
        cout << "Added successfully" << endl;
    }

    void updateBook(int id) {
        for (auto x : this->books) {
            if (id == x.id) {
                cout << "\n========== Enter book details ==========" << endl;
                cout << "Enter . to skip an update entry" << endl;
                string name = "", author = "", cost = "-1", quantity = "-1";
                cout << "Name: ";
                getline(cin, name, '.');
                if (name != "") x.name = name;
                cout << "Author: ";
                getline(cin, author, '.');
                if (author != "") x.author = author;
                cout << "Cost: ";
                getline(cin, cost, '.');
                if (stoi(cost) != -1) x.cost = stoi(cost);
                cout << "Quantity: ";
                getline(cin, quantity, '.');
                if (stoi(quantity) != -1) x.quantity = stoi(quantity);
                cout << "Updated Successfully" << endl;
                return;
            }
        }
        cout << "The book with given ID could not be found" << endl;
    }

    void updateMagazine(int id) {
        for (auto x : this->magazines) {
            if (id == x.id) {
                cout << "\n========== Enter magazine details ==========" << endl;
                cout << "Enter . to skip an update entry" << endl;
                string name = "", pub_month = "", quantity = "-1";
                cout << "Name: ";
                getline(cin, name, '.');
                if (name != "") x.name = name;
                cout << "Publication month: ";
                getline(cin, pub_month, '.');
                if (pub_month != "") x.pub_month = pub_month;
                cout << "Quantity: ";
                getline(cin, quantity, '.');
                if (stoi(quantity) != -1) x.quantity = stoi(quantity);
                cout << "Updated Successfully" << endl;
                return;
            }
        }
        cout << "The magazine with given ID could not be found" << endl;
    }

    void updateEmployee(int id) {
        for (auto x : this->employees) {
            if (id == x.id) {
                cout << "\n========== Enter magazine details ==========" << endl;
                cout << "Enter . to skip an update entry" << endl;
                string name = "", designation = "", salary = "-1";
                cout << "Name: ";
                getline(cin, name, '.');
                if (name != "") x.name = name;
                cout << "Designation: ";
                getline(cin, designation, '.');
                if (designation != "") x.designation = designation;
                cout << "Quantity: ";
                getline(cin, salary, '.');
                if (stoi(salary) != -1) x.salary = stoi(salary);
                cout << "Updated Successfully" << endl;
                return;
            }
        }
        cout << "The magazine with given ID could not be found" << endl;
    }

    void deleteBook(int id) {
        const int n = this->books.size();
        for (auto x : this->books) {
            if (x.id == id) {
                swap(x, this->books[n - 1]);
                this->books.pop_back();
                cout << "Deleted Successfully" << endl;
                return;
            }
        }
        cout << "The book with given ID could not be found" << endl;
    }

    void deleteMagazine(int id) {
        const int n = this->magazines.size();
        for (auto x : this->magazines) {
            if (x.id == id) {
                swap(x, this->magazines[n - 1]);
                this->magazines.pop_back();
                cout << "Deleted Successfully" << endl;
                return;
            }
        }
        cout << "The magazine with given ID could not be found" << endl;
    }

    void deleteEmployee(int id) {
        const int n = this->employees.size();
        for (auto x : this->employees) {
            if (x.id == id) {
                swap(x, this->employees[n - 1]);
                this->employees.pop_back();
                cout << "Deleted Successfully" << endl;
                return;
            }
        }
        cout << "The employee with given ID could not be found" << endl;
    }

    void printMenu() {
        cout << "Enter 1 to add a book" << endl;
        cout << "Enter 2 to add a magazine" << endl;
        cout << "Enter 3 to add an employee" << endl;

        cout << "Enter 4 to update a book" << endl;
        cout << "Enter 5 to update a magazine" << endl;
        cout << "Enter 6 to update an employee" << endl;

        cout << "Enter 7 to delete a book" << endl;
        cout << "Enter 8 to delete a magazine" << endl;
        cout << "Enter 9 to delete an employee" << endl;

        cout << "Enter 10 to get all books" << endl;
        cout << "Enter 11 to get all magazines" << endl;
        cout << "Enter 12 to get all employees" << endl;

        cout << "Enter 13 to print this menu" << endl;
        cout << "Enter 14 to exit the program" << endl;
    }
};

int main() {
    auto library = Library();
    auto formatter = Formatter();

    int choice, id;
    cout << "20BCS033   MD Rashid Hussain" << endl;
    cout << endl;
    library.printMenu();
    while (true) {
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addMagazine();
                break;
            case 3:
                library.addMagazine();
                break;
            case 4:
                cout << "\nEnter ID: ";
                cin >> id;
                library.updateBook(id);
                break;
            case 5:
                cout << "\nEnter ID: ";
                cin >> id;
                library.updateMagazine(id);
                break;
            case 6:
                cout << "\nEnter ID: ";
                cin >> id;
                library.updateEmployee(id);
                break;
            case 7:
                cout << "\nEnter ID: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 8:
                cout << "\nEnter ID: ";
                cin >> id;
                library.deleteMagazine(id);
                break;
            case 9:
                cout << "\nEnter ID: ";
                cin >> id;
                library.deleteEmployee(id);
                break;
            case 10:
                formatter.printBooks(library.getAllBooks());
                break;
            case 11:
                formatter.printMagazines(library.getAllMagazine());
                break;
            case 12:
                formatter.printEmployees(library.getAllEmployees());
                break;
            case 13:
                cout << endl;
                library.printMenu();
                cout << endl;
                break;
            case 14:
                cout << "Exiting the program ..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice entered" << endl;
        }
    }

    return 0;
}
