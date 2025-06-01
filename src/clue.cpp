#include "clue.h"

//default clue constructor
Clue::Clue() {
    ClueID = 0;
    name = "N/A";
    inspected = false;
}

Clue::Clue(int id, const string& name) : ClueID(id), name(name), inspected(false) {}

Clue::~Clue() {
    // No manual cleanup needed
    // included for standard practice 
}
