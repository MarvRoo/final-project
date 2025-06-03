#include "player.h"

Player::Player(string name, string bloodType, string item,string description) {
    this->name = name;
    this->bloodType = bloodType;
    personalItem = item;
    this->description = description;
}