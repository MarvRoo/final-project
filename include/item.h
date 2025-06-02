#ifndef ITEM_H
#define ITEM_H

#include "clue.h"
#include <string>
using namespace std;

class Item : public Clue {
private:
    bool hasBlood;
    bool hasFingerPrint;
    string bloodType;
    string whoseFingerprint;
    string itemLocation;
    bool itemFound; 
    string itemDescription;



public:
    Item();
    Item(const string& name, bool hasBlood, const string& bloodType,  bool fingerPrint, 
        const string& whoseFingerprint, const string& itemLocation, const string& itemDescrip, 
        bool itemFound, int clueID);

    bool isItemFound();
    void print();
    Item(const Item&) = delete; //delete copy constructor
    Item& operator=(const Item&) = delete; //delete copy assignment operator
    ~Item() override;
};

#endif
