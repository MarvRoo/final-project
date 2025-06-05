#include "printer.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Printer::printSearchItem(string itemName) {
    if (!gameLibraryPtr) {
        throw runtime_error("Game data not set.");
    }

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        Item* item = dynamic_cast<Item*>(cluePtr.get());
        if (item && item->getName() == itemName) {
            item->print();
            item->setInspected(true);
            return;
        }
    }

    throw runtime_error("Item \"" + itemName + "\" not found.");
}

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

void Printer::printAccessibleLocations() {
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
}

void Printer::printClues() {
    if (!playerPtr || !gameLibraryPtr) {
        throw runtime_error("Player or Game data not set.");
    }

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

void Printer::printClue(string clueName) {
    if (!gameLibraryPtr) {
        throw runtime_error("Game data not set.");
    }

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        if (!cluePtr || cluePtr->getName() != clueName) continue;
        if (dynamic_cast<Item*>(cluePtr.get())) break;

        cluePtr->print();
        cluePtr->setInspected(true);
        return;
    }

    throw runtime_error("Clue or Interview \"" + clueName + "\" not found.");
}

void Printer::printPersonDetails(const string& personName) {
    if (!gameLibraryPtr) {
        throw runtime_error("Game data not set.");
    }

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
    if (!playerPtr) {
        throw runtime_error("Player not set.");
    }

    cout << "==== Ending ====" << endl;
    cout << "End Name: " << ending.getSceneName() << endl;
    cout << ending.getStoryDescription() << endl;
    int endHp = playerPtr->getPlayerHp();
    cout << "You ended the game with " << endHp << " different choices could have gotten you elsewhere..." << endl;
}

void Printer::printAutopsy(const string& characterName) const {
    if (!gameLibraryPtr) {
        throw runtime_error("Game data not set.");
    }

    for (const Autopsy& autopsy : gameLibraryPtr->autopsyLibrary) {
        if (autopsy.getCharacterName() == characterName) {
            autopsy.getAutopsyDescription(); // Assuming this method prints or returns
            return;
        }
    }

    throw runtime_error("No autopsy found for \"" + characterName + "\".");
}

