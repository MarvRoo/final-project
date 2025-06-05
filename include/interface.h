#ifndef INTERFACE_H
#define INTERFACE_H

#include<vector>
#include<string>

#include "gamedata.h"

using namespace std;

class Interface {
    private:
        Printer printer;
    public:
        void viewClueInterface();
        void viewLocationInterface();
        string viewSuspectList(vector<string>&suspectList);
};

#endif
