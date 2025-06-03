#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>

using namespace std;

class Day{
private:
    bool Night;
    bool Evening;
    bool Morning;
    bool allFound;
    bool locked;

    int numDay = 0;
    vector<int> allDayClues;

public:

    Day(){}
    //dayNumber, morning, evening, night, locked, allFound, clues
    Day(int numDay, bool Night, bool Evening, bool Morning, bool cluesFound, bool lockedDay, const vector<int>& unlockClues);
   
    bool isNight(int Day);
    bool isMorning(int Day);
    bool isEvening(int Day);

    bool isDayComplete(const vector<int>& playerClueList);
    void changeDay(const string& newTimeOfDay){}
};

#endif