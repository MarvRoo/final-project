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
   bool keyItemFound;
   int keyItemID;
   vector<string> itemsList;

public:
    // Constructors
    Location(const string& name, const string& description, vector <string> ItemClues, bool accessible, bool multiple, string keyItem);
    Location(const string& name, const string& description, bool accessible, bool multiple, string keyItem);

    bool checkUnlock();
    bool checkMultiItems();
};
#endif