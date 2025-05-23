#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include "item.h"
#include "clue.h"
using namespace std;

class Location {
protected:
    string name;
    string description; 
    bool islocked;
    bool KeyItemFound;
    Item* keyitem;
    vector<Item*> itemList;
    vector<Clue*> requiredCluesToLeave;

public:
    // Constructors
    Location();
    Location(const string& name, const string& description, bool locked = false, bool keyFound = false, Item* key = nullptr);
    Location(const string& name, const string& description, const vector<Clue*>&  requiredClues, bool locked = false, bool keyFound = false, Item* key = nullptr);
    ~Location();

    // SetRoom variants
    void SetRoom(const string& name, const string& description, const vector<Item>& items);
    void SetRoom(const string& name, const string& description, Item* Key);
    void SetRoom(const string& name, const string& description, bool locked, Item* Key);
    void SetRequiredClues(const vector<Clue*>& Clues);
    const vector<Clue*>& getRequiredCluesToLeave() const {return requiredCluesToLeave;}

    // Other methods
    bool checkUnlock(bool KeyItemFound) const;
    void addItem(Item* item);
    const vector<Item*>& getItemList() const {return itemList;}
    Item* getKeyItem() const {return keyItem;}
    string getName() const {return name;}
    string getDescription() const {return description;}
    bool isLockedStatus() const {return isLocked;}
    bool hasKeyItemBeenFound() const {return keyItemFound;}
    bool setKeyItemFound(bool found) {keyItemFound = found;}

};
#endif