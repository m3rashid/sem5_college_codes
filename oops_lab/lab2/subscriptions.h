#include <bits/stdc++.h>
using namespace std;

class Subscription {
   public:
    int type_int;
    string type;

    Subscription(int type) {
        this->type_int = type;
        switch (type) {
            case 1:
                this->type = "Newspaper";
                break;
            case 2:
                this->type = "Magazine";
                break;
            case 3:
                this->type = "Novel";
                break;
            default:
                this->type = "Other";
        }
    };
};