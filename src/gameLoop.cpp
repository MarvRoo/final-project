#include "gameLoop.h"
#include "gameLoader.h"
using namespace std;

void gameLoop::run(){
    GameData gameData = LoadFiles();
    interface.setGameData(gameData);
    printer.setGameData(gameData);

    //iterate through the   map<string, vector<unique_ptr<DialogueUnit>>> gameDialogue library
    //that library not only holds dialogue but is the game flow 
}

Location* gameLoop::findLocation(string locationName){
    for (Location& loc : gameData.locationLibrary) {
        if (loc.getName() == locationName) {
            return &loc;
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
        cout << "Error: Location " << locationName << "not found." << endl;
    }
}

string gameLoop::goToLocation(const string& chosenLocationName){
    //first grab the only player in our library
    vector<string>* playerLocations = playerPtr->shareRoomListPtr();

    //check that we found the valid location and that the player has not found the keyclue in that location
    for (const string& roomName : *playerLocations) {
        for (Location& loc : gameData.locationLibrary) {
            if (loc.getName() == roomName && loc.checkkeyClueFound() == false) {
                //then add the locations cluelist to players clue list;

            }else{
                cout << "Hmmm there's no new clues to collect in " << chosenLocationName << endl;
            }
        }
    }
}

void gameLoop::acquireNewClue(const string& clueName){
    Player player = gameData.playerLibrary[0];
    for(int i = 0; i < gameData.clueLibrary.size(); ++i){
        //checking if it exists okay good
        if(gameData.clueLibrary[i]->getName() == clueName){
            //not id, id is an int
            playerPtr->addNewClues(clueName);
            return; 
        }
    }
    cout << "Error: Clue " << clueName << "not found." << endl;
}

//revisit
void gameLoop::changeDayTime(int dayNum, const string& currentTime){
    //im not sure whats going on here
    //your suppose to search the library for days already made
    //specifically dayNum which is limited to 1, 2, 3
    //then using the currentTime to set that bool to false and the next one that comes after should be 
    //true 
    Day* day = findDay(dayNum);
    if(day){
        day->Night = false;
        day->Evening = false;
        day->Morning = false;

    if(currentTime == "Night"){
        day->Night = true;
    }
    else if(currentTime == "Evening"){
        day->Evening = true;
    }
    else if(currentTime == "Morning"){
        day->Morning = true;
    }
    }
    else{
        //shouldnt happen but good to have the error check
        cout << "Error: Day " << dayNum << " not found." << endl;
    }
}


