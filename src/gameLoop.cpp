#include "gameLoop.h"
#include "gameLoader.h"
using namespace std;

void gameLoop::run(){
    GameData gameData = LoadFiles();
    if (gameData.playerLibrary.empty()) {
        throw runtime_error("No player...");
    }

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
    for (Location& loc : gameData.locationLibrary) {
        if (loc.getName() == locationName) {
            return &loc;
        }
    }
    return nullptr; // Not found
}

Day* gameLoop::findDay(int numDay){
    for (Day& day : gameData.dayLibrary) {
        if (day.getDay() == numDay) {
            return &day;
        }
    }
    return nullptr; // Not found
}

void gameLoop::unlockNextLocation(const string& locationName){
    Location* location = findLocation(locationName);
    if(location){
        //set to true so unlocked
        //needs a helper because a private variable can not be modified by force
        location->unlockLocation();
    }
    else{
        //shouldnt happen but heres the error
        cout << "Error: Location " << locationName << " not found." << endl;
    }
}

string gameLoop::goToLocation(const string& chosenLocationName) {
    // Only job here: validate the location, give clues if not already collected
    for (Location& loc : gameData.locationLibrary) {
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
    for(auto& clue : gameData.clueLibrary){
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


