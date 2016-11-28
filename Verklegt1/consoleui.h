#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "performerservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();

private:
    PerformerService _service;
    void displayListOfScientists();
    void readScientists(vector <Performer> &performers);
};

#endif // CONSOLEUI_H
