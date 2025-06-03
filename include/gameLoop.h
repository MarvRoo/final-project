#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>

#include "gamedata.h"
#include "interface.h"
#include "printer.h"

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
    Interface interface;
    Printer printer;
};
#endif
