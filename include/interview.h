#ifndef INTERVIEW_H
#define INTERVIEW_H

#include "clue.h"
#include <string>
#include <vector>


class Interview : public Clue {
	private:
		vector<string> InterviewFacts;
	public:
		Interview(){}
		Interview(const vector<string>& interviewClueString, int clueID);
		string getType() const override { return "Interview"; }

		~Interview() override;
		void print();
};

#endif