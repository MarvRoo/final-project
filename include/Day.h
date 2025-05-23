#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include "Item.h"
#include "Clue.h"
#include "Player.h"
using namespace std;

class Day{
public:
    bool Night;
    bool Evening;
    bool Morning;
    int Day;
    vector<Clue*> nextDayUnlock;

    Day();
    Day(int Day, bool Night, bool Evening, bool Morning, const vector<Clue*>& unlockClues);
    ~Day();
   
    void setDay(int Day, vector<Clue*> unlockClues, bool isNight, bool isEvening, bool isMorning);
    bool isNight(int Day);
    bool isMorning(int Day);
    bool isEvening(int Day);
    bool isDayComplete() const;
    bool CheckDayComplete(vector<Clue*> ClueList) const;
};


