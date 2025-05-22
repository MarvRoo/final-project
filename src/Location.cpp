#include "Location.h"
#include <string>
#include <vector>
#include "Item.h"
#include "Clue.h"
using namespace std;

// Constructors
Location::Location() : isLocked(false), keyItemFound(false), keyItem(nullptr) {}
Location::Location(const string& name, const string& description, bool locked, bool keyFound, Item* key)
    : name(name), description(description), isLocked(locked), KeyItemFound(keyFound), keyItem(key){}
Location::Location(const string& name, const string& description, const vector<Clue*>& requiredClues, bool locked, bool keyFound, Item* key)
    : name(name), description(description), isLocked(locked), keyItemFound(keyFound), keyItem(key), requiredCluesToLeave(requiredClues) {}
Location::~Location(){
    itemList.clear();
    keyItem = nullptr;
    requiredCluesToLeave.clear();
}

void Location::SetRoom(const string& roomName, const string& roomDescription, const vector<Item>& items){
    name = roomName;
    description = roomDescription;
    itemList.clear();
    for(int i = 0; i < items.size(); ++i){
        itemList.push_back(new Item(Items[i]));
    }
    keyItem = nullptr;
}
void Location::SetRoom(const string& roomName, const string& roomDescription, Item* Key){
    name = roomName;
    description = roomDescription;
    keyItem = key;
    isLocked = false;
}
void Location::SetRoom(const string& roomName, const string& roomDescription, bool locked, Item* Key){
    name = roomName;
    description = roomDescription;
    isLocked = locked;
    keyItem = Key;
}
void Location::SetRequiredClues(const vector<Clue*>& Clues){
    requiredCluesToLeave = Clues;
}

// Other methods
bool Location::checkUnlock(bool KeyItemFound) const{
    return !isLocked || keyItemFound;
}
void Location::addItem(Item* item){
    itemList.push_back(item);
}

const vector<Item*>& Location::getItemList() const {return itemList;}
Item* Location::getKeyItem() const {return keyItem;}
string Location::getName() const {return name;}
string Location::getDescription() const {return description;}
bool Location::isLockedStatus() const {return isLocked;}
bool Location::hasKeyItemBeenFound() const {return keyItemFound;}
bool Location::setKeyItemFound(bool found) {
    keyItemFound = found;
    return keyItemFound;
}




