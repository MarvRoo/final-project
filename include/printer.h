#ifndef PRINTER_H
#define PRINTER_H

#include "player.h"
#include "gamedata.h"
#include "ending.h"
#include <vector>

using namespace std;

class Printer {
    private:
        const GameData* gameDataPtr;

    public:
        void setGameData(const GameData& data);
        void printClues(vector<vector<string>>* clues);
        void printSearchItem(vector<Item*>* items);
        void printPersonDetails(const string& personName);
        void printEnd(const Ending& ending);
        void printAccessibleLocations(Player* player);
};

#endif