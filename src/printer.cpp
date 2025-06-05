#include "printer.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Printer::printSearchItems() {
    if (!gameLibraryPtr) {
        throw runtime_error("Game data not set.");
    }

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        Item* item = dynamic_cast<Item*>(cluePtr.get());
        if (item) {
            cout << "- " << item->getName() << endl;
        }
    }

    cout << "---------------------" << endl;
}

int Printer::printAccessibleLocations() {
    if (!playerPtr || !gameLibraryPtr) {
        throw runtime_error("Player or Game data not set.");
    }

    vector<string>* roomListPtr = playerPtr->shareRoomListPtr(); 
    vector<string>* clueListPtr = playerPtr->shareClueListPtr();

    for (const string& roomName : *roomListPtr) {
        for (const Location& loc : gameLibraryPtr->locationLibrary) {
            if (loc.getName() == roomName) {
                bool visited = false;
                for (const string& clue : *clueListPtr) {
                    if (clue == loc.getKeyClue()) {
                        visited = true;
                        break;
                    }
                }

                cout << loc.getName() << " : " << (visited ? "Visited" : "Pending Visit") << endl;
                break;
            }
        }
    }

    cout << "------------------------------" << endl;
    return static_cast<int>(roomListPtr->size());
}

string Printer::printLocation(int choosenindex){

    vector<string>* roomListPtr = playerPtr->shareRoomListPtr();

    if (choosenindex < 0 || choosenindex >= static_cast<int>(roomListPtr->size())) {
        //tell the player
        return "OutOfBounds";
    }

    const string& targetRoomName = (*roomListPtr)[choosenindex];

    for (const Location& loc : gameLibraryPtr->locationLibrary) {
        if (loc.getName() == targetRoomName) {
            return loc.getName();
        }
    }
    //should not be valid
    throw runtime_error("Location not found in locationLibrary for selected index");
}

void Printer::printClues() {

    vector<string>* clues = playerPtr->shareClueListPtr();
    if (!clues) throw runtime_error("Clue list not found.");

    int i = 1;
    for (const string& clueName : *clues) {
        bool found = false;
        for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
            if (cluePtr && cluePtr->getName() == clueName) {
                if (dynamic_cast<Item*>(cluePtr.get())) break;
                cluePtr->setInspected(true);
                cout << "Clue " << i++ << ": " << cluePtr->getName() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            throw runtime_error("Clue \"" + clueName + "\" not found in library.");
        }
    }

    cout << endl;
}

void Printer::printPersonDetails(const string& personName) {

    for (const Person& person : gameLibraryPtr->personLibrary) {
        if (person.getPersonName() == personName) {
            cout << "---- Person Details ----\n";
            cout << "Name: " << person.getPersonName() << endl;
            cout << "Description: " << person.grabDescription() << endl;
            cout << "------------------------\n";
            return;
        }
    }

    throw runtime_error("Person \"" + personName + "\" not found.");
}

void Printer::printEnd(const Ending& ending) {

    cout << "==== Ending ====" << endl;
    cout << "End Name: " << ending.getSceneName() << endl;
    cout << ending.getStoryDescription() << endl;
    int endHp = playerPtr->getPlayerHp();
    cout << "You ended the game with " << endHp << " different choices could have gotten you elsewhere..." << endl;
}

void Printer::printAutopsy(const string& characterName) const {

    for (const Autopsy& autopsy : gameLibraryPtr->autopsyLibrary) {
        if (autopsy.getCharacterName() == characterName) {
            autopsy.getAutopsyDescription(); // Assuming this method prints or returns
            return;
        }
    }

    throw runtime_error("No autopsy found for \"" + characterName + "\".");
}


int Printer::printSelectableItems() {
    
    lastItemList.clear();
    vector<string>* clues = playerPtr->shareClueListPtr();

    int index = 1;
    for (const string& clueName : *clues) {
        for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
            if (cluePtr && cluePtr->getName() == clueName) {
                if (Item* item = dynamic_cast<Item*>(cluePtr.get())) {
                    cout << index++ << ". " << item->getName() << endl;
                    lastItemList.push_back(item);
                }
                break;
            }
        }
    }

    if (lastItemList.empty()) cout << "(none found)" << endl;

    return static_cast<int>(lastItemList.size());
}

int Printer::printSelectableClues() {
    lastClueList.clear();
    vector<string>* clues = playerPtr->shareClueListPtr();

    int index = 1;
    for (const string& clueName : *clues) {
        for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
            if (cluePtr && cluePtr->getName() == clueName) {
                if (!dynamic_cast<Item*>(cluePtr.get())) {
                    cout << index++ << ". " << cluePtr->getName() << endl;
                    lastClueList.push_back(cluePtr.get());
                }
                break;
            }
        }
    }

    if (lastClueList.empty()) cout << "(none found)" << endl;

    return static_cast<int>(lastClueList.size());
}

void Printer::printSelectedItemByIndex(int index) {
    if (index < 1 || index > static_cast<int>(lastItemList.size()))
        throw runtime_error("Invalid item selection.");

    Item* item = const_cast<Item*>(lastItemList[index - 1]);
    item->print();
    item->setInspected(true);
}

void Printer::printSelectedClueByIndex(int index) {
    if (index < 1 || index > static_cast<int>(lastClueList.size()))
        throw runtime_error("Invalid clue selection.");

    Clue* clue = const_cast<Clue*>(lastClueList[index - 1]);
    clue->print();
    clue->setInspected(true);
}
