#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>

#include "scientistservice.h"
#include "scientist.h"

using namespace std;

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
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();
    void readScientists();
};

#endif // CONSOLEUI_H
