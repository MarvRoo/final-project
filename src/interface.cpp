#include "interface.h"
#include "player.h"

#include <iostream>
#include <vector>
#include <limits>

//pesudo code for interface rn bc game loop isn't done yet
void Interface::setPrinter(Printer* printerPtr) {
    printer = printerPtr;
}

//repetative pop up that gives player review the clues
void Interface::viewClueInterface() {
    cout << "=== Items Acquired ===" << endl;
    int itemCount = printer->printSelectableItems();

    cout << "\n=== Clues Acquired ===" << endl;
    int clueCount = printer->printSelectableClues();

    if (itemCount == 0 && clueCount == 0) {
        cout << "\nYou have no clues or items to inspect." << endl;
        return;
    }

    cout << "\nWould you like to inspect an (1) Item or (2) Clue? Enter 1 or 2: ";
    int typeChoice;
    cin >> typeChoice;

    while (cin.fail() || (typeChoice != 1 && typeChoice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter 1 for Item or 2 for Clue: ";
        cin >> typeChoice;
    }

    int selection;
    if (typeChoice == 1) {
        if (itemCount == 0) {
            cout << "No items available to inspect.\n";
            return;
        }
        cout << "Enter the number of the Item to inspect: ";
        cin >> selection;

        while (cin.fail() || selection < 1 || selection > itemCount) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
            cin >> selection;
        }

        printer->printSelectedItemByIndex(selection);

    } else {
        if (clueCount == 0) {
            cout << "No clues available to inspect.\n";
            return;
        }
        cout << "Enter the number of the Clue to inspect: ";
        cin >> selection;

        while (cin.fail() || selection < 1 || selection > clueCount) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again: ";
            cin >> selection;
        }

        printer->printSelectedClueByIndex(selection);
    }
}


//repetative pop up that gives player review the location they want go
string Interface::viewLocationInterface() {
    cout << "Viewing lists of locations:" << endl;
    int locSize = printer->printAccessibleLocations();

    if (locSize == 0) {
        cout << "No accessible locations found." << endl;
        return "";
    }

    int choosenindex = -1;
    string returnedLoc;

    while (true) {
        cout << endl << "Enter the number (0 to " << (locSize - 1) << ") of the location to enter: ";
        cin >> choosenindex;

        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            // discard input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            returnedLoc = printer->printLocation(choosenindex);
            break; // success
        } catch (const out_of_range& e) {
            cout << "That number is out of range. Try again." << endl;
        }
    }

    return returnedLoc;
}

string Interface::viewSuspectList(vector<string>&suspectList) {
    //print out list of possible suspects
    int suspectCount = 0;

    for(int i = 0; i < suspectList.size(); ++i) {
        suspectCount +=1;
        cout << suspectList.at(i) << " (" << i + 1 << ")" << endl;
    }

    cout << "Given the list of possible suspects, input the number (next to the person's name) that indicates who you think the suspect is." << endl;
    int suspectNumber;
    string chosenSuspect;
    bool ifFalse = false;

    
    while(suspectNumber >= suspectList.size()+2 || suspectNumber <= 0) {
        cout << "Input a valid number as indicted next to the suspects's name." << "From 1 to " << suspectCount << endl;
        cin >> suspectNumber;
        if(suspectNumber <= suspectList.size()+1 && suspectNumber > 0) break;
    }

    //find the suspect given the number
    for(int j = 0; j < suspectList.size(); ++j) {
        if(suspectNumber-1 == j) {
            chosenSuspect = suspectList.at(j);
            break;
        }
    }
    return chosenSuspect;
}