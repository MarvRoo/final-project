#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>

#include "gamedata.h"
#include "interface.h"
#include "printer.h"
#include "player.h"

class gameLoop{
private:
    Player* playerPtr;
    GameData* libraries;
public:
    gameLoop(){}
    ~gameLoop(){}

    void setInternalData(GameData* gameData){ this->libraries = gameData;}

    void run();
    void unlockNextLocation(const string& locationName);
    void setPlayer(Player* playerPtr){this->playerPtr = playerPtr;}

    string goToLocation(const string& requiredLocation);
    void acquireNewClue(const string& clueName);
    void changeDayTime(int dayNum, const string& currentTime);
    Location* findLocation(string locationName);
    Day* findDay(int numDay);

};
#endif
