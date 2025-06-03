#include "person.h"
using namespace std;


Person::Person(){
    //empty
}

Person::Person(const string& name, const string& bloodType, const string& personalItem, bool isDead, bool hasAutopsy,  const string& description){
    this->name = name;
    this->bloodType = bloodType;
    this->personalItem = personalItem;
    this->isDead = isDead;
    this->hasAutopsy = hasAutopsy;
    this->description = description;
}

string Person::grabDescription() const{
    return description;
}

string Person::getPersonName() const {return name;}
