#ifndef CLUE_H
#define CLUE_H

#include <string>
#include <iostream>
using namespace std;

class Clue {
protected:
    int ClueID;
    string name;
    bool inspected;

public:
    Clue();
    Clue(int id, const string& name);

    virtual void print() { cout << name; }
    virtual ~Clue();

    Clue(const Clue&) = delete; //delete copy constructor
    Clue& operator=(const Clue&) = delete; //delete copy assignment operator

    string getName() const;
    void setInspected(bool inspection) { inspected = inspection; }

    // Identify type of clue (default is "Clue")
    virtual string getType() const { return "Clue"; }
};

#endif