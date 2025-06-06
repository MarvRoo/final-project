#include "printer.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

string Printer::printAccessibleLocations() const{
    //write out the interface
    //Tell the viewer they are looking at the listed items they've found so far
    //call printers the printers should be printing them numbered by # found
    //int Printer::printSelectableItems()
    //Tell the player this is the list of clues they collected
    //int Printer::printSelectableClues()
    cout << "\n===== Accessible Locations =====" << endl;

    vector<string>* accessibleLocsPtr = playerPtr->shareRoomListPtr();
    const vector<string>& accessibleLocs = *accessibleLocsPtr;
    if (accessibleLocs.empty()) {
        //stupid when game loads up we need to push some initial location names
        throw runtime_error("playerPtr has an empty list...");
    }

    for (size_t i = 0; i < accessibleLocs.size(); ++i) {
        cout << i + 1 << ". " << accessibleLocs[i] << endl;
    }

    cout << "Select a location by number: ";
    int choice;
    cin >> choice;

    if (choice < 1 || static_cast<size_t>(choice) > accessibleLocs.size()) {
        cout << "Invalid choice." << endl;
        return "";
    }
    //okay but now we need to call the location they went to 
    printLocation(accessibleLocs[choice - 1]);

    return accessibleLocs[choice - 1];
}

//repetative pop up that gives player review the location they want go
void Printer::printLocation(string locName) const {
    cout << "\n===== Location Selected =====" << endl;
    //use the location name to search the library objection location and then print it
    for (auto& loc : gameLibraryPtr->locationLibrary) {
        if (loc.getName() == locName) {
            loc.printDescript();
            return;
        }
    }
}


//These are fine
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

void Printer::printEnd() {
    if (!playerPtr || !gameLibraryPtr) {
        cerr << "[Error] Missing player or game library in printEnd()." << endl;
        return;
    }

    int hp = playerPtr->getPlayerHp();

    // Safety check
    if (gameLibraryPtr->endingsLibrary.size() < 2) {
        cerr << "[Error] Not enough endings available." << endl;
        return;
    }

    const Ending& chosenEnding = (hp <= 25)
        ? gameLibraryPtr->endingsLibrary[0]  // Bad ending
        : gameLibraryPtr->endingsLibrary[1]; // Good ending

    cout << "==== Ending ====" << endl;
    cout << "End Name: " << chosenEnding.getSceneName() << endl;
    cout << chosenEnding.getStoryDescription() << endl;
    cout << "You ended the game with " << hp
         << ". Different choices could have gotten you elsewhere..." << endl;
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


//New clue searches
int Printer::printSelectableItems() const {
    //only print the items the player has in their list and skip numbering the rest
    //You can do this by matching the Players clue list of strings which hold the names of Clues Interview or Items and only matching
    //strings with the names of data Item types
    cout << "\n===== Items in Your Inventory =====" << endl;

    vector<string>* inventoryPtr = playerPtr->shareClueListPtr();
    const vector<string>& inventory = *inventoryPtr;
    vector<string> itemNames;
    int count = 0;

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        if (cluePtr->getType() == "Item") {
            string itemName = cluePtr->getName();
            if (find(inventory.begin(), inventory.end(), itemName) != inventory.end()) {
                ++count;
                itemNames.push_back(itemName);
                cout << count << ". " << itemName << endl;
            }
        }
    }

    return count;
}

int Printer::printSelectableClues() const {
    //only print the items the player has in their list and skip numbering the rest  
    //make the same constraint and checks as items above
    cout << "\n===== Clues and Interviews You Collected =====" << endl;

    vector<string>* inventoryPtr = playerPtr->shareClueListPtr();
    const vector<string>& inventory = *inventoryPtr;
    vector<string> clueNames;
    int count = 0;

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        if (cluePtr->getType() == "Clue" || cluePtr->getType() == "Interview") {
            string clueName = cluePtr->getName();
            if (find(inventory.begin(), inventory.end(), clueName) != inventory.end()) {
                ++count;
                clueNames.push_back(clueName);
                cout << count << ". " << clueName << endl;
            }
        }
    }

    return count;
}

void Printer::printSelectedItemByIndex(int index) const {
    //create a vector of the names of printSelectableItems
    //then use the index -1 passed in to find the item the player select and return the name string
    //remember that clue library is unique and Stores data Types Clue, Interview, and Item
    //so you gotta make sure your only pushing the string names of Items
    vector<string>* inventoryPtr = playerPtr->shareClueListPtr();
    const vector<string>& inventory = *inventoryPtr;
    vector<string> itemNames;

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        if (cluePtr->getType() == "Item") {
            string itemName = cluePtr->getName();
            if (find(inventory.begin(), inventory.end(), itemName) != inventory.end()) {
                itemNames.push_back(itemName);
            }
        }
    }

    if (index < 1 || index > static_cast<int>(itemNames.size())) {
        cout << "Invalid item index." << endl;
        return;
    }

    
}

void Printer::printSelectedClueByIndex(int index) const {
   //sane idea as the item but this time only for Type interview and Clue
   //if the type if Interview then call interview print
   //if the type is Clue call clue print
   vector<string>* inventoryPtr = playerPtr->shareClueListPtr();
    const vector<string>& inventory = *inventoryPtr;
    vector<Clue*> cluesToPrint;

    for (const auto& cluePtr : gameLibraryPtr->clueLibrary) {
        if ((cluePtr->getType() == "Clue" || cluePtr->getType() == "Interview") &&
            find(inventory.begin(), inventory.end(), cluePtr->getName()) != inventory.end()) {
            cluesToPrint.push_back(cluePtr.get());
        }
    }

    if (index < 1 || index > static_cast<int>(cluesToPrint.size())) {
        cout << "Invalid clue index." << endl;
        return;
    }

    Clue* selected = cluesToPrint[index - 1];
    cout << "\n===== Clue Details =====" << endl;
    if (selected->getType() == "Interview") {
        selected->print(); // Implement this in Interview subclass
    } else {
        selected->print();          // Implement this in Clue class
    }
}
