#include "interface.h"
#include "player.h"

#include <iostream>
#include <vector>

//pesudo code for interface rn bc game loop isn't done yet

//repetative pop up that gives player review the clues
//use clueLibrary in gamedata.h
 void Interface::viewClueInterface() {
    cout << "Enter the number (that's next to the corresponding clue)";
    cout << "that you would like to reveiw on. " << endl;
    /*
        call printer function to print out list of clues
    */
}

//repetative pop up that gives player review the location they want go
//use locationLibrary in gamedata.h
 void Interface::viewLocationInterface() {
    cout << "Viewing lists of locations:" << endl;
    /*
         call printer function to print out list of locations
    */
    
    //not sure if you would like to implment these (can delete later)
    cout << "Would you like to know what locations you have or have not visited so far? " << endl;
    cout << "enter the number '1' to see what locations you have already visited. " << endl;
    cout << "Enter the number '2' to see what locations you have not visited yet." << endl;
}