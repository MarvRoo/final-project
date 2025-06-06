#include "interview.h"
#include <iostream>

using namespace std;

Interview::Interview(const vector<string>& interviewClueString, int clueID) {
    this->name = interviewClueString[0] + "'s Interview";
    this->ClueID = clueID;
    this->InterviewFacts = interviewClueString;
}

Interview::~Interview() {
    // vector<string> InterviewFacts automatically cleans itself up
}

void Interview::print() {
    for(int i=0; i < InterviewFacts.size()-1; ++i){
        if(i == 0){
            cout << InterviewFacts.at(i) + ": " << endl;
        }
        cout << InterviewFacts.at(i) << endl;
    }
}