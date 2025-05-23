#ifndef INTERVIEW_H
#def INTERVIEW_H

#include “Clue.h”
#include <string>
#include <vector>


Class Interview : public Clue {
	public:
		void SetInterview(const std::string name, int valueID, const std::string& fileName);
		std::vector<std::string> InterviewFacts;
};
#endif