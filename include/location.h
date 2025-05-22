#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
using namespace std;
#include "Item.h"

class Location {
protected:
    string name;
    bool islocked;
    bool KeyItemFound;
    Item keyitem;

public:
    // Constructors
    Location();

    // SetRoom variants
    void SetRoom(const string& name, const string& description, const vector<Item>& items, const Item& keyItem);
    void SetRoom(const string& name, const string& description, const string& keyItemName);
    void SetRoom(const string& name, const string& description, bool locked, const Item& keyItem);

    // Other methods
    bool checkUnlock(bool KeyItemFound) const;
    void SetItems(const string& itemName);


};
#endif