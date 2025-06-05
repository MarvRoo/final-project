#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <vector>
#include <map>
#include <memory>

class DialogueUnit;  // Forward declaration

#include "dialogueunit.h"
#include "dialogue.h"
#include "choice.h"
#include "autopsy.h"
#include "ending.h"
#include "day.h"
#include "person.h"
#include "player.h"
#include "location.h"
#include "item.h"
#include "clue.h"
#include "interview.h"

using namespace std;

//Just a data container no .cpp
// what the game knows.
struct GameData {
    vector<string> dialogueKeyOrder;
    vector<Location> locationLibrary;
    vector<unique_ptr<Clue>> clueLibrary;
    vector<Autopsy> autopsyLibrary;
    vector<Ending> endingsLibrary; 
    vector<Day> dayLibrary;
    vector<Person> personLibrary;
    vector<Player> playerLibrary;
    map<string, vector<unique_ptr<DialogueUnit>>> gameDialogue;
    //A collection of Dialogue objects mapped by a key word
};

#endif