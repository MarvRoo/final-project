#include "dialogue.h"
#include <string>

using namespace std;

Dialogue::Dialogue(){}

Dialogue::Dialogue(vector<string> dialogueStrings){
    this->dialogueSegments = dialogueStrings;
}

void Dialogue::print() const {
    //prints all strings but can return a checkpoint string to conduct code in gameloop and then continue printing
    //call go to location example
    //continues reading until another checkpoint
}