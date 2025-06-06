#include "choice.h"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

Choice::Choice(){

}

//copy the choice vector
Choice::Choice(const vector<pair<string, int>>& choices, bool isChoiceNeg)
{
    this->options = choices;
    this->negHp = isChoiceNeg;
}


void Choice::print() const{
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i].first << endl;
    }

    // Get user input for choice
    int selection = 0;
    while (true) {
        cout << "Enter your choice (1-" << options.size() << "): ";
        cin >> selection;

        if (cin.fail() || selection < 1 || static_cast<size_t>(selection) > options.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            break;
        }
    }

    // Call playerChoices with the chosen int from the paired option
    int effect = options[selection - 1].second;

    //choice is printed out
    cout << endl << "Me: " + options[selection - 1].first << endl << endl;
    if(this->negHp){
        //true means the hp question causes subtraction not additon
        gameFunctions->playerChoices(effect, negHp);
    }
    gameFunctions->playerChoices(effect, false);
}

int Choice::getPointValue(int index) const {
    if (index < options.size()) {
        return options[index].second;
    }
    return 0;
    //or throw an exception if index is invalid
}


