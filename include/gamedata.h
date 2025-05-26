#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <map>
#include <memory>


#include "location.h"
#include "dialogue.h"
#include "autopsy.h"
#include "ending.h"
#include "dialogueunit.h"
#include "day.h"
#include "person.h"
#include "player.h"

using namespace std;

//Just a data container no .cpp
// what the game knows.
struct GameData {
    vector<Location> locationLibrary;
    vector<unique_ptr<Clue>> clueLibrary;
    vector<Autopsy> autopsyLibrary;
    vector<Ending> endingsLibrary; 
    vector<Day> dayLibrary;
    vector<Person> personLibrary;
    vector<Player> playerLibrary;
    map<string, vector<unique_ptr<DialogueUnit>>> gameDialogue;
    //A collection of Dialogue objects
};

#endif