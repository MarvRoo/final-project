#include "autopsy.h"

using namespace std;


Autopsy::Autopsy(string charName, const string& descript) : characterName(charName), autopsyDescription(descript) {}

Autopsy Autopsy::findAutopsies(string personName) {
    return Autopsy(personName, this->autopsyDescription);
}