#ifndef AUTOPSY_H
#define AUTOPSY_H

#include<string>

using namespace std;

class Autopsy {
    private :
        string characterName;
        string autopsyDescription;

    public: 

    Autopsy(string charName, const string& descript);
    Autopsy findAutopsies(string personName);
    ~Autopsy();
};


#endif