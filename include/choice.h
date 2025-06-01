#ifndef CHOICE_H
#define CHOICE_H


#include "dialogueunit.h"
#include <string>

class Choice : public DialogueUnit{
private:
    vector<pair<string, int>> options;
public: 
    Choice();
    Choice(const vector<pair<string, int>>& choices);
    void print() const override;
    int getPointValue(int index) const;

};

#endif