#ifndef GAMElOADER_H
#define GAMELOADER_H

#include <vector>
#include <string>
#include "gamedata.h"

using namespace std;

//A class full of pure reader functions
//how it learns it (from files).
class GameLoader {
public:
    vector<Location> loadLocations(const string& filename);
    //vector<Item> loadItems(const string& filename);
    vector<Clue> loadClues(const string& filename);
    vector<Dialogue> loadDialogue(const vector<string>& DialogueFiles);
    //vector<Day> loadDays(const string& filename);
    //vector<Interviews> loadInterviews(const string& filename);
    //vector<Person> loadCharacters(const string& filename);
};

GameData LoadFiles();

#endif
