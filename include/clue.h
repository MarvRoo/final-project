#ifndef CLUE_H
#define CLUE_H

#include <string>
using namespace std;

class Clue {
protected:
    int ClueID;
    string name;
    bool inspected;

public:
    Clue();
    Clue(int id, const string& name);
    virtual void print();
    virtual ~Clue();
    Clue(const Clue&) = delete; //delete copy constructor
    Clue& operator=(const Clue&) = delete; //delete copy assignment operator
};

#endif