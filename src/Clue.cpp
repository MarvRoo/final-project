#include "Clue.h"

//default clue constructor
Clue::Clue() {
    ClueID = 0;
    name = "";
    inspected = false;
}

Clue::Clue(int id, const string& name, bool inspected) : ClueID(id), name(name), inspected(inspected) {}

//get the name of the clue
string Clue::getName() const {
    return name;
}

//check if the clue has been inspected yet
bool Clue::isInspected() const {
    return inspected;
}

//get the clue identifier (ID)
int Clue::getClueID() const {
    return ClueID;
}