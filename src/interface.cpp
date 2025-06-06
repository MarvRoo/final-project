#include "interface.h"
#include "player.h"
#include "printer.h"

#include <iostream>
#include <vector>
#include <limits>

//pesudo code for interface rn bc game loop isn't done yet
void Interface::setPrinter(Printer* printerPtr) {
    this->printer = printerPtr;
}

void Interface::showAutopsies(string deadNpc){
    printer->printAutopsy(deadNpc);
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

void Interface::clueReview() {
    cout << "\nGame: Remember, all you have to do is match some of the clues you've collected to your thinking process...\n";
    cout << "This will summarize your investigation for the day and help you pick a suspect to interview tomorrow.\n" << endl;

    cout << "Game: You will not be allowed to move on until you've correctly matched the clues to the thought process.\n" << endl;

    cout << "Game: These are the clues you've collected so far.\nYou can pick which ones to view more in depth, like items or interviews.\n";
    viewClueInterface();

    int choice = 0;
    while (true) {
        cout << "\nWould you like to continue reviewing your clues?\nEnter 1 for 'No' or 2 for 'Yes': ";
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter 1 or 2." << endl;
            continue;
        }

        if (choice == 1) break;

        viewClueInterface();
    }
}