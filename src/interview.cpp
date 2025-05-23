#include "Interview.h"

void Interview::interview(const std::string& interviewClueString, int clueID) {
    this->name = interviewClueString;
    ClueID = clueID;

    std::vector<std::string> InterviewFacts.push_back(interviewClueString);
}

void Interview::printInterviewFacts() {
    for(int i = 0; i < InterviewFacts.size() -1; ++i){
        cout << InterviewFacts.at(i);
        cout << endl;
    }

}
