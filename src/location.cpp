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


