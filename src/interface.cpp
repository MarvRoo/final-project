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

/*
Printer Class should have the following

(Used to show the player where they can go)
- A printer that prints all the locations that player has open to them
- The function should call the helper function in player + shareRoomListPtr() const: vector<string>*
- you'll use that vector<string>* to know what classes player has at this point in the story
- The printer should print the name of the location and specify if it has been accessed already.
Format: Location name : (Visited or Pending Visit)
- you'll do this by doing the following
- Access the Game data library and use the locationlibrary and compare your string names to the names of the Locations objects
and when you find a match to its location object go in and check the following
- If the room's keyItem is already found. Then print Visited after printing the location name 
- If keyitem not found Then print Pending Visit after printing the location name
*/

/*
What if we want to print the location description? 
printLocationDescript(string LocationName);
- The function should call the locationlibrary to search for the object
- Location should have the helpter function that prints it's decription
- so it's like our central print is calling the mini printer specifically for locationdescription

/*
These are so we can seperate the printing of clues vs items but if 
interface needs both it can call the Printing all clues in an organized way function. You name it
Printing players cluelist
 */

/*what about just printing cluelist?*/

/*
What if I want to print only items?
 */


/*
Printing all clues in an organized way: 

like for exmaple.

Items collected: 
(list them with their index number +1-etc)

Clues collected: 
(list string clues displayed and interview names)

-In order to do this 
search the interview and item library to be able to find the object by its variable name
this way you can confirm if it should be printed under items collected or clues collected.
*/


/*
Print a clues description in singular form?
function (string mameofClue)
    search the interview and item library to be able to find the object by its variable name
    when the object is called use the object to call its printer for the following cases 
    - Remember you need to check each objects name and match it with 
    - if the clue that we're printing is an interview 
            -call mini interview print
    - if the clue that were printing is an item
            - calll mini item printer
    - if the clue is a clue dont search library 
            -just print the name becuase clue doesn't have any depth 
*/
