#include "gameLoader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//marked red because location class constructor isnt fixed 
vector<Location> GameLoader::loadLocations(const string& filename) {
    vector<Location> locations;
    ifstream inFile("../src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        throw runtime_error("Failed to open dialogue in file: " + filename + "-Fix loadLocations");
    }

    string line, descript, name, ifLocked, keyClue;
    bool isLocked;

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

            Location place(name, descript, clues, isLocked, multiClue, keyClue);
            //const string& name, const string& description, vector <string> clueList, bool accessible, bool multiple, string keyClue
            locations.push_back(place);
        } else {
            //Fallback to normal item
            bool multiClue = false;
            //single clue locations mean that keyclue is both the first line
            getline(inFile, line);
            getline(inFile, descript);
            getline(inFile, name);
            getline(inFile, ifLocked);
            getline(inFile, keyClue);
            getline(inFile, line); // read empty line

            isLocked = (ifLocked == "true" || ifLocked == "1");

            //uncomment when classes merged
            Location place(name, descript, isLocked, multiClue, keyClue);
            locations.push_back(place);
        }
    }

    inFile.close();
    return locations;
}

//converter catcher needed 
vector<unique_ptr<Clue>> GameLoader::loadClues(const string& fileItems, const string& fileClues){
    //seperated files since formatting varies greatly between string clues and item clues
    vector<unique_ptr<Clue>> clues;

    // Load item clues
    ifstream itemFile("../src/game_text_files/" + fileItems);
    if (!itemFile.is_open()) {
        throw runtime_error("Failed to open item clue file: " + fileItems + "-fix loadClues");
    }

    //loop for reading item text file first 
    string line, name, hasBlood, bloodType, hasfingerPrints, whoTouched, location, descrip, isFound, itemID;
    int clueID;
    bool ifBlood, ifFingerPrints, ifFound;
    while (getline(itemFile, name)) {
        getline(itemFile, hasBlood);
        getline(itemFile, bloodType);
        getline(itemFile, hasfingerPrints);
        getline(itemFile, whoTouched);
        getline(itemFile, location);
        getline(itemFile, descrip);
        getline(itemFile, isFound);
        getline(itemFile, itemID);
        //empty line
        getline(itemFile, line);

        // Convert required values
        try {
        clueID = stoi(itemID);
        } catch (const invalid_argument& e) {
            throw runtime_error("Invalid CLUEID value in ending file: [" + itemID + "] is not a number. Found in reading items.");
        }
        bool ifBlood = (hasBlood == "true");
        bool ifFingerPrints = (hasfingerPrints == "true");
        bool ifFound = (isFound == "true");

        // Construct item (assumes Item inherits from Clue and has appropriate constructor)
        //Item::Item(const string& name, bool hasBlood, const string& bloodType,  bool fingerPrint, const string& whoseFingerprint, const string& itemLocation, const string& itemDescrip, bool itemFound, int clueID) 
        try {
            auto item = make_unique<Item>(name, ifBlood, bloodType, ifFingerPrints, whoTouched, location, descrip, ifFound, clueID);
            clues.push_back(std::move(item));
        } catch (const bad_alloc&) {
            throw runtime_error("Memory allocation failed while loading item clue: " + name);
        }
    }

    itemFile.close();

    string clueText;
    // Load string clues
    ifstream clueFile("../src/game_text_files/" + fileClues);
    if (!clueFile.is_open()) {
        throw runtime_error("Failed to open clue text file: " + fileClues + "-fix loadClues");
    }

    while (getline(clueFile, line)) {
        if (line == "+Clue") {

            getline(clueFile, clueText); // The clue string
            getline(clueFile, itemID);   // #clueID
            getline(clueFile, line);     // +end

            if (line != "+end") {
                throw runtime_error("Expected +end after clue text");
            }
            //convert clueID
            try {
            clueID = stoi(itemID);
            } catch (const invalid_argument& e) {
                throw runtime_error("Invalid CLUEID value in ending file: [" + itemID + "] is not a number. Found readings clues.");
            }
            
            try {
                auto clue = make_unique<Clue>(clueID, clueText);
                clues.push_back(std::move(clue));
            } catch (const bad_alloc&) {
                throw runtime_error("Memory allocation failed while loading clue ID: " + itemID);
            }
        }

        else if (line == "+Interview") {
            vector<string> lines;

            // Read all lines until +end
            while (getline(clueFile, line) && line != "+end") {
                lines.push_back(line);
            }

            // After +end, get the clue ID
            getline(clueFile, itemID); // #clueID
            try {
            clueID = stoi(itemID);
            } catch (const invalid_argument& e) {
                throw runtime_error("Invalid CLUEID value in ending file: [" + itemID + "] is not a number. Found in reading interviews.");
            }

            // Construct interview
            try {
                auto interview = make_unique<Interview>(lines, clueID);
                clues.push_back(std::move(interview));
            } catch (const bad_alloc&) {
                throw runtime_error("Memory allocation failed while loading interview ID: " + itemID);
            }
        }
    }
    
    clueFile.close();

    return clues;

}

