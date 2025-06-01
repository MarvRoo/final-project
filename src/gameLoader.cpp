#include "gameLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//marked red because location class constructor isnt fixed 
vector<Location> GameLoader::loadLocations(const string& filename) {
    vector<Location> locations;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line, descript, name, ifLocked, itemFound, keyClue;
    bool isLocked, isFound;

    while (getline(inFile, line)) {
        if (!line.empty()) {
            line.erase(line.find_last_not_of(" \t\r\n") + 1); // trim trailing
        }

        if (line.find("+multi-item") != string::npos) {
            bool multiClue = true;
            vector<string> clues;
            string clue;

            // Read clues until "+end"
            while (getline(inFile, clue)) {
                if (clue == "+end") break;
                clues.push_back(clue);
            }

            getline(inFile, descript);
            getline(inFile, name);
            getline(inFile, ifLocked);
            getline(inFile, keyClue);
            getline(inFile, line); //read empty line

            isLocked = (ifLocked == "true" || ifLocked == "1");
            isFound = (itemFound == "true" || itemFound == "1");

            Location place(name, descript, clues, isLocked, multiClue, keyClue);
            //const string& name, const string& description, vector <string> clueList, bool accessible, bool multiple, string keyClue
            locations.push_back(place);
        } else {
            //Fallback to normal item
            bool multiClue = false;
            getline(inFile, descript);
            getline(inFile, name);
            getline(inFile, ifLocked);
            getline(inFile, keyClue);
            getline(inFile, line); // read empty line

            isLocked = (ifLocked == "true" || ifLocked == "1");
            isFound = (itemFound == "true" || itemFound == "1");

            //uncomment when classes merged
            Location place(name, descript, isLocked, multiClue, keyClue);
            locations.push_back(place);
        }
    }

    inFile.close();
    return locations;
}

//Incomplete loadClues
vector<unique_ptr<Clue>> GameLoader::loadClues(const string& fileItems, const string& fileClues){
    //seperated files since formatting varies greatly between string clues and item clues
    vector<unique_ptr<Clue>> clues;

    // Load item clues
    ifstream itemFile("src/game_text_files/" + fileItems);
    if (!itemFile.is_open()) {
        throw runtime_error("Failed to open item clue file: " + fileItems);
    }

    string line;
    while (getline(itemFile, line)) {
        string name = line;

        string clueText;
        getline(itemFile, clueText); // The clue text

        string clueID;
        getline(itemFile, clueID);   // #clueID line

        // Construct item (assumes Item inherits from Clue and has appropriate constructor)
        //Item::Item(const string& name, bool hasBlood, const string& bloodType,  bool fingerPrint, const string& whoseFingerprint, const string& itemLocation, const string& itemDescrip, bool itemFound, int clueID) 
        auto item = make_unique<Item>(name, clueText, clueID);
        clues.push_back(std::move(item));
    }

    itemFile.close();

    // Load string clues
    ifstream clueFile("src/game_text_files/" + fileClues);
    if (!clueFile.is_open()) {
        throw runtime_error("Failed to open clue text file: " + fileClues);
    }

    while (getline(clueFile, line)) {
        if (line == "+Clue") {
            string clueText, clueID;

            getline(clueFile, clueText); // The clue string
            getline(clueFile, clueID);   // #clueID
            getline(clueFile, line);     // +end

            if (line != "+end") {
                throw runtime_error("Expected +end after clue text");
            }

            auto clue = make_unique<Clue>(clueText, clueID);
            clues.push_back(std::move(clue));
        }

        else if (line == "+Interview") {
            vector<string> lines;

            // Read all lines until +end
            while (getline(clueFile, line) && line != "+end") {
                lines.push_back(line);
            }

            // After +end, get the clue ID
            string clueID;
            getline(clueFile, clueID); // #clueID

            // Construct interview
            auto interview = make_unique<Interview>(lines, clueID);
            clues.push_back(std::move(interview));
        }
    }
    
    clueFile.close();

    return clues;

}

