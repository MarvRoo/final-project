#ifndef PRINTER_H
#define PRINTER_H

#include "player.h"
#include "gamedata.h"
#include "ending.h"
#include <vector>

using namespace std;

class Printer {
    private:
        //printer should already have access
        const GameData* gameLibraryPtr;
        Player* playerPtr;


    public:
        void setGameData(GameData* gameDataPtr){this->gameLibraryPtr = gameDataPtr;}
        void setplayer(Player* player){playerPtr = player;}
        void printAccessibleLocations();

        void printClues();
        void printClue(string clueName);

        void printSearchItems();
        void printSearchItem(string itemName);

        void printPersonDetails(const std::string& personName);
        void printEnd(const Ending& ending);
        void printAutopsy(const std::string& characterName) const;
};

#endif