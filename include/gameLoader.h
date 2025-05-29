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
    //remove this after these are the checkpoint used in this code
    vector<string> checkpoints = {"+player","+clue", "+interview","+choice", "+person", "+end"};
    //list is used primarily in dialogue 
    //but will be used in person.txt


public:
    vector<Location> loadLocations(const string& filename);

    vector<unique_ptr<Clue>> loadClues (const string& filename);
    unique_ptr<Item> makeItem(); //return pointer of item
    //unique_ptr<Interview> makeInterview(); in progress i do not have the class yet

    //incomplete
    map<string, vector<unique_ptr<DialogueUnit>>> loadDialogue(vector<string>& DialogueFiles);
    //these functions help make the pointer object to push to loadDialogues
    unique_ptr<Choice> makeChoice();
    unique_ptr<Dialogue> makeDialogue();

    vector<Day> loadDays(const string& filename);
    vector<Autopsy> loadAutopies(const string& filename);
    vector<Ending> loadendings(const string& filename);

    //game loader for people complete in theory(start testing)
    vector<Person> loadCharacters(const string& filename, vector<Player> &players);
    Player makePlayer(const string name,const string bloodType,const string item,const string description);
};

GameData LoadFiles();

#endif
