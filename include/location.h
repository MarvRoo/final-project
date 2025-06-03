#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
using namespace std;

class Location {
private:
   bool isAccessible;
   string name;
   string description;
   bool hasMultipleClues;
   bool keyClueFound;
   string keyClue;
   vector<string> clueList;

public:
    // Constructors
    Location(const string& name, const string& description, vector <string> clueList, bool accessible, bool multiple, string keyClue);
    Location(const string& name, const string& description, bool accessible, bool multiple, string keyClue);

    void unlockLocation(){isAccessible = true;}
    void lockLocation(){isAccessible = false;}
    void markClueFound(){keyClueFound = true;}

    //these should be made into acessors with const
    bool checkkeyClueFound(){return keyClueFound;}
    bool checkMultiItems(){return hasMultipleClues;}
    bool checkUnlock(){return isAccessible;}

    //these are also const
    string getName() const {return name;}
    string getKeyClue() const {return keyClue;}
    vector<string> getClueList() const {return clueList;}
    vector<string> getClues(){return clueList;}
};
#endif
