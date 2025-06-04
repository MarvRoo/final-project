#include "dialogue.h"
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

    for (size_t i = 0; i < dialogueSegments.size(); ++i) {
        const string& line = dialogueSegments[i];

        // Handle location unlock
        if (line.rfind("+unlockNextLocation", 0) == 0) {
            if (i < dialogueSegments.size()) {
                string newUnlockedLocation = dialogueSegments[++i];
                cout << "[Unlocked a new location: " << newUnlockedLocation << "]" << endl;
                // TODO: GameLoop::unlockNextLocation(newUnlockedLocation);
            }
        }

        // Handle location transition
        if (line.rfind("+goToLocation", 0) == 0) {
            cout << "[Going to a new location...]" << endl;

            // Assume returnedString = Interface::goToLocation();
            returnedString = "Shed"; // Stub, this would be dynamic in gameplay
            //make this string equal goToLocation() since goToLocation() returns a string

            ++i;
            //reads the +checkBranch check point
            if (i < dialogueSegments.size() && dialogueSegments[i].rfind("+CheckBranch{", 0) == 0) {
                string requiredLocation = dialogueSegments[i++];
                string gameHint = dialogueSegments[i++]; // e.g. "Game: mmm you should go back..."

                // Loop until player chooses the correct location
                while (returnedString != requiredLocation) {
                    cout << gameHint << endl;
                    //CODE GAMELOOP needs to be done
                    // returnedString = GameLoop::goToLocation();
                    returnedString = requiredLocation; // Simulating for now
                }
                // Skip over +end}
                if (i < dialogueSegments.size() && dialogueSegments[i] == "+end}") {
                    ++i;
                }
            }
        }

        // Handle clue blocks like interviews or dialogue clues
        if (line == "+stringClues{" || line == "+InterviewClues{") {
            cout << "[New clues discovered...]" << endl;
            //check next string after starting collection loop
            ++i;
            while (i < dialogueSegments.size() && dialogueSegments[i] != "+end}") {
                string clue = dialogueSegments[i];
                cout << " - " << clue << endl;
                //Call the following function that should be in Gameloop
                // TODO: GameLoop::acquireNewClue(clue);
                ++i;
            }
            ++i; // Skip +end}
            
        }
        /*
        +callNightInterface
        +chooseSuspect{
        Gardener
        Pool Boy
        +end}
        */
       if(line  == "+callNightInterface"){
        vector<string> suspects;

        //collect suspect list
        ++i;
        if (line  == "+chooseSuspect{"){
            ++i;
            while (line != "+end}"){
                suspects.push_back(line);
                ++i;
            }
        }
        //call interface for end of the day summarization of 
        //this function should take in the following
        // function(suspects) and return the string name of the suspect the player choose in interface
        //Gameloop will then call changeSuspect or whatever the function is called in player to set the name of the selected suspect
        
       }

        // Handle end-of-reading marker
        if (line == "+doneReading") {
            cout << "[End of this section. Time progresses.]" << endl;
            string NumDay = dialogueSegments[i++];
            //convert to numDay variable to an int 
            int dayNum = stoi(NumDay);

            string currentTime = dialogueSegments[i++];
            // TODO: GameLoop::changeDayTime(dayNum, currentTime);
            //Gameloop should search Days for a day with the dayNum int. So 1 is Day1 etc.
            //Then check what currentTime string was passed in Morning or Evening or Night
            //Fixing the bools in the day accordingly
        }

        //Regular dialogue output
        cout << line << endl;
    }
}