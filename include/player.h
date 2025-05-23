#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"
using namespace std;

class Player{
public:
    string declaredSuspect; 
    Player();
    void setSuspect(string suspectName = "NA");
    void nextRoom(int roomId);
    void ReviewClues(int clueId); 
    void ReviewItem(int itemId);
    void startInterview(string suspectName);
};

#endif