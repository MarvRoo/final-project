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
    string itemDescription; //added this
    bool isFound; //added this to check item has been found


public:
    Item();
    Item(int clueID, const string& name, bool hasBlood, bool fingerPrint, const string& bloodType, bool inspected, const string& itemLocation, const string& itemDescrip, bool itemFound);

    //void SetItemDescript(const string& desc);
    bool itemFound(bool found);
};

#endif
