#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include "location.h"
#include "item.h"
#include "clue.h"
#include "dialogue.h"

using namespace std;

//Just a data container no .cpp
// what the game knows.
struct GameData {
    vector<Location> locations;
    //vector<Item> items; since technically all clue in vector can be interview or items
    vector<Clue> clues;
    vector<Dialogue> dialogueSegments;
    //A collection of Dialogue objects
};

#endif