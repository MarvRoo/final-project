#ifndef CHOICE_H
#define CHOICE_H


#include "dialogueunit.h"
#include "gameLoop.h"
#include <string>


class Choice : public DialogueUnit{
private:
    vector<pair<string, int>> options;
    bool negHp;
    shared_ptr<Interface> interface;
    gameLoop* gameFunctions = nullptr;

public: 
    Choice();
    Choice(const vector<pair<string, int>>& choices, bool isChoiceNeg);
    void print() const override;
    int getPointValue(int index) const;
    bool isNeg(){return negHp;}

    void setInterface(std::shared_ptr<Interface> visuals) override {
        interface = visuals;
    }
    
    void setGameLoop(gameLoop* ptr) override {
        gameFunctions = ptr;
    }

};

#endif