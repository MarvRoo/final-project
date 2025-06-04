#include "printer.h"
#include <iostream>

using namespace std;

void Printer::setGameData(const GameData& data){
    gameDataPtr = &data;
}

void Printer::printSearchItem(vector<Item *>* items){
    if (!items) return;

    for (Item* item : *items){
        if (item && item->isItemFound()){
            item->print();
            cout << endl;
        }
    }
}

void Printer::printAccessibleLocations(Player* player){
    vector<string>* roomListPtr = player->shareRoomListPtr(); 
    vector<string>* clueListPtr = player->shareClueListPtr();

    for (const string& roomName : *roomListPtr){
        for (const Location& loc : gameDataPtr->locationLibrary){
            if (loc.getName() == roomName){
                bool visited = false;
                
                for (const string& clue : *clueListPtr){ //if player's clue list has the keyClue, means player has visited location
                    if (clue == loc.getKeyClue()){
                        visited = true;
                        break;
                    }
                }
                cout << loc.getName() << " : " << (visited ? "Visited" : "Pending Visit") << endl;
                break; //location found, no more checking
            }
        }
    }
}

void Printer::printClues(vector<vector<string>>* clues){
    if (!clues) return;

    int segment = 1;
    for (const vector<string>& clueSegment : *clues){
        cout << "Clue(s) " << segment++ << " : " << endl;

        for (const string& clue : clueSegment){
            cout << " - " << clue << endl;
        }
        cout << endl;
    }

    //base case: When a clue is inspected it should be marked as so, a player should
    //know what clues they have already looked into
    //also find the clue itself and mark it as found
    //location only has a vector of names but those names range from just a clue to the 
    //subclass item or interview and they have they're own inspected
    
} 

void Printer::printPersonDetails(const string& personName){
    for (const Person& person : gameDataPtr->personLibrary){
        if (personName == person.getPersonName()){
            cout << "Name: " << personName << endl;
            cout << "Description: " << person.grabDescription() << endl;
            return;
        }
    }
}

void Printer::printEnd(const Ending& ending){
    for (const Ending& ending : gameDataPtr->endingsLibrary){
        cout << "Finale : " << ending.getSceneName() << endl;
        cout << ending.getStoryDescription() << endl;
        cout << "HP : " << ending.getHPCap() << endl;
    }
}

void Printer::findAutopsy(const string& characterName) const {
    if(!gameDataPtr){
        cout << "Error: Printer has no gameData set to find autopsy." << endl;
        return;
    }
    for(size_t i = 0; i < gameDataPtr->autopsyLibrary.size(); ++i){
        const Autopsy& currentAutopsy = gameDataPtr->autopsyLibrary[i];

        if(currentAutopsy.getCharacterName() == characterName){
            currentAutopsy.findAutopsies(characterName);
            return;
        }
    }
}
