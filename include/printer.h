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
        GameData* gameLibraryPtr;
        Player* playerPtr;
        // Stores the last displayed selectable items and clues for index-based selection
        vector<const Item*> lastItemList;
        vector<const Clue*> lastClueList;


    public:
        void setGameData(GameData* gameDataPtr){this->gameLibraryPtr = gameDataPtr;}
        void setplayer(Player* player){playerPtr = player;}
        int printAccessibleLocations();
        vector<string> getAccessibleLocationList() const;
        string printLocation(int choosenindex);

        void printClues();
        void printSearchItems();

        void printPersonDetails(const std::string& personName);
        void printEnd(const Ending& ending);
        void printAutopsy(const std::string& characterName) const;


        // Print grouped and numbered selectable items and clues
        int printSelectableItems();         // Displays acquired items and stores them
        int printSelectableClues();         // Displays acquired clues and stores them

        // Print selected item/clue based on index (1-based)
        void printSelectedItemByIndex(int index);
        void printSelectedClueByIndex(int index);
};

#endif