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
    int numDay = 0;
    vector<int> allDayClues;

public:

    Day();
    Day(int numDay, bool Night, bool Evening, bool Morning, const vector<int>& unlockClues);
   
    bool isNight(int Day);
    bool isMorning(int Day);
    bool isEvening(int Day);

    bool isDayComplete(const vector<int>& playerClueList) const;
    bool isDayComplete(const vector<int>& playerClueList) const;
};

#endif