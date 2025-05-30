#include "gameLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<Location> GameLoader::loadLocations(const string& filename){
    vector<Location> locations;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

     string line;
    while (getline(inFile, line)) {
        //Remove trailing whitespace (helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }
        //we don't push white lines, it's just text file formatting

        string name, bloodType, item, description;
        if (line.find("+player") != string::npos) {
        }
    }
    inFile.close();
    return locations;

    
}

//Tank works the same as dialogue but no mapping
vector<unique_ptr<Clue>> GameLoader::loadClues(const string& filename){

}

map<string, vector<unique_ptr<DialogueUnit>>> GameLoader::loadDialogue(vector<string>& DialogueFiles){
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

//checkpoints +player and +end used in txt file
//read from the same text file
vector<Person> GameLoader::loadCharacters(const string& filename, vector<Player> &players){
    vector<Person> people;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line;
    while (getline(inFile, line)) {
        //Remove trailing whitespace (helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }
        //we don't push white lines, it's just text file formatting

        string name, bloodType, item, description;
        if (line.find("+player") != string::npos) {
            //Read player info (4 lines total, +end ignored)
            getline(inFile, name);
            getline(inFile, bloodType);
            getline(inFile, item);
            getline(inFile, description);
            getline(inFile, line); 
            // skip +end

            //call the functon to make a player object and push the return
            players.push_back(makePlayer(name, bloodType, item ,description));

        }else{
            //non player
            string isDeadStr, hasAutopsyStr;
            bool isDead, hasAutopsy;

            getline(inFile, name);
            getline(inFile, bloodType);
            getline(inFile, item);

            //how to read these in theyre proper value?
            getline(inFile, isDeadStr);
            getline(inFile, hasAutopsyStr);
            //formatting may vary depending on writer but overall format followed
            isDead = (isDeadStr == "true" || isDeadStr == "1");
            hasAutopsy = (hasAutopsyStr == "true" || hasAutopsyStr == "1");

            getline(inFile, description);
            getline(inFile, line); // skip
            //make object 
            Person character(name, bloodType, item, isDead, hasAutopsy, description);
            //push object
            people.push_back(character);
        }
    }

    inFile.close();
    return people;
}

Player GameLoader::makePlayer(const string name,const string bloodType,const string item,const string description){
    //create an object and return 
    Player player(name, bloodType, item, description);
    //push to player vector in function called from
    return player;
}

vector<Autopsy> GameLoader::loadAutopies(const string& filename){
    vector<Autopsy>  autopsyReports;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line;
    while (getline(inFile, line)) {
        //Remove trailing whitespace (helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }
     
        string name, descript;
       
        getline(inFile, name);
        getline(inFile, descript);
        getline(inFile, line);
        //empty line read
        Autopsy autopsyReport(name, descript);
        autopsyReports.push_back(autopsyReport);

    }

    inFile.close();
    return autopsyReports;
}

vector<Ending> GameLoader::loadendings(const string& filename){
    vector<Ending>  storyEndings;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line;
    while (getline(inFile, line)) {
        //Remove trailing whitespace (helps match +tags better)
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
        }
        //we don't push white lines, it's just text file formatting
        string name, text, hp;
        int hpCap;

        getline(inFile, name);
        getline(inFile, text);
        getline(inFile, hp);
        getline(inFile, line);
        //empty line read

        Ending Ending(name, text, hpCap);
        storyEndings.push_back(Ending);

    }

    inFile.close();
    return storyEndings;

}

//Loader Central
GameData LoadFiles() {
    GameLoader DropDead;
    GameData data;

    vector<Player> players;

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

    data.personLibrary = DropDead.loadCharacters("src/person.txt", players);
    data.playerLibrary = players;



    return data;
}
