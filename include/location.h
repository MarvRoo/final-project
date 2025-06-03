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

    bool checkUnlock();
    bool checkkeyClueFound();
    bool checkMultiItems();
    string getName() const;
    string getKeyClue() const;
    vector<string> getClueList() const;
    void changeClueFound();
    void unlockLocation();
    void lockLocation();
    
};
#endif
