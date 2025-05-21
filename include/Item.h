#ifndef ITEM_H
#define ITEM_H

#include "Clue.h"
#include <string>
using namespace std;

class Item : public Clue {
private:
    bool hasBlood;
    bool hasFingerPrint;
    string bloodType;
    string itemLocation;

public:
    Item();
    Item(const string& name, bool hasBlood, const string& bloodType, bool inspected, const string& itemLocation);

    void SetItem(const string& name, bool hasBlood, const string& bloodType, bool inspected, const string& itemLocation);
    void SetItemDescript(const string& desc);
    bool itemFound(bool found);
    bool beingInspected(bool Inspected);
};

#endif
