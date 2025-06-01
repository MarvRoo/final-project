#include "dialogue.h"
#include <string>

using namespace std;

Dialogue::Dialogue(){}

Dialogue::Dialogue(vector<string> dialogueStrings){
    this->dialogueSegments = dialogueStrings;
}

void Dialogue::print() const {
    //tbd
    //has to ccount for programming checkpoints
    //checkpoint functions implements in gameloop. Game loop calls to print and shares it's
    //functions with dialogue print so it prints properly
}