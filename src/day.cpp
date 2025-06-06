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

bool Day::isNight(){
    //no other logic needed besides returning the value of the priavte variable Night
    return Night;
}

bool Day::isMorning(){
    return Morning;
}

bool Day::isEvening(){
    return Evening;
}

bool Day::isDayComplete(const vector<int>& playerClueList) {
    for (int requiredClue : allDayClues) {
        bool found = false;
        for (int playerClue : playerClueList) {
            if (playerClue == requiredClue) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false; 
            //At least one required clue not found
        }
    }
    return true; //All required clues found
}

void Day::changeDay(const string& currentTimeOfDay){

    if(currentTimeOfDay == "Night"){
        Night = false;
        //Day 2 morning changed to true in game loop
    }
    else if(currentTimeOfDay == "Evening"){
        Evening = false;
        Night = true;
    }
    else if(currentTimeOfDay == "Morning"){
        Morning = false;
        Evening = true;
    }else{
        //being called to change morning to true for day 2 or 3
        Morning = true;
    }
}