#include "item.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;

//default constructor
Item::Item() {
    hasBlood = false;
    bloodType = "N/A";
    hasFingerPrint = false;
    whoseFingerprint = "N/A";
    itemLocation = "N/A";
    itemDescription = "N/A";
    itemFound = false;
}

//initialize Item object
Item::Item(const string& name, bool hasBlood, const string& bloodType,  bool fingerPrint, const string& whoseFingerprint, const string& itemLocation, const string& itemDescrip, bool itemFound, int clueID) 
    : hasBlood(hasBlood), 
      bloodType(bloodType),
      hasFingerPrint(fingerPrint), 
      whoseFingerprint(whoseFingerprint),
      itemLocation(itemLocation), 
      itemDescription(itemDescrip),
      itemFound(itemFound)
      {
    this->name = name;
    this->ClueID = clueID;
      }

Item::~Item() {
    // All members are std::string or bool — no manual cleanup needed
}

//checks if the item has been found yet
bool Item::isItemFound() const {return this->itemFound;}

void Item::print() const {
    cout << "Item name: " << this->name << endl;
    if(this->hasBlood == true) cout << "The item has blood on it." << endl;
    if(this->bloodType != "N/A") cout << "Blood type found on the item: " << this->bloodType << "." << endl;
    if(this->hasFingerPrint == true) {
        cout << "The fingerprint that's found on the ";
        cout << this->name << " belongs to " << this->whoseFingerprint << "." << endl;
    }
    if(this->itemLocation != "N/A") {
        cout << "Location where " << this->name << " has been found: ";
        cout << this->itemLocation << "." << endl; 
    }
    cout << "Item description: " << this->itemDescription << "." << endl;
}