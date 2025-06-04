#include "autopsy.h"
#include <iostream>

using namespace std;


Autopsy::Autopsy(string charName, const string& descript) : characterName(charName), autopsyDescription(descript) {}

void Autopsy::findAutopsies(string personName) {
    if(this->characterName == personName) {
        cout << this->autopsyDescription << endl;
    }
    
}
Autopsy::~Autopsy(){}