#ifndef INTERVIEW_H
#define INTERVIEW_H

#include "clue.h"
#include <string>
#include <vector>


class Interview : public Clue {
	private:
		std::vector<std::string> InterviewFacts;
	public:
		void interview(const std::string& interviewClueString, int clueID);
		void printInterviewFacts();
};

#endif