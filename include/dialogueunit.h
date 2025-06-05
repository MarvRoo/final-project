#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
using namespace std;
#include "interface.h"

class DialogueUnit {
public:
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor
    
    virtual void setInterface(Interface* visuals) = 0;
};

#endif