map<string, vector<unique_ptr<DialogueUnit>>> GameLoader::loadDialogue(vector<string>& DialogueFiles){
    map<string, vector<unique_ptr<DialogueUnit>>> dialogueMap;

    for (const string& file : DialogueFiles) {
        ifstream inFile("../src/game_text_files/" + file);
        if (!inFile.is_open()) {
            throw runtime_error("Failed to open dialogue file: " + file + " -fix dialogue");
        }

        string line;
        string currentMappingName;
        //we'll pass these into the constructor
        vector<string> dialogueLines;

        while (getline(inFile, line)) {
            size_t end = line.find_last_not_of(" \t\r\n");
            if (end != string::npos) {
                line.erase(end + 1); // trims trailing whitespace
            } else {
                line.clear(); // the line is all whitespace, so make it an empty string
            }


            if (line.empty()){
                //empty lines are part of dialogue output formatting
                dialogueLines.push_back(line);
            }

            //Done with textfile
            if (line == "+doneReading"){
                //we want to push this edge, it's an exeption
                //Read the next two lines 
                dialogueLines.push_back(line);

                getline(inFile, line);
                dialogueLines.push_back(line);
                getline(inFile, line);
                dialogueLines.push_back(line);

                // Push any remaining dialogue for the current mapping
                if (!dialogueLines.empty() && !currentMappingName.empty()) {
                    try {
                        dialogueMap[currentMappingName].emplace_back(make_unique<Dialogue>(dialogueLines));
                    } catch (const bad_alloc&) {
                        throw runtime_error("Memory allocation failed while loading dialogue at +done: " + currentMappingName);
                    }
                    dialogueLines.clear();
                    currentMappingName.clear();
                }
                return dialogueMap;
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
                    if (!dialogueLines.empty()) {
                        try {
                            dialogueMap[currentMappingName].emplace_back(make_unique<Dialogue>(dialogueLines));
                        } catch (const bad_alloc&) {
                            throw runtime_error("Memory allocation failed while loading dialogue at +mapping: " + currentMappingName);
                        }
                        dialogueLines.clear();
                        currentMappingName.clear();
                    }
                    currentMappingName = line;
                }
            }


            // Choice with 2 options
            string choiceMapName;
            if (line == "+Choice2{" || line == "-Choice2{") {
                bool negValue = (line[0] == '-');
                string opt1, opt2;
                int j1 = 0, j2 = 0;

                if (getline(inFile, opt1) &&
                    getline(inFile, line)) {

                    // Clean line and convert safely
                    line.erase(line.find_last_not_of(" \t\r\n") + 1);
                    try {
                        j1 = stoi(line);
                    } catch (const invalid_argument&) {
                        throw runtime_error("Invalid score for Choice2 option 1: '" + line + "'");
                    }

                    if (getline(inFile, opt2) &&
                        getline(inFile, line)) {

                        line.erase(line.find_last_not_of(" \t\r\n") + 1);
                        try {
                            j2 = stoi(line);
                        } catch (const invalid_argument&) {
                            throw runtime_error("Invalid score for Choice2 option 2: '" + line + "'");
                        }

                        vector<pair<string, int>> options = {
                            {opt1, j1},
                            {opt2, j2}
                        };

                        getline(inFile, line); // skip +end}
                        getline(inFile, line); // check for +mappingName
                        line.erase(line.find_last_not_of(" \t\r\n") + 1);

                        if (line == "+mappingName") {
                            getline(inFile, choiceMapName);
                            choiceMapName.erase(choiceMapName.find_last_not_of(" \t\r\n") + 1);
                        }

                        try {
                            auto choice = make_unique<Choice>(options, negValue);
                            if (choiceMapName.empty()) {
                                throw std::runtime_error("Missing +mappingName after choice block. Cannot insert Choice.");
                            }
                            dialogueMap[choiceMapName].emplace_back(std::move(choice));
                        } catch (const bad_alloc&) {
                            throw runtime_error("Memory allocation failed while loading choice block 2 in dialogue");
                        }
                    }
                }

            }else if (line == "+Choice3{" || line == "-Choice3{") {
                //looks crazy I know 
                bool negValue = (line[0] == '-');
                string opt1, opt2, opt3;
                int j1 = 0, j2 = 0, j3 = 0;

                if (getline(inFile, opt1) &&
                    getline(inFile, line)) {

                    line.erase(line.find_last_not_of(" \t\r\n") + 1);
                    try {
                        j1 = stoi(line);
                    } catch (const invalid_argument&) {
                        throw runtime_error("Invalid score for Choice3 option 1: '" + line + "'");
                    }

                    if (getline(inFile, opt2) &&
                        getline(inFile, line)) {

                        line.erase(line.find_last_not_of(" \t\r\n") + 1);
                        try {
                            j2 = stoi(line);
                        } catch (const invalid_argument&) {
                            throw runtime_error("Invalid score for Choice3 option 2: '" + line + "'");
                        }

                        if (getline(inFile, opt3) &&
                            getline(inFile, line)) {

                            line.erase(line.find_last_not_of(" \t\r\n") + 1);
                            try {
                                j3 = stoi(line);
                            } catch (const invalid_argument&) {
                                throw runtime_error("Invalid score for Choice3 option 3: '" + line + "'");
                            }

                            vector<pair<string, int>> options = {
                                {opt1, j1},
                                {opt2, j2},
                                {opt3, j3}
                            };

                            getline(inFile, line); // skip +end}
                            getline(inFile, line); //should read mapping
                            line.erase(line.find_last_not_of(" \t\r\n") + 1);

                            if (line == "+mappingName") {
                                getline(inFile, choiceMapName);
                                choiceMapName.erase(choiceMapName.find_last_not_of(" \t\r\n") + 1);
                            }

                            try {
                                auto choice = make_unique<Choice>(options, negValue);
                                dialogueMap[choiceMapName].emplace_back(std::move(choice));
                            } catch (const bad_alloc&) {
                                throw runtime_error("Memory allocation failed while loading choice 3 block in dialogue");
                            }

                        }
                    }
                }
                
            }else {
                //if not a choice block then continue to push all strings even empty to dialogueLines vector
                dialogueLines.push_back(line);
            }
        }
        //moving to next textfile
        inFile.close();
    }
    //return map should be when donereading is read 
    //but as a failure backup the line is here
    return dialogueMap;
}


