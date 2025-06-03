#include "gameLoop.h"
using namespace std;

void gameLoop::run(){
    gameData = LoadFiles();
    interface.setGameData(gameData);
    printer.setGameData(gameData);
}

void gameLoop::unlockNextLocation(const string& locationName){
    Location* location = findLocation(locationName);
    if(location){
        location->isAccessible = true;
        cout << "Unlocked location: " << locationName << endl;
    }
    else{
        cout << "Error: Location " << locationName << "not found." << endl;
    }
}

string gameLoop::goToLocation(){
    cout << "Available Locations:" << endl;
    vector<Location*> accessibleLocations;
    for(int i = 0; i < gameData.locationLibrarysize(); ++i){
        if(gameData.locationLibrary[i].checkUnlock()){
            cout << "- " << gameData.locationLibrary[i].name << endl;
            accessibleLocations.push_back(&gameData.locationLibrary[i]);
        }
    }
    if(accessibleLocations.empty()){
        cout << "No accessible locations." << endl;
        return "";
    }
    
    int choice;
    cout << "Enter the name of the location you want to go to: ";
    string chosenLocationName;
    cin >> chosenLocationName;

    for(int i = 0; i < accessibleLocation.size(); ++i){
        if(accessibleLocations[i]->name == chosenLocationName){
            cout << "Going to: " << chosenLocationName << endl;
            return chosenLocationName;
        }
    }
    cout << "Invalid location choice." << endl;
    return "";
}

string gameLoop::goToLocation(const string& requiredLocation){
    cout << "Going to: " << requiredLocation << endl;
    return requiredLocation;
}

void gameLoop::acquireNewClue(const string& clueName){
    for(int i = 0; i < gameData.clueLibrary.size(); ++i){
        if(gameData.clueLibrary[i]->name == clueName){
            playerPtr->clueList.push_back(gameData.clueLibrary[i]->ClueId);
            cout << "Acquired clue: " << clueName << endl;
            return 
        }
    }
    cout << "Error: Clue " << clueName << "not found." << endl;
}

void gameLoop::changeDayTime(int dayNum, const string& currentTime, bool isChoice){
    Day* day = findDay(dayNum);
    if(day){
        day->Night = (currentTime == "Night");
        day->Evening = (currentTime == "Evening");
        day->Morning = (currentTime == "Morning");
    }
    cout << "Time progressed to Day " << dayNum << ", " << currentTime << endl;
    else{
        cout << "Error: Day " << dayNum << " not found." << endl;
    }
}

