#include <bits/stdc++.h>

using namespace std;

int dict[26] = {};

void validate_key(int* key) {
    if (*key > 26) {
        *key = *key % 26;
    }

    while (*key < 0) {
        *key = *key + 26;
    }
}

string encrypt(string plain_text, int key) {
    for (int i = 0; i < plain_text.length(); i++) {
        int index = dict[plain_text[i] - 'a'];
        if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
            int value = (index + key) % 26;
            plain_text[i] = value + 'a';
        } else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            int value = (index + key) % 26;
            plain_text[i] = value + 'A';
        }
    }

    return plain_text;
}

string decrypt(string cypher_text, int key) {
    for (int i = 0; i < cypher_text.length(); i++) {
        int index = dict[cypher_text[i] - 'a'];
        if (cypher_text[i] >= 'a' && cypher_text[i] <= 'z') {
            int value = (index - key + 26) % 26;
            cypher_text[i] = value + 'a';
        } else if (cypher_text[i] >= 'A' && cypher_text[i] <= 'Z') {
            int value = (index - key + 26) % 26;
            cypher_text[i] = value + 'A';
        }
    }

    return cypher_text;
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    for (int i = 0; i < 26; i++) {
        dict[i] = i;
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;
    validate_key(&key);

    char op;
    string text;

    while (true) {
        cout << "Enter operation ==> e(encryption), d(decryption), c(change key), q(quit): ";
        cin >> op;

        switch (op) {
            case 'e':
                cout << "Enter your string: ";
                cin.ignore();
                getline(cin, text);
                cout << "========== Encrypted text ==========" << endl;
                cout << encrypt(text, key) << endl
                     << endl;
                break;

            case 'd':
                cout << "Enter your string: ";
                cin.ignore();
                getline(cin, text);
                cout << "========== Decrypted text ==========" << endl;
                cout << decrypt(text, key) << endl
                     << endl;
                break;

            case 'c':
                cout << "Enter the key: ";
                cin >> key;
                validate_key(&key);
                cout << "Key updated" << endl
                     << endl;
                break;

            case 'q':
                cout << "Exiting the program ... " << endl;
                exit(0);
                break;

            default:
                cout << "Invalid operation found" << endl;
        }
    }

    return 0;
}
