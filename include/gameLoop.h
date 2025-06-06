#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>

//tells the compilar these will exist
class GameData;
class Location;
class Day;


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
    void acquireNewClue(const string& clueName);
    void changeDayTime(int dayNum, const string& currentTime);
    void playerChoices(int hpUpdate, bool subtract);

    string goToLocation(const string& requiredLocation);
    Location* findLocation(string locationName);
    Day* findDay(int numDay);
    bool cluesMatch(int numDay);

};
#endif
