#include "player.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Player::Player() : declaredSuspect("NA") {}

void Player::setSuspect(string suspectName){
    declaredSuspect = suspectName;
}

void Player::nextRoom(int roomId){
    cout << "\n--- Loading next room: " << roomId << "---" << endl;
    if(roomId >=0 && roomID < RoomList.size()){
        Location* destinationRoom = RoomList[roomId];
        if(destinationRoom != nullptr){
            if(!destinationRoom->isLockedStatus() || destinationRoom->hasKeyItemBeenFound()){
                currentLocation = destinationRoom;
                cout << "You have entered: " << currentLocation->getName() << endl;
            }
            else{
                cout << "The " << destinationRoom->getName() << " is locked." << endl;
                if(destinationRoom->getKeyItem() != nullptr){
                    cout << "You might need the " << destinationRoom->getKeyItem()->getName() << "to open it." << endl;
                }
            }
        }
        else{
            cout << "Room with ID " << roomId << "is not a balid location." << endl;
        }
    }
        else{
            cout << "Invalid Room ID." << endl;
        }
        cout << "------------------------------------------" << endl;
}

void Player::printReviewClues(){
    cout << "\n--- Reviewing Clues ---" << endl;
    if(ClueList.empty()){
        cout << "You haven't found any clues yet." << endl;
    }
    else{
        for(size_t i = 0; i < ClueList.size(); ++i){
            if(ClueList[i] != nullptr){
                cout << "[" << i << "] Name: " ClueList[i]->getName() << ", Description: " << ClueList[i]->getDescription() << endl;
            }
            else{
                cout << "[" << i << "] Empty, Clue not yet found" << endl;
            }
        }
    }
    cout << "------------------------------------------" << endl;
}

void Player::ReviewItem(int){
    cout << "\n--- Reviewing Item with ID: " << itemId << " ---" << endl;
    bool found = false;

    for(int i = 0; i < inventory.size(); ++i){
        const Item* item = inventory[i];
        if(item != nullptr && item->getItemID() == itemId){
            cout << "Name: " << item->getName() << endl;
            cout << "Description " << item->getDescription() << endl;
            found = true;
            break;
        }
    }

    if(!found && currentLocation != nullptr){
        cont vector<Item*>& locationItems = currentLocation->getItemList();
        for(int i = 0; i < locationItems.size(); ++i){
            const Item* item = locationItems[i];
            if(item != nullptr && item->getItemID() == itemId){
                cout << "Found in the " << currentLocation->getName() << ":" << endl;
                cout << "Name: " << item->getName() << endl;
                cout << "Description: " << item->getDescription() << endl;
                found = true;
                break;
            }
        }
    }
    if(!found){
        cout << "Item with ID " << itemId << " was not found in your inventory or the current location." << endl;
    }
    cout << "------------------------------------------" << endl;
}

void Player::startInterview(string suspectName){
    cout << "\n--- Attempting to interview: " << suspectName << " ---" << endl;
    bool found = false;

    for(int i = 0; i < suspects.size(); ++i;){
        const Person* suspect = suspects[i];
        if(suspect != nullptr && suspect->name == suspectName){
            cout << "You begin interviewing " << suspect->name << "." << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Suspect " << suspectName << " not found" << endl;

    }
    cout << "------------------------------------------" << endl;
}