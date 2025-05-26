#include "gameLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<Location> GameLoader::loadLocations(const string& filename){

}
//"vector<Item> GameLoader::loadItems(const string& filename);
vector<unique_ptr<Clue>> GameLoader::loadClues(const string& filename){

}

map<string, vector<unique_ptr<DialogueUnit>>> GameLoader::loadDialogue(const vector<string>& DialogueFiles){
    map<string, vector<unique_ptr<DialogueUnit>>> dialogueMap;

    for (const string& file : DialogueFiles) {
        //specify where files are located
        ifstream inFile("src/game_text_files/" + file);

        if (!inFile.is_open()) {
            //debug error if file is not open
            throw runtime_error("Failed to open dialogue file: " + file);
        }

        string line;
        while (getline(inFile, line)) {
            // Remove trailing whitespace (optional, helps match +tags better)
            if (!line.empty()) {
                line.erase(line.find_last_not_of(" \t\r\n") + 1);
            }

            if (line.find("+clue") != string::npos) {
                // Process clue line
            } else if (line.find("+interview") != string::npos) {
                // Process interview line
            } else if (line.find("+choice") != string::npos) {
                // Process choice line
            } else if (line.find("+end") != string::npos) {
                // Process end line
            }
        }

        inFile.close();
    }
    return dialogueMap;

}

vector<Day> GameLoader::loadDays(const string& filename){
    vector<Day> days;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line;
    while (getline(inFile, line)) {
        // Remove trailing whitespace (optional, helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }

        if (line.find("+player") != string::npos) {
            // Process clue line
        } else if (line.find("+clue") != string::npos) {
            // Process interview line
        } else if (line.find("+end") != string::npos) {
            // Process end line
        }
    }

    inFile.close();
    return days;
}

vector<Person> GameLoader::loadCharacters(const string& filename){
    vector<Person> people;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line;
    while (getline(inFile, line)) {
        // Remove trailing whitespace (optional, helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }

        if (line.find("+player") != string::npos) {
            // Read player info (4 lines total, +end ignored)
            string name, bloodType, item, description;
            getline(inFile, name);
            getline(inFile, bloodType);
            getline(inFile, item);
            getline(inFile, description);
            getline(inFile, line); 
            // skip +end
            vector<Player> players;

            players = loadplayers(name, bloodType item,description);


        }else{
            //non people texts 
            string name, bloodType, item, description;
            bool isDead, hasAutopsy;

            getline(inFile, name);
            getline(inFile, bloodType);
            getline(inFile, item);

            //how to read these in theyre proper value?
            //getline(inFile, isDead);
            //getline(inFile, hasAutopsy);

            getline(inFile, description);
            getline(inFile, line); // skip
        }
    }

    inFile.close();
    return people;
}

vector<Player> loadplayers(string name, string bloodType, string item,string description){
    vector<Player> players;
    Player player(name, bloodType, item, description);
    players.push_back(player);

    return players;
}

vector<Autopsy> GameLoader::loadAutopies(const string& filename){
    
}

vector<Ending> GameLoader::loadendings(const string& filename){
    

}

// Similar methods for loadItems and loadClues
GameData LoadFiles() {
    GameLoader DropDead;
    GameData data;

    vector<string> DialogueFiles = {"Day1Morning.txt", "Day1Evening.txt","Day1Night.txt", 
    "Day2Morning.txt", "Day2Evening.txt", "Day2Night.txt", "Day3Morning.txt", "Day3Evening.txt",
    "Day3Night.txt"};
    //read all file names and push contents to DialogueFiles
    

    data.locationLibrary = DropDead.loadLocations("src/Locations.txt");
    data.clueLibrary = DropDead.loadClues("src/Items.txt");
    data.gameDialogue = DropDead.loadDialogue(DialogueFiles);
    data.autopsyLibrary = DropDead.loadAutopies("src/autopsies.txt");
    data.dayLibrary = DropDead.loadDays("src/days.txt");
    data.endingsLibrary = DropDead.loadendings("src/endings.txt");
    data.personLibrary = DropDead.loadCharacters("src/person.txt");

    return data;
}
