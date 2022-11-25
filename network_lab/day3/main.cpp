#include <bits/stdc++.h>
using namespace std;

string key[] = {
    "aaaaa",
    "aaaab",
    "aaaba",
    "aaabb",
    "aabaa",
    "aabab",
    "aabba",
    "aabbb",
    "abaaa",
    "abaab",
    "ababa",
    "ababb",
    "abbaa",
    "abbab",
    "abbbb",
    "baaaa",
    "baaab",
    "baaba",
    "baabb",
    "babaa",
    "babab",
    "babba",
    "babbb",
    "bbaaa",
    "bbaab",
    "bbaba",
};

string sanitize(string str) {
    string cleaned = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            cleaned += ((str[i] - 'A') + 'a');
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            cleaned += str[i];
        }
    }
    return cleaned;
}

string encrypt_baconian(string plain_text, string enc_text) {
    string res = "";
    string ret = "";
    for (int i = 0; i < plain_text.length(); i++) {
        res += key[(int)(plain_text[i] - 'a')];
    }

    for (int i = 0; i < res.length(); i++) {
        if (res[i] == 'b') {
            ret += enc_text[i] - 'a' + 'A';
        } else if (res[i] == 'a') {
            ret += enc_text[i];
        }
    }

    return ret;
};

string decrypt_baconian(string plain_text, string enc_text) {
    string res = "";
    return res;
};

string preserve_message(string cipher, string enc_text) {
    string str = "";
    for (int i = 0; i < enc_text.length(); i++) {
        if (enc_text[i] == ' ') {
            str[i] += enc_text[i];
        } else if (cipher[i] == '\0') {
            break;
        } else {
            str[i] += cipher[i];
        }
    }
    return str;
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;

    string plain_text = "t t", encryption_text = "this is a great class to have this";
    // cout << "Enter plain text: ";
    // getline(cin, plain_text);

    // cout << "Enter Encryption text: ";
    // getline(cin, encryption_text);

    string original_enc = encryption_text;
    string original_text = plain_text;

    plain_text = sanitize(plain_text);
    encryption_text = sanitize(encryption_text);

    if (encryption_text.length() < plain_text.length() * 5) {
        cout << "Invalid encrytion text entered" << endl;
        exit(0);
    }

    string encrypted = encrypt_baconian(plain_text, encryption_text);
    string decrypted = decrypt_baconian(plain_text, encryption_text);

    cout << "Plain text: " << plain_text << endl;
    cout << "Encryption text: " << encryption_text << endl;
    cout << "Cipher text: " << encrypted << endl;
    cout << "Preserved: " << preserve_message(encrypted, encryption_text) << endl;
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}