#include "clue.h"

//default clue constructor
Clue::Clue() {
    ClueID = 0;
    name = "N/A";
    inspected = false;
}

Clue::Clue(int id, const string& name, bool inspected) : ClueID(id), name(name), inspected(inspected) {}

string Clue::getName() const {return name;}