#include "Item.h"

//default constructor
Item::Item() {
    hasBlood = false;
    hasFingerPrint = false;
    bloodType = "";
    itemLocation = "";
    itemDescription = "";
    isFound = false;
}

//initialize Item object
Item::Item(int clueID, const string& name, bool hasBlood, const string& bloodType, bool inspected, const string& itemLocation, const string& itemDescrip, bool itemFound); 
    : ClueID(clueID), 
      name(name), 
      hasBlood(hasBlood), 
      hasFingerPrint(fingerPrint), 
      bloodType(bloodType), 
      inspected(inspected), 
      itemLocation(itemLocation), 
      itemDescription(itemDescrip),
      isFound(itemFound)  {}

//checks if the item has been found yet
bool Item::itemFound(bool found) {
    return isFound;
}