#include "day.h"

Day::Day(int numDay, bool Night, bool Evening, bool Morning, bool cluesFound, bool lockedDay, const vector<int>& unlockClues){
    this->numDay = numDay;
    this->Night = Night;
    this->Evening = Evening;
    this->Morning = Morning;
    this->allFound = cluesFound;
    this->locked = lockedDay;
    this->allDayClues = unlockClues;
}

bool Day::isNight(int Day){
    //no other logic needed besides returning the value of the priavte variable Night
    return Night;
}

bool Day::isMorning(int Day){
    return Morning;
}

bool Day::isEvening(int Day){
    return Evening;
}

bool Day::isDayComplete(const vector<int>& playerClueList) {
    if (playerClueList == this->allDayClues) return true;
    return false;
}

void Day::changeDay(const string& newTimeOfDay){
    Night = false;
    Evening = false;
    Morning = false;

    if(newTimeOfDay == "Night"){
        Night = true;
    }
    else if(newTimeOfDay == "Evening"){
        Evening = true;
    }
    else if(newTimeOfDay == "Morning"){
        Morning = true;
    }
}