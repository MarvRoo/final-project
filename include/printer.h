#ifndef PRINTER_H
#define PRINTER_H

#include "player.h"
#include "gamedata.h"
#include "ending.h"

using namespace std;

class Printer {
    private:
        const GameData* gameDataPtr;

    public:
        void setGameData(const GameData& data);
        void printClues(vector<vector<string>>* clues);
        void printSearchItemLibrary(vector<string>* items);
        void printPersonDetails(const string& personName);
        void printDialogueSegment(const string& segementName);
        void printEnd(const Ending& ending);
};

#endif