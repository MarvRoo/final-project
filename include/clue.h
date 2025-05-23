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
    Clue(int id, const string& name, bool inspected);
    string getName() const;
    bool isInspected() const;
    int getClueID() const;
};

#endif