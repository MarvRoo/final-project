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
Item::Item(int clueID, const string& name, bool hasBlood, const string& bloodType, bool inspected, const string& itemLocation) 
    : ClueID(clueID), 
      name(name), 
      hasBlood(hasBlood), 
      hasFingerPrint(fingerPrint), 
      bloodType(bloodType), 
      inspected(inspected), 
      itemLocation(itemLocation), 
      itemDescription(itemDescrip),
      isFound(itemFound)  {}

//set the item description
// void Item::SetItemDescript(const string& desc) {
//     itemDescription = desc;
// }

//checks if the item has been found yet
bool Item::itemFound(bool found) {
    return isFound;
}