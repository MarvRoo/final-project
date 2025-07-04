#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>
class Printer; // Forward declaration
#include "printer.h"

using namespace std;

class Interface {
private:
    Printer* printer = nullptr;  // Use a pointer to be set later

public:
    void setPrinter(Printer* printerPtr);  // Setter
    void viewClueInterface();
    string viewLocationInterface();
    string viewSuspectList(vector<string>& suspectList);
    void showAutopsies(string deadNpc);
    void gameOver();
    void clueReview();

    /*we still need to add accessors to printer for 

        // Prints the ending scene
        void printEnd(const Ending& ending);
    */
};

#endif