#ifndef ENDING_H
#define ENDING_H

#include <vector>
#include <string> 
using namespace std;


class Ending {
private:
    string sceneName;
    string storyDescription;
    int hpcap;

public:
    Ending();
    Ending(string name, string storyDescript, int hp);
    string getSceneName() const;
    string getStoryDescription() const;
    int getHPCap() const;
};

#endif