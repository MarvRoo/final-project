#ifndef CHOICE_H
#define CHOICE_H


#include "dialogueunit.h"
#include <string>

class Choice : public DialogueUnit{
private:
    vector<pair<string, int>> options;
    bool negHp;
    Interface* interface;
public: 
    Choice();
    Choice(const vector<pair<string, int>>& choices, bool isChoiceNeg);
    void print() const override;
    int getPointValue(int index) const;

    void setInterface(Interface* visuals) override { interface = visuals; }

};

#endif