#include "autopsy.h"
#include <iostream>

using namespace std;


Autopsy::Autopsy(string charName, const string& descript) : characterName(charName), autopsyDescription(descript) {}

string Autopsy::getCharacterName() const{
    return characterName;
}
string Autopsy::getAutopsyDescription() const{
    return autopsyDescription;
}
Autopsy::~Autopsy(){}