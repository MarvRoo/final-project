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
    GameData gameData;
    Player* playerPtr;
public:
    gameLoop(){}
    ~gameLoop(){}

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
