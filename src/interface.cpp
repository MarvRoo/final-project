#include "interface.h"
#include "player.h"

#include <iostream>
#include <vector>
#include <limits>

//pesudo code for interface rn bc game loop isn't done yet
void Interface::setPrinter(Printer* printerPtr) {
    this->printer = printerPtr;
}

//repetative pop up that gives player review the clues
void Interface::viewClueInterface() {
    //calls printer to print all clues 
    int itemCount = printer->printSelectableItems();
    int clueCount = printer->printSelectableClues();
    cout << "1. View Items\n";
    cout << "2. View Clues & Interviews\n";
    cout << "Choose an option (1 or 2): ";

    int choice;
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter 1 for Items or 2 for Clues: ";
        cin >> choice;
    }

    int index;
    int count;
    if (choice == 1) {
        if (itemCount == 0) {
            cout << "\n[Info] No items in inventory to inspect.\n";
            return;
        }
        cout << "\nEnter the number of the entry to inspect (1 to " << itemCount << "): ";
        cin >> index;
        count = itemCount;
    } else {
        if (clueCount == 0) {
            cout << "\n[Info] No clues or interviews to inspect.\n";
            return;
        }
        cout << "\nEnter the number of the entry to inspect (1 to " << clueCount << "): ";
        cin >> index;
        count = clueCount;
    }

    while (cin.fail() || index < 1 || index > count) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Try again (1 to " << count << "): ";
        cin >> index;
    }

    if (choice == 1) {
        printer->printSelectedItemByIndex(index);
    } else {
        printer->printSelectedClueByIndex(index);
    }

}

string Interface::viewLocationInterface(){

    //return the string after calling printer
    return printer->printAccessibleLocations();

}

string Interface::viewSuspectList(vector<string>&suspectList) {
    //print out list of possible suspects
    //print out the vector of suspectList and let the player pick which one
    //call the printpersondetails
    if (suspectList.empty()) {
        cout << "[Info] You have no suspects yet.\n";
        return "";
    }

    cout << "\n=== Suspect List ===\n";
    for (size_t i = 0; i < suspectList.size(); ++i) {
        cout << (i + 1) << ". " << suspectList[i] << endl;
    }

    cout << "\nSelect a suspect to view details (1 to " << suspectList.size() << "): ";
    int index;
    cin >> index;

    while (cin.fail() || index < 1 || index > static_cast<int>(suspectList.size())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number between 1 and " << suspectList.size() << ": ";
        cin >> index;
    }

    string chosenSuspect = suspectList[index - 1];

    // Call printer to show suspect's detailed info
    printer->printPersonDetails(chosenSuspect);

    //this is so player setsuspect can be called
    return chosenSuspect;
}

void Interface::gameOver() {
    printer->printEnd(); // Now printer handles the logic internally
}