#include "player.h"

Player::Player(string name, string bloodType, string item,string description) {
    this->name = name;
    this->bloodType = bloodType;
    personalItem = item;
    this->description = description;
}

void Player::addUnlockedRoom(const std::string& roomName) {
    roomList.push_back(roomName);  // `unlockedRooms` should be a vector<string>
}
