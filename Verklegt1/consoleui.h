#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"
#include "scientist.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void createScientist();
    void WelcomeMenu();

    friend istream& operator >> (istream& in, Scientist& rhs);

private:
    ScientistService service;
    void displayListOfScientists();
    void readScientists();
};

#endif // CONSOLEUI_H
