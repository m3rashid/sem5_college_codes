// #include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Observe {
   public:
    int lowest_num = -1, max_number = 20;
    int processors, tasks;
    vector<vector<int>> adj_matrix;
    vector<vector<int>> pxt_matrix;

    Observe() {
        cout << "Enter number of tasks: ";
        cin >> tasks;
        cout << "Enter number of procesors: ";
        cin >> processors;
        adj_matrix.resize(tasks, vector<int>(tasks, -1));
        pxt_matrix.resize(processors, vector<int>(tasks, -1));
    }

    ~Observe() {
        adj_matrix.clear();
    }

    void take_pxt_matrix_input() {
        cout << "========== Enter PXT matrix values ==========" << endl;

        for (int i = 0; i < processors; i++) {
            cout << "Enter " << i + 1 << (i == 0 ? "st" : i == 1 ? "nd"
                                                      : i == 2   ? "rd"
                                                                 : "th")
                 << " row: (" << (tasks) << ") nums: ";
            for (int j = 0; j < tasks; j++) cin >> pxt_matrix[i][j];
        }
    }

    void print_pxt_matrix() {
        cout << endl;
        for (int i = 0; i < processors; i++) {
            for (int j = 0; j < tasks; j++) {
                cout << pxt_matrix[i][j] << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void make_adj_matrix() {
        srand(time(0));
        for (int i = 0; i < tasks; i++) {
            for (int j = i + 1; j < tasks; j++) {
                adj_matrix[i][j] = (rand() % max_number) + lowest_num;
            }
        }
    }

    void print_adj_matrix() {
        cout << endl;
        for (int i = 0; i < tasks; i++) {
            int j = 0;
            for (; j < i + 1; j++) cout << "-1  ";
            for (; j < tasks; j++) cout << adj_matrix[i][j] << "   ";
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    Observe graph = Observe();

    graph.make_adj_matrix();
    graph.take_pxt_matrix_input();

    graph.print_adj_matrix();
    graph.print_pxt_matrix();

    return 0;
}
