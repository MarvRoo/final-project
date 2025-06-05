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
public:
    vector<Location> loadLocations(const string& filename);

    vector<unique_ptr<Clue>> loadClues (const string& filename, const string& filename2);

    //internal Dialogue reader helper
    /*void handleNewMappingName(
        const string& newMappingName,
        string& currentMappingName,
        vector<string>& dialogueLines,
        map<string, vector<unique_ptr<DialogueUnit>>>& dialogueMap,
        vector<string>& perserveKeyOrder
    );*/

    void flushDialogueBuffer(
        map<string, vector<unique_ptr<DialogueUnit>>>& dialogueMap,
        vector<string>& perserveKeyOrder,
        string& currentMappingName,
        vector<string>& dialogueLines
    );
    map<string, vector<unique_ptr<DialogueUnit>>> loadDialogue(vector<string>& DialogueFiles, vector<string> &keyOrder);
    //these functions help make the pointer object to push to loadDialogues

    vector<Day> loadDays(const string& filename);
    vector<Autopsy> loadAutopies(const string& filename);
    vector<Ending> loadendings(const string& filename);

    //game loader for people complete in theory(start testing)
    vector<Person> loadCharacters(const string& filename, vector<Player> &players);
    //Player makePlayer(const string name,const string bloodType,const string item,const string description);
};

GameData LoadFiles();

#endif
