#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Person{
public:
    string name;
    string bloodType;
    string personalItem;
    string whoseFingerprint;
    bool isDead;
    bool hasFingerprint;
    bool hasAutopsy;
    vector<Item*> autopsies;
    string description;

    Person();
    Person(const string& name, const string& bloodType, const string& personalItem, const string& whoseFingerprint, bool isDead, bool hasFingerprint, bool hasAutopsy, const vector<Item*>& autopsies,  const string& description);
    ~Person();

    void setDescription(const string& description);
    void personConstructor();
    bool findAutopsies(const vector<Item*>& items, bool hasAutopsy);
};


