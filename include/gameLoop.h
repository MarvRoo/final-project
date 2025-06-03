#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>
#include "gameData.h"
#include "day.h"
#include "clue.h"
#include "interface.h"
#include "printer.h"
#include "gameLoader.h"

class gameLoop{
public:
    gameLoop();
    ~gameLoop();

    void run();
    void unlockNextLocation(const string& locationName);
    string goToLocation();
    string goToLocation(const string& requiredLocation);
    void acquireNewClue(const string& clueName);
    void changeDayTime(int dayNum, string& currentTime);

private:
    GameData gameData;
    Player* playerPtr;
}
