#include "Day.h"

Day::Day() : Night(false), Evening(false), Morning(false), Day(0) {}

Day::Day(int Day, vector<Clue*> unlockClues, bool Night, bool Evening, bool Morning)
    : Day(day), Night(night), Evening(evening), Morning(morning), nextDayUnlock(unlockClues) {}

Day::~Day();

void Day::setDay(int dayNum, vector<Clue*> unlockClues, bool isNight, bool isEvening, bool isMorning){
    Day = dayNum;
    nextDayUnlock = unlockClues;
    Night = isNight;
    Evening = isEvening;
    Morning = isMorning;
}

bool Day::isNight(int Day){
    return Day == dayNum && Night;
}

bool Day::isMorning(int Day){
    return Day == dayNum && Morning;
}

bool Day::isEvening(int Day){
    return Day == dayNum && Evening;
}

bool Day::isDayComplete(const vector<Clue*>& playerClueList) const{
    if(Night){
        return CheckDayComplete(playerClueList);
    }
    else{
        return false;
    }
}

bool Day::CheckDayComplete(const vector<Clue*>& clueList) const{
    for(int i = 0; i < nextDayUnlock.size(); i++){
        Clue* unlockClue = nextDayUnlock[i];
        bool found = false;

        if(unlockClue != nullptr){
            for(int j = 0; j < ClueList.size(); j++){
                Clue* playerCLue = clueList[j];

                if(playerClue != nullptr && unlockClue->getClueID() == playerClue->getClueId()){
                    found = true;
                    break;
                }
            }
            if(!found && !nextDayUnlock.empty()){
                return false;
            }
        }
    }
    return true;
}