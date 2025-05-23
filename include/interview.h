#ifndef INTERVIEW_H
#def INTERVIEW_H

#include “Clue.h”
#include <string>
#include <vector>


Class Interview : public Clue {
	private:
		std::vector<std::string> InterviewFacts;
	public:
		void interview(const std::string& interviewClueString, int clueID);
		void printInterviewFacts();
};
#endif