map<string, vector<unique_ptr<DialogueUnit>>> GameLoader::loadDialogue(vector<string>& DialogueFiles){
    map<string, vector<unique_ptr<DialogueUnit>>> dialogueMap;

    for (const string& file : DialogueFiles) {
        ifstream inFile("src/game_text_files/" + file);
        if (!inFile.is_open()) {
            throw runtime_error("Failed to open dialogue file: " + file);
        }

        string line;
        string currentMappingName;
        //we'll pass these into the constructor
        vector<string> dialogueLines;

        while (getline(inFile, line)) {
            if (!line.empty()) {
                line.erase(line.find_last_not_of(" \t\r\n") + 1);
            }

            if (line.empty()){
                //empty lines are part of dialogue output formatting
                dialogueLines.push_back(line);
            }

            //Done with textfile
            if (line == "+doneReading"){
                break;
            }

            //Start new mapping group
            if (line == "+mappingName") {
                if (getline(inFile, line)) {
                    line.erase(line.find_last_not_of(" \t\r\n") + 1);
                    /*Program:
                        check if dialogueLines vector isn't empty before we change mapping name
                        if not empty then use the the currentMappingName to push into map<string, vector<unique_ptr<DialogueUnit>>>
                        we would call the dialogue constructor with the parameter of dialogueLines to make the object
                        push that object in and then clear the dialogueLines vector to reuse aswell as currentMappingName
                    */
                    if (!dialogueLines.empty() && !currentMappingName.empty()) {
                        //Push Dialogue object with its designated mapping name to dialogueMap for the Game dialogue Library
                        dialogueMap[currentMappingName].emplace_back(make_unique<Dialogue>(dialogueLines));
                        //clear vector
                        dialogueLines.clear();
                        //clear string
                        currentMappingName.clear();
                    }
                    currentMappingName = line;
                }
            }

            // Choice with 2 options
            if (line == "+Choice2{") {
                string opt1, opt2;
                int j1 = 0, j2 = 0;

                if (getline(inFile, opt1) &&
                    getline(inFile, line) && (j1 = stoi(line)) &&
                    getline(inFile, opt2) &&
                    getline(inFile, line) && (j2 = stoi(line))) {

                    vector<pair<string, int>> options = {
                        {opt1, j1},
                        {opt2, j2}
                    };

                    //call choice constructor 
                    //push constructed choice to vector map<string, vector<unique_ptr<DialogueUnit>>> dialogueMap;
                    //we should already have the mapping name associated to this push
                    dialogueMap[currentMappingName].emplace_back(make_unique<Choice>(options)); 

                }
                //end of reading a choice object
                getline(inFile, line); // +end}

            }else if (line == "+Choice3{") {
                // Choice with 3 options
                string opt1, opt2, opt3;
                int j1 = 0, j2 = 0, j3 = 0;

                if (getline(inFile, opt1) &&
                    getline(inFile, line) && (j1 = stoi(line)) &&
                    getline(inFile, opt2) &&
                    getline(inFile, line) && (j2 = stoi(line)) &&
                    getline(inFile, opt3) &&
                    getline(inFile, line) && (j3 = stoi(line))) {

                    vector<pair<string, int>> options = {
                        {opt1, j1},
                        {opt2, j2},
                        {opt3, j3}
                    };

                    //call choice constructor 
                    //push constructed choice to vector map<string, vector<unique_ptr<DialogueUnit>>> dialogueMap;
                    //we should already have the mapping name associated to this push
                    dialogueMap[currentMappingName].emplace_back(make_unique<Choice>(options));
                    
                }
                //end of reading a choice object
                getline(inFile, line); // +end}
            }else {
                //if not a choice block then continue to push all strings even empty to dialogueLines vector
                dialogueLines.push_back(line);
            }
        }

        inFile.close();
    }

    return dialogueMap;

}


//incomplete
vector<Day> GameLoader::loadDays(const string& filename){
    vector<Day> days;
    ifstream inFile("src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        throw runtime_error("Failed to open dialogue file: " + filename);
    }

    string line, dayNum, night, evening, morning, isLocked, allCluesFound, clue;
    while (getline(inFile, dayNum)) {
        // Skip empty lines
        if (dayNum.empty()) continue;

        getline(inFile, morning);
        getline(inFile, evening);
        getline(inFile, night);
        getline(inFile, isLocked);
        getline(inFile, allCluesFound);

        // Expect +clues line next
        while (getline(inFile, line) && line != "+clues") {
            if (line.empty()) continue;
        }

        vector<int> clues;
        while (getline(inFile, clue)) {
            if (clue == "+end") break;
            if (!clue.empty()) {
                clues.push_back(stoi(clue));
                //stoi is changing string to int
            }
        }

        // Convert required values
        int dayNumber = stoi(dayNum);
        bool nightBool = (night == "true");
        bool eveningBool = (evening == "true");
        bool morningBool = (morning == "true");

        Day day(dayNumber, nightBool, eveningBool, morningBool, clues);
        days.push_back(day);
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
        //example: "Hello world   " will still be recognized as "Hello world"
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

//hp converted to int 
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
    

    data.locationLibrary = DropDead.loadLocations("src/locations.txt");
    //double file reader
    data.clueLibrary = DropDead.loadClues("src/items.txt","src/clue.txt" );
    //multi-file reader +2
    data.gameDialogue = DropDead.loadDialogue(DialogueFiles);
    data.autopsyLibrary = DropDead.loadAutopies("src/autopsies.txt");
    data.dayLibrary = DropDead.loadDays("src/days.txt");
    data.endingsLibrary = DropDead.loadendings("src/endings.txt");

    //reference vector
    data.personLibrary = DropDead.loadCharacters("src/person.txt", players);
    data.playerLibrary = players;



    return data;
}
