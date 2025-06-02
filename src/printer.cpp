#include "printer.h"
#include <iostream>

using namespace std;

void Printer::setGameData(const GameData& data){
    gameDataPtr = &data;
}

void Printer::printSearchItemLibrary(vector<string>* items){
    for (const string& itemName : *items){
        for (const string& day : gameDataPtr->dayLibrary){
            for (const string& item : day.getItemList()){
                if (item.getName() == itemName && item.isItemFound()){
                    item.print();
                    cout << endl;
                } 
            }
        }
        }
}
void Printer::printDialogueSegment(const string& segmentName){

}