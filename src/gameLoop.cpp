#include "gameLoop.h"
using namespace std;

void gameLoop::run(){
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
            return 
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
        day->Night = (currentTime == "Night");
        //so if night all are false now since now we're day 2
        day->Evening = (currentTime == "Evening");
        //night is true and evening false
        day->Morning = (currentTime == "Morning");
        //morning is false and evening true
    }
    else{
        //shouldnt happen but good to have the error check
        cout << "Error: Day " << dayNum << " not found." << endl;
    }
}

