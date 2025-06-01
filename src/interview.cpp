#include "interview.h"
#include<iostream>

using namespace std;

Interview::Interview(const vector<string>& interviewClueString, int clueID) {
    this->ClueID = clueID;
    this->InterviewFacts = interviewClueString;
}

Interview::~Interview() {
    // vector<string> InterviewFacts automatically cleans itself up
}

void Interview::print() {
    for(int i=0; i < InterviewFacts.size()-1; ++i){
        cout << InterviewFacts.at(i) << endl;
    }
}