#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "item.h"
using namespace std;

class Person{
private:
    bool isDead;
    bool hasAutopsy;
protected:
    string name;
    string bloodType;
    string personalItem;
    string description;
public:
    Person();
    Person(const string& name, const string& bloodType, const string& personalItem, bool isDead, bool hasAutopsy,  const string& description);
    string grabDescription() const;
};

#endif