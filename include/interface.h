#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>
#include "printer.h"

using namespace std;

class Interface {
private:
    Printer* printer = nullptr;  // Use a pointer to be set later

public:
    void setPrinter(Printer* printerPtr);  // Setter

    void viewClueInterface();
    void viewLocationInterface();
    string viewSuspectList(vector<string>& suspectList);
};

#endif