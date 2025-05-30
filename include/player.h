#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "item.h"

using namespace std;

class Player : public Person{
private: 
    vector<vector<string>> clueList;
    vector<string> roomList;
    string declaredSuspect = "N/A";
    int hp = 50;
    vector<string> clueSummary;
    //made up of strings like interview names, clue names, and item names
    //player has to order them in the correct order to move on 
public:
    Player(string name, string bloodType, string item,string description){
        this->name = name;
        this->bloodType = bloodType;
        personalItem = item;
        this-> description = description;
    }

    void setSuspect(string const suspectName){declaredSuspect = suspectName;}
    vector<string> grabclueSummary() const {return clueSummary;}
    vector<vector<string>>* shareClueListPtr() {return &clueList;}
    vector<string>* shareRoomListPtr() {return &roomList;}
};

#endif