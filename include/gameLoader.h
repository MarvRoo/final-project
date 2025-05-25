#ifndef GAMElOADER_H
#define GAMELOADER_H

#include <vector>
#include <string>
#include <memory>

#include "gamedata.h"

using namespace std;

//A class full of pure reader functions
//how it learns it (from files).
class GameLoader {
private:
    vector<string> checkpoints = {"+player","+clue", "+interview","+choice", "+person", "+end"};
    //list is used primarily in dialogue 
    //but will be used in person.txt
public:
    vector<Location> loadLocations(const string& filename);
    vector<unique_ptr<Clue>> loadClues (const string& filename);
    map<string, vector<unique_ptr<DialogueUnit>>> loadDialogue(const vector<string>& DialogueFiles);
    vector<Day> loadDays(const string& filename);
    vector<Person> loadCharacters(const string& filename);
    vector<Autopsy> loadAutopies(const string& filename);
    vector<Ending> loadendings(const string& filename);
};

GameData LoadFiles();

#endif
