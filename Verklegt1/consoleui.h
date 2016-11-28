#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "performerservice.h"
#include "performer.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();

    friend istream& operator >> (istream& in, Performer& rhs);

private:
    PerformerService _service;
    void displayListOfScientists();
    void readScientists(vector <Performer> &performers);
};

#endif // CONSOLEUI_H
