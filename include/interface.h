#ifndef INTERFACE_H
#define INTERFACE_H

#include<vector>
#include<string>

using namespace std;

class Interface {

    private:
        const GameData* gameDataPtr;

    public:
        void viewClueInterface();
        void viewLocationInterface();
        void setGameData(const GameData& data){ gameDataPtr = &data;}
};

#endif
