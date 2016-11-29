#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"
#include "scientist.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();
    void WelcomeMenu();

    friend istream& operator >> (istream& in, Scientist& rhs);

private:
    ScientistService _service;
    void displayListOfScientists();
    void readScientists(vector <Scientist> &scientists);
};

#endif // CONSOLEUI_H
