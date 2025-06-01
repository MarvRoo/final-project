#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
using namespace std;

class DialogueUnit {
public:
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor
};

#endif