#ifndef INTERFACE_H
#define INTERFACE_H

#include<vector>
#include<string>

#include "gamedata.h"

using namespace std;

class Interface {

    private:
        const GameData* gameDataPtr;

    public:
        void viewClueInterface();
        void viewLocationInterface();
        void setGameData(const GameData& data){ this->gameDataPtr = &data;}
};

#endif
