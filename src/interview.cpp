#include "interview.h"
#include<iostream>

using std::cout;
using std::endl;
using std::string;
using namespace std;

void Interview::interview(const std::string& interviewClueString, int clueID) {
    this->ClueID = clueID;
    InterviewFacts.push_back(interviewClueString);
}

void Interview::print() {
    for(int i=0; i < InterviewFacts.size()-1; ++i){
        cout << InterviewFacts.at(i) << endl;
    }
}

Interview::~Interview() {}