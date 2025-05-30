#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
using namespace std;


/*
+ void print() = 0: virtual void 
+ ~DialogueUnit() = default: virtual*/
class DialogueUnit {
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor
};

#endif