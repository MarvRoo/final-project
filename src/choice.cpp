#include "choice.h"
#include <string>
#include <iostream>

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
        //Only show the text
    }
}

int Choice::getPointValue(int index) const {
    if (index < options.size()) {
        return options[index].second;
    }
    return 0;
    //or throw an exception if index is invalid
}


