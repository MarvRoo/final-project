#include "location.h"
#include <string>
#include <vector>
#include "item.h"
#include "clue.h"
using namespace std;

Location::Location(const string& name, const string& description, vector <string> ItemClues, bool accessible, bool multiple, string keyItem){
    isAccessible = acsessible;
    this->name = name;
    this->description = description;
    hasMultipleClues = multiple;
    keyItemFound = false;
    keyItemId = 0;
    itemsList = ItemClues;
}

Location::Location(const string& name, const string& description, bool accessible, bool multiple, string keyItem){
    isAccessible = acsessible;
    this->name = name;
    this->description = description;
    hasMultipleClues = multiple;
    keyItemFound = false;
    keyItemId = 0;
    itemsList = ItemClues;
}

bool Location::checkUnlock(){
    return isAcsessible;
}

bool Location::checkMultiItems(){
    return hasMultipleClues;
}
