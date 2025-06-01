#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <vector>
using namespace std;
#include "dialogueunit.h"


class Dialogue : public DialogueUnit{
private:
    vector<string> dialogueSegments;
public:

    Dialogue();
    Dialogue(vector<string> dialogueStrings);
    void print() const override;

};

#endif