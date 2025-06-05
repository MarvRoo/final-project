#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
#include <memory>  // For std::shared_ptr
using namespace std;

class Interface;  // <--- forward declare here

class DialogueUnit {
public:
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor

    virtual void setInterface(shared_ptr<Interface> visuals) = 0;
};

#endif