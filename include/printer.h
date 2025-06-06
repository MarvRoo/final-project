#ifndef PRINTER_H
#define PRINTER_H

class GameData; 
//forward declaration

#include "player.h"
#include "gamedata.h"
#include "ending.h"

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Printer {
private:
    GameData* gameLibraryPtr;
    Player* playerPtr;

public:
    void setGameData(GameData* gameDataPtr) { this->gameLibraryPtr = gameDataPtr; }
    void setplayer(Player* player) { playerPtr = player; }

    // Prints only accessible locations and returns the one chosen
    string printAccessibleLocations() const;
    //repetative pop up that gives player review the location they want go
    void printLocation(string locName) const;

    // Prints details about a person by name
    void printPersonDetails(const std::string& personName);

    // Prints the ending scene
    void printEnd();

    // Prints autopsy information for a character
    void printAutopsy(const std::string& characterName) const;

    // Print the list of player-collected items, numbered; returns the count
    int printSelectableItems() const;

    // Print the list of player-collected clues/interviews; returns the count
    int printSelectableClues() const;

    // Prints the name of the selected item based on its index
    void printSelectedItemByIndex(int index) const;

    // Prints the full details of a selected clue/interview by index
    void printSelectedClueByIndex(int index) const;
};

#endif
