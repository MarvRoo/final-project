#include "gameLoop.h"
#include "gameLoader.h"
using namespace std;

void gameLoop::run(){
    GameData gameData = LoadFiles();
    if (gameData.playerLibrary.empty()) {
        throw runtime_error("No player...");
    }
    setInternalData(&gameData);

    Player* playerPtr = &gameData.playerLibrary[0];

    // Create shared Interface object
    shared_ptr<Interface> interface = make_shared<Interface>();
    Printer printer;

    // Configure Printer
    printer.setGameData(&gameData);
    printer.setplayer(playerPtr);

    // Set printer in interface
    interface->setPrinter(&printer);

    // Set player for other logic
    setPlayer(playerPtr);

    // Loop through game dialogue using preserved order
    for (const string& key : gameData.dialogueKeyOrder) {
        auto it = gameData.gameDialogue.find(key);
        if (it != gameData.gameDialogue.end()) {
            const auto& dialogueList = it->second;

            cout << "---- Entering Scene: " << key << " ----" << endl;

            for (const auto& dialogueUnitPtr : dialogueList) {
                if (dialogueUnitPtr) {
                    dialogueUnitPtr->setInterface(interface);
                    //shared pointer passed safer
                    dialogueUnitPtr->setGameLoop(this);
                    dialogueUnitPtr->print();
                }
            }

            cout << "------------------------------" << endl;
        } else {
            cerr << "Warning: Key '" << key << "' not found in gameDialogue map!" << endl;
        }
    }

    // Print the keys in gameDialogueLibrary
    /*cout << "Dialogue Keys in Order:\n";
    for (const auto& pair : gameData.gameDialogue) {
        cout << "- " << pair.first << endl;
    }

    cout << "Testing dialogue key order:" << endl;
    for (const string& key : gameData.dialogueKeyOrder) {
        cout << "- " << key << endl;
    }*/
    
}

Location* gameLoop::findLocation(string locationName){
    for (Location& loc : libraries->locationLibrary) {
        if (loc.getName() == locationName) {
            return &loc;
        }
    }
    throw runtime_error("findLocation failed to return a proper pointer");
}

Day* gameLoop::findDay(int numDay){
    for (Day& day : libraries->dayLibrary) {
        if (day.getDay() == numDay) {
            return &day;
        }
    }
    return nullptr; // Not found
}

void gameLoop::unlockNextLocation(const string& locationName){
    Location* location = findLocation(locationName);

    if (location) {
        // Unlock the location itself
        location->unlockLocation();
        cout << "Unlocked new location: " << locationName << endl << endl;

        // Add location name to player's unlocked room list
        if (playerPtr) {
            playerPtr->addUnlockedRoom(locationName);
            cout << "Added to player's unlocked room list: " << locationName << endl;
        } else {
            cerr << "Error: playerPtr is null in unlockNextLocation()." << endl;
        }

    } else {
        cerr << "Error: Location " << locationName << " not found. Failed in gameLoop." << endl;
    }
}

string gameLoop::goToLocation(const string& chosenLocationName) {
    // Only job here: validate the location, give clues if not already collected
    for (Location& loc : libraries->locationLibrary) {
        if (loc.getName() == chosenLocationName) {
            if (!loc.checkkeyClueFound()) {
                vector<string> clues = loc.getClues();
                for (const string& clue : clues) {
                    playerPtr->addNewClues(clue);
                }
                loc.markClueFound();
                //marks that the locations key item has been found
            } else {
                //only if the keyitem in the location is already found
                cout << "Hmmm there's no new clues to collect in " << chosenLocationName << "." << endl;
            }
            return chosenLocationName;
        }
    }

    cout << "Error: Location " << chosenLocationName << " not found." << endl;
    return "";
}

void gameLoop::acquireNewClue(const string& clueName){
    //fixed the copy change
    for(auto& clue : libraries->clueLibrary){
        if(clue->getName() == clueName){
            playerPtr->addNewClues(clueName);
            return; 
        }
    }
    //shouldn't happen
    cout << "Error: Clue " << clueName << " not found." << endl;
}

//revisit
void gameLoop::changeDayTime(int dayNum, const string& currentTime){
    //im not sure whats going on here
    //your suppose to search the library for days already made
    //specifically dayNum which is limited to 1, 2, 3
    //then using the currentTime to set that bool to false and the next one that comes after should be 
    //true 
    Day* day = findDay(dayNum);
    if (currentTime == "Night"){
        if(dayNum < 3){
            //we only have three days so if the day is either day 1 or 2 and the currentTime is Night
            //we need to set the nextDay's Morning to true
            Day* nextDay = findDay(dayNum+1);
            nextDay->changeDay("NEXTDAYTRUE");
        }
    }
    if(day){
        day->changeDay(currentTime);
    }
    else{
        //shouldnt happen ever
        cout << "Error: Day " << dayNum << "not found" << endl;
    }
}

void gameLoop::playerChoices(int hpUpdate, bool subtract){
    if(subtract){
        playerPtr->upDateHp(-hpUpdate);
        return;
    }
    playerPtr->upDateHp(hpUpdate);
}

bool gameLoop::cluesMatch(int numDay){
    vector<int> clueIDs;  // Final result to return

    // Get the player's collected clue names
    vector<string>* clueNames = playerPtr->shareClueListPtr();

    // Loop through each clue name the player has
    for (const auto& clueName : *clueNames) {
        // Search the master clue library for a match
        for (const auto& clue : libraries->clueLibrary) {
            if (clue->getName() == clueName) {
                clueIDs.push_back(clue->getID());  // Add matching clue ID
                break;  // Stop searching after the first match
            }
        }
    }

    //use clueIDs vector
    //Iterate through day library for a day with a true in either morning, evening or night
    // Use clueIDs vector to check days
        // Search only for the specific day number
    for (auto& day : libraries->dayLibrary) {
        if (day.getDay() == numDay) {
            if (day.isMorning() || day.isEvening() || day.isNight()) {
                if (day.isDayComplete(clueIDs)) {
                    cout << "\nDay " << day.getDay() << ": You found all the clues to move on!\n" << endl;
                    return true;
                } else {
                    cout << "\nMmm... looks like you might have missed some clues. Visit locations you haven't been to...\n";
                    return false;
                }
            }
        }
    }

    // If day not found or not active
    cout << "\nNo active time segment found for Day " << numDay << ".\n";
    return false;


}