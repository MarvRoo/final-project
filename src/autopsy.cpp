#include "autopsy.h"
#include <iostream>

using namespace std;


Autopsy::Autopsy(string charName, const string& descript) : characterName(charName), autopsyDescription(descript) {}

void Autopsy::findAutopsies(string personName) const {
    if(this->characterName == personName) {
        cout << this->autopsyDescription << endl;
    }
    
}
string Autopsy::getCharacterName() const{
    return characterName;
}
string Autopsy::getAutopsyDescription() const{
    return autopsyDescription;
}
Autopsy::~Autopsy(){}