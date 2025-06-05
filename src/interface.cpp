#include "interface.h"
#include "player.h"

#include <iostream>
#include <vector>

//pesudo code for interface rn bc game loop isn't done yet

//repetative pop up that gives player review the clues
//use clueLibrary in gamedata.h
 void Interface::viewClueInterface() {
    printer.printClues();
    cout << "Enter the number (that's next to the corresponding clue)";
    cout << "that you would like to reveiw on. " << endl;
}

//repetative pop up that gives player review the location they want go
//use locationLibrary in gamedata.h
 void Interface::viewLocationInterface() {
    cout << "Viewing lists of locations:" << endl;
    printer.printAccessibleLocations();
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