//incomplete
vector<Day> GameLoader::loadDays(const string& filename){
    vector<Day> days;
    ifstream inFile("../src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        throw runtime_error("Failed to open dialogue file: " + filename + "-fix loadDays");
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
                //stoi is changing string to int might need a throw error hear to catch
            }
        }

        // Convert required values
        int dayNumber;
        try {
        dayNumber = stoi(dayNum);
        } catch (const invalid_argument& e) {
            throw runtime_error("Invalid CLUEID value in ending file: [" + dayNum + "] is not a number.");
        }
        bool nightBool = (night == "true");
        bool eveningBool = (evening == "true");
        bool morningBool = (morning == "true");
        bool cluesFound = (allCluesFound == "true");
        bool dayLocked = (isLocked == "true");

        days.emplace_back(Day(dayNumber, morningBool, eveningBool, nightBool, cluesFound, dayLocked, clues));
    }

    inFile.close();
    return days;
}

//checkpoints +player and +end used in txt file
//read from the same text file
vector<Person> GameLoader::loadCharacters(const string& filename, vector<Player> &players){
    vector<Person> people;
    ifstream inFile("../src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename + "-fix loadChars");
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

            //conversion

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
    ifstream inFile("../src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename  + "-fix loadAutopsies");
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
    ifstream inFile("../src/game_text_files/" + filename);

    if (!inFile.is_open()) {
        //debug error if file is not open
        throw runtime_error("Failed to open dialogue file: " + filename + "-fix loadends");
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

        //convert string hp into int for hpCap
        //write a throw error when stoi fails.
        try {
        hpCap = stoi(hp);
        } catch (const invalid_argument& e) {
            throw runtime_error("Invalid HP value in ending file: [" + hp + "] is not a number.");
        } catch (const std::out_of_range& e) {
            throw runtime_error("HP value out of range in ending file: [" + hp + "].");
        }

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

    //for now only test first day
    vector<string> DialogueFiles = {"day1Morning.txt", "day1Evening.txt","day1Night.txt"};

    /*"day2Morning.txt", "day2Evening.txt", "day2Night.txt", "day3Morning.txt", "day3Evening.txt",
    "day3Night.txt"};*/
    //read all file names and push contents to DialogueFiles
    

    data.locationLibrary = DropDead.loadLocations("locations.txt");
    //double file reader
    data.clueLibrary = DropDead.loadClues("item.txt","clue.txt" );
    //multi-file reader +2
    data.gameDialogue = DropDead.loadDialogue(DialogueFiles);
    data.autopsyLibrary = DropDead.loadAutopies("autopsies.txt");
    data.dayLibrary = DropDead.loadDays("days.txt");
    data.endingsLibrary = DropDead.loadendings("ending.txt");

    //reference vector
    data.personLibrary = DropDead.loadCharacters("person.txt", players);
    data.playerLibrary = players;



    return data;
}
