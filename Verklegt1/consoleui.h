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
    void displayListOfScientists(vector<Scientist> &scientists);
    void readScientists(vector<Scientist>& scientists);
};

#endif // CONSOLEUI_H
