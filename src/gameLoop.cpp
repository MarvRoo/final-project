#include "gameLoop.h"
using namespace std;

void gameLoop::run(){
    gameLoader loader;
    gameData = LoadFiles();
    interface.setGameData(gameData);
    printer.setGameData(gameData);

    //iterate through the   map<string, vector<unique_ptr<DialogueUnit>>> gameDialogue library
    //that library not only holds dialogue but is the game flow 
}

void gameLoop::unlockNextLocation(const string& locationName){
    Location* location = findLocation(locationName);
    if(location){
        //set to true so unlocked
        location->isAccessible = true;
    }
    else{
        //shouldnt happen but heres the error
        cout << "Error: Location " << locationName << "not found." << endl;
    }
}

string gameLoop::goToLocation(){
    //showing the choices is interface
    //if the location already has its keyitemfound that means we already visited
    //special case where you can say "Already visited location. No new clues found here"
    //otherwise dont say anuthing and clues so the function 
    //call your acquire clues 

    vector<Location*> accessibleLocations;
    for (int i = 0; i < gameData.locationLibrary.size(); ++i) {
    if (gameData.locationLibrary[i].checkUnlock()) {
        accessibleLocations.push_back(&gameData.locationLibrary[i]);
    }
    }

    if (accessibleLocations.empty()) {
        cout << "No accessible locations." << endl;
        return "";
     }
    cout << "Available Locations:" << endl;
    for (size_t i = 0; i < accessibleLocations.size(); ++i) {
        cout << i + 1 << ". " << accessibleLocations[i]->name << endl;
    }
    string chosenLocationName;
    int choice;
    cout << "Enter the number of the location you want to go to: ";
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cout << "Invalid input." << endl;
        return "";
    }

    if (choice > 0 && choice <= accessibleLocations.size()) {
        chosenLocationName = accessibleLocations[choice - 1]->name;
    } else {
        cout << "Invalid choice." << endl;
        return "";
    }

    Location* chosenLocation = findLocation(chosenLocationName);
    if (chosenLocation) {
    if (chosenLocation->keyItemFound) {
        cout << "Already visited " << chosenLocationName << ". No new clues found here." << endl;
    } else {
    for (const string& clueName : chosenLocation->clueList) {
        acquireNewClue(clueName);
    }
    chosenLocation->keyItemFound = true;
    }
    return chosenLocationName;
    } else {
        cout << "Error: Could not find location " << chosenLocationName << endl;
        return "";
    }
}

string gameLoop::goToLocation(const string& requiredLocation){
    cout << "Going to: " << requiredLocation << endl;
    return requiredLocation;
}

void gameLoop::acquireNewClue(const string& clueName){
    for(int i = 0; i < gameData.clueLibrary.size(); ++i){
        //checking if it exists okay good
        if(gameData.clueLibrary[i]->name == clueName){
            //not id, id is an int
            playerPtr->clueList.push_back(gameData.clueLibrary[i]->name);
            return; 
        }
    }
    cout << "Error: Clue " << clueName << "not found." << endl;
}

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


