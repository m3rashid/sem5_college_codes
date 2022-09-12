#include <bits/stdc++.h>
using namespace std;

class MatrixMul {
    int m, n, p;
    vector<vector<int>> m1;
    vector<vector<int>> m2;
    vector<vector<int>> res;

   public:
    static int number_of_multiplications;

    static int incrementMulCount() {
        number_of_multiplications++;
        return number_of_multiplications;
    }

    string getSubs(int num) {
        return (num == 1) ? "1st" : (num == 2) ? "2nd"
                                : (num == 3)   ? "3rd"
                                               : to_string(num) + "th";
    }

    void takeInput() {
        cout << "========== Matrix Multiplication ==========" << endl;
        cout << "For (m X n) * (n X p) matrices" << endl;
        cout << "Enter m, n and p: ";
        cin >> m >> n >> p;

        m1.resize(m, vector<int>(n, 0));
        m2.resize(n, vector<int>(p, 0));
        res.resize(m, vector<int>(p, 0));

        cout << "Enter first matrix" << endl;
        for (int i = 1; i <= m; i++) {
            cout << "Enter " << getSubs(i) << " row elements: ";
            for (int j = 0; j < n; j++) {
                cin >> m1[i - 1][j];
            }
        }

        cout << endl
             << "Enter second matrix" << endl;
        for (int i = 1; i <= n; i++) {
            cout << "Enter " << getSubs(i) << " row elements: ";
            for (int j = 0; j < p; j++) {
                cin >> m2[i - 1][j];
            }
        }
    }

    void multiply() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][j] += (m1[i][k] * m2[k][j]);
                    incrementMulCount();
                }
            }
        }
    }

    void printResult() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                cout << res[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int MatrixMul::number_of_multiplications = 0;

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    auto m = MatrixMul();
    m.takeInput();
    m.multiply();
    m.printResult();

    cout << "Total number of multiplications: " << MatrixMul::number_of_multiplications << endl;

    return 0;
}
