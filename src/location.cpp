#include "location.h"
#include <string>
#include <vector>
using namespace std;

Location::Location(const string& name, const string& description, vector <string> clueList, bool accessible, bool multiple, string keyClue){
    isAccessible = accessible;
    this->name = name;
    this->description = description;
    hasMultipleClues = multiple;
    keyClueFound = false;
    this->keyClue = keyClue;
    this->clueList = clueList;
}

Location::Location(const string& name, const string& description, bool accessible, bool multiple, string keyClue){
    isAccessible = accessible;
    this->name = name;
    this->description = description;
    hasMultipleClues = multiple;
    keyClueFound = false;
    this->keyClue = keyClue;

}

bool Location::checkUnlock(){
    return isAccessible;
}

bool Location::checkMultiItems(){
    return hasMultipleClues;
}
string Location::getName() const {return name;}
string Location::getKeyClue() const {return keyClue;}
vector<string> Location::getClueList() const {return clueList;}
void Location::unlockLocation(){isAccessible = true;}
void Location::lockLocation(){isAccessible = false;}
void Location::changeClueFound(){keyClueFound = true;}
bool Location::checkkeyClueFound(){return keyClueFound;}
