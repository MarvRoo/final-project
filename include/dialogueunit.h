#ifndef DIALOGUEUNIT_H
#define DIALOGUEUNIT_H

#include <vector>
#include <memory>
using namespace std;

class Interface;  // <--- forward declare here
class gameLoop;  // <--- Add this line to forward-declare

class DialogueUnit {
public:
    virtual void print() const = 0;            // Pure virtual function
    virtual ~DialogueUnit() = default;         // Virtual default destructor

    virtual void setInterface(shared_ptr<Interface> visuals) = 0;
    virtual void setGameLoop(gameLoop* GameFunctions) = 0;
};

#endif