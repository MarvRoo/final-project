#include "Person.h"
using namespace std;

Person()::Person() : isDead(false), hasFingerprint(false), hasAutopsy(false) {}
Person::Person(const string& name, const string& bloodType, const string& personalItem, const string& whoseFingerprint, bool isDead, bool hasFingerprint, bool hasAutopsy, const vector<Item*>& autopsies,  const string& description) 
    : name(name), bloodType(bloodType), personalItem(personalItem), whoseFingerprint(whoseFingerprint), isDead(isDead), hasFingerprint(hasFingerprint), hasAutopsy(hasAutopsy), autopsies(autopsies), description(description) {}
Person::~Person();
void setDescription(const string& description){
    this->description = description
}
void personConstructor(){
    this->name = "";
    this->bloodType = "";
    this->personalItem = "";
    this->isDead = false;
    this->hasFingerprint = false;
    this->hasAutopsy = false;
    this->autopsies.clear();
    this->description = "";
}
bool findAutopsies(const vector<Item*>& items, bool hasAutopsy){
    this->hasAutopsy = hasAutopsy;

    if(!hasAutopsy){
        return false;
    }
    for(int i = 0; i < items.size(); i++){
        Item* missingItem = items[i];
        bool found = false;

        for(int j = 0; j < autopsies.size(); j++){
            Item* autopsyItem = autopsies[j];

            if(missingItem != nullptr && autopsyItem != nullptr && missingItem == autopsyItem){
                found = true;
                break;
            }
        }
    }
    
}

