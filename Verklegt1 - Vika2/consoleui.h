#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>

#include "scientistservice.h"
#include "scientist.h"

#include "computer.h"
#include "computerservice.h"

using namespace std;

class ConsoleUI
{
public:

    ConsoleUI(); 

    void WelcomeMenu();
    void features();
    void listOrSortScientist();

private:

    ScientistService sService;
    ComputerService cService;

    void display(vector<Scientist> scientists);
    //void displayComputers(vector<Computer> computers);
    void readComputers();
    void readScientists();

    void displayListOfScientistsAlpha();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();

    void searchName();
    void searchComputer();
    void searchDateOfBirth();
    void searchGender();
    void searchRandomScientist();

    void stats();
};

#endif // CONSOLEUI_H
