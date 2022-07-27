#include <bits/stdc++.h>
using namespace std;

string transpose(vector<vector<char>> mat, int rows, int cols) {
    string str = "";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) str += mat[j][i];
    }
    return str;
}

void encrypt(string text, int rows, int cols) {
    vector<vector<char>> mat(rows, vector<char>(cols, 'x'));
    int n = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (n + j < text.length()) mat[i][j] = text[j + n];
        }
        n = n + cols;
    }

    string encrypted = transpose(mat, rows, cols);
    cout << encrypted << endl;
}

void decrypt(string text, int rows, int cols) {
    vector<vector<char>> mat(cols, vector<char>(rows, ' '));
    int n = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (n + j < text.length()) mat[i][j] = text[j + n];
        }
        n = n + rows;
    }

    string decrypted = transpose(mat, cols, rows);
    int trail = decrypted.length() - 1;
    while (decrypted[trail] == 'x') trail--;

    decrypted = decrypted.substr(0, trail + 1);
    cout << decrypted << endl;
}

int main() {
    int key, rows, cols, choice;
    string text;

    cout << "20BCS033 MD Rashid Hussain" << endl;
    cout << "Enter key: ";
    cin >> key;
    cin.get();

    do {
        cout << "\n1. Encrypt\t2. Decrypt\t3. Change Key\t4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter plain text: ";
                cin.ignore();
                getline(cin, text);
                rows = ceil(text.length() / (float)key);
                cols = key;
                encrypt(text, rows, cols);
                break;
            case 2:
                cout << "Enter plain text: ";
                cin.ignore();
                getline(cin, text);
                rows = ceil(text.length() / (float)key);
                cols = key;
                decrypt(text, rows, cols);
                break;
            case 3:
                cout << "Enter new key: ";
                cin >> key;
                cout << "Key changed to " << key << endl;
                break;
            case 4:
                cout << "Exiting the program ..." << endl;
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    } while (true);

    return 0;
}
