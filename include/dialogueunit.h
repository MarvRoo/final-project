#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
using namespace std;

class DialogueUnit {
private:
    Interface* interface;
public:
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor
    
    virtual void setInterface(Interface* visuals){interface = visuals;}
};

#endif