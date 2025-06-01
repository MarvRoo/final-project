#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <vector>
#include <string>
using namespace std;
#include "dialogueunit.h"


class Dialogue : public DialogueUnit{
private:
    vector<string> dialogueSegments;
public:

    Dialogue();
    Dialogue(vector<string> dialogueStrings);
    //acts as a filter and caller to gameloops checkpoint functions 
    void print() const override;
};

#endif