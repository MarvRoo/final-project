#include "Player.h"
#include <string>
#include <vector>
#include "Item.h"
#include "Clue.h"
#include "Location.h"
#include <iostream>
using namespace std;


Player::Player() : declaredSuspect("NA") {}

void Player::setSuspect(string suspectName){
    declaredSuspect = suspectName;
}

void Player::nextRoom(int roomId){

}
void Player::ReviewClues(int){

}
void Player::ReviewItem(int){

}
void Player::startInterview(string){

}




