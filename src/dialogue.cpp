#include "dialogue.h"
#include "gameLoop.h"
#include <string>
#include <iostream>

using namespace std;
Dialogue::Dialogue(){}

Dialogue::Dialogue(vector<string> dialogueStrings){
    this->dialogueSegments = dialogueStrings;
}

void Dialogue::print() const {
    string prevLocation;
    string returnedString; // This would come from GameLoop goToLocation()
    if (!gameFunctions) throw runtime_error("gameLoop pointer not set in Dialogue.");


    for (size_t i = 0; i < dialogueSegments.size();) {
        const string& line = dialogueSegments[i];

        // Handle location unlock
        if (line == "+unlockNextLocation") {
            if (i < dialogueSegments.size()) {
                ++i;
                string newUnlockedLocation = dialogueSegments[i];
                cout << endl << "[Unlocked a new location: " << newUnlockedLocation << "]" << endl;
                gameFunctions->unlockNextLocation(newUnlockedLocation);
                //keep moving the story so add by 1
                ++i;
                
            }
        }// Handle location transition
        //[presumed done]
        else if (line.rfind("+goToLocation", 0) == 0) {
            cout << "[Going to a new location...]" << endl;

            //check returning string matches 
            returnedString = interface->viewLocationInterface();

            //move by one to see get branch
            ++i;
            //reads the +checkBranch check point
            if (i < dialogueSegments.size() && dialogueSegments[i] == "+CheckBranch{") {
                //first word is name
                ++i;
                string requiredLocation = dialogueSegments[i];
                ++i;
                string gameHint = dialogueSegments[i]; 
                //"Game: mmm you should go back..."
                //call the first display of locations

                //Loop until player chooses the correct location
                while (returnedString != requiredLocation) {
                    cout << endl << gameHint << endl << endl;
                    
                    returnedString = interface->viewLocationInterface();
                }
                //read +end block
                ++i;
                //the returned string matches the location name
                //Skip over +end} by increasing index
                //This function catches that last line clean up
                if (dialogueSegments[i] == "+end}") {
                    //blank line addition
                    ++i;
                }else{
                    throw runtime_error("+goToLocation has failed");
                }
            }
        }

        // Handle clue blocks like interviews or dialogue clues
        else if (line == "+stringClues{" || line == "+InterviewClues{") {
            cout << endl << "[New clues discovered...]" << endl;
            //check next string after starting collection loop
            ++i;
            while (i < dialogueSegments.size() && dialogueSegments[i] != "+end}") {
                string clue = dialogueSegments[i];
                cout << " - " << clue << endl;
                //Call the following function that should be in Gameloop
                gameFunctions->acquireNewClue(clue);
                ++i;
            }
            //prev line is +end} get rid of it 
            cout << endl;
            ++i;
            
        }
        
       else if(line  == "+callNightInterface"){
            vector<string> suspects;
            //CODE TO READ THE SUMMARY WALKTHROUGH
            cout << "\nGame: It's that time of day again...who will it be?\n" << endl;
            cout << "Complete the statement or answer the question with the corresponding clue your found\n" << endl;
            //Call interface Night Summary 
            interface->clueReview();
            cout << endl << endl;

            
            string statement;
            string clueAnswer;
            //call Suspect run down
            ++i; 
            while(dialogueSegments[i] != "+end"){
                statement = dialogueSegments[i];
                ++i;
                clueAnswer = dialogueSegments[i];
                gameFunctions->suspectRunDown(statement, clueAnswer);
                ++i;
            }
            //collect suspect list
            ++i;
            if(dialogueSegments[i] == "+chooseSuspect{"){
                ++i;
                while (dialogueSegments[i] != "+end}"){
                    suspects.push_back(line);
                    ++i;
                }
                //we're at +end}
                ++i;
                interface->viewSuspectList(suspects);
                //we dont want to cout +end
            }

        }else if(line == "+allDayCluesFound"){
            //call gameloop to match players clues to their respective clue ids then match that list to day clues
            //check if we're a match to move on
            ++i;
            string day = dialogueSegments[i];
            int dayNum = stoi(day);
            int choice = 0;
            //while not true
            while (!gameFunctions->cluesMatch(dayNum)){
                //loop the go to location interface
                string prevLoc = interface->viewLocationInterface();
                cout << "\nEnter 1 for 'Yes' and 2 for 'No' to continue going to locations: \n";
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2) {
                    cin.clear();
                    cout << "Invalid input. Please try again." << endl;
                    cin >> choice;
                }

            }
            //do not print day number
            ++i;
            
        }

        // Handle end-of-reading marker
        else if (line == "+doneReading") {
            cout << endl << "[End of this section. Time progresses.]" << endl;
            ++i;
            string NumDay = dialogueSegments[i];
            //convert to numDay variable to an int 
            int dayNum = stoi(NumDay);
            
            ++i;
            string currentTime = dialogueSegments[i];
            gameFunctions->changeDayTime(dayNum, currentTime);

            cout << "Moving on to Day " + NumDay + ": " << endl << endl;
            return;
        }else if(line == "+search{"){
            //keep reading 
            ++i;
            string gameText = dialogueSegments[i];
            //skip the +end
            ++i;
            int choice;
            cout << endl << gameText << endl;
            cout << "Enter 1 for 'Yes' and 2 for 'No': ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 2) {
                cin.clear();
                cout << "Invalid input. Please try again." << endl;
                cin >> choice;
            }
            //loop until string "No" is given
            while (choice != 2){
                string prevLoc = interface->viewLocationInterface();
                //player can collect clues until there choice changes
                cout << endl << endl << gameText << endl;
                cout << "Enter 1 for 'Yes' and 2 for 'No': ";
                cin >> choice;

                if (cin.fail() || choice < 1 || choice > 2) {
                    cin.clear();
                    cout << "Invalid input. Please try again." << endl;
                    cin >> choice;
                }
            }

        }else{
            //Regular dialogue output
            //if all the branches dont get checked
            cout << line << endl;
            ++i;
        }
    }
}