#include <bits/stdc++.h>
using namespace std;

class InventoryItem {
   public:
    int itemId;
    string type;
    int count;

    InventoryItem(int itemId, int type, int count) {
        this->itemId = itemId;
        this->count = count;
        switch (type) {
            case 1:
                this->type = "Chair";
                break;
            case 2:
                this->type = "Table";
                break;
            case 3:
                this->type = "Paper Weight";
                break;
            default:
                this->type = "others";
        }
    };
};

class Inventory {
   public:
    vector<InventoryItem> inventory;

    Inventory() {}

    void addItem(int itemId, int type, int count) {
        InventoryItem inv = InventoryItem(itemId, type, count);
        inventory.push_back(inv);
        cout << "Added item to the inventory" << endl;
    }

    void showInventory() {
        int i = 1;
        for (auto x : inventory) {
            cout << "=== Details for Item " << i << " ===" << endl;
            cout << "Type: " << x.type << endl;
            cout << "Count: " << x.count << endl;
            cout << endl;
            i++;
        }
    }

    void removeItem(int itemId) {
        bool removed = false;
        for (auto x : inventory) {
            if (x.itemId == itemId) {
                remove(inventory.begin(), inventory.end(), x);
                removed = true;
                break;
            }
        }
        if (removed) {
            cout << "Item removed from the inventory" << endl;
        } else {
            cout << "Item not found" << endl;
        }
    }
};
