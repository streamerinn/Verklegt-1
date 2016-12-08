#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>

#include "scientistservice.h"
#include "scientist.h"
#include "computerservice.h"
#include "computer.h"

#include "computer.h"
#include "computerservice.h"
#include "connectionservice.h"

using namespace std;

class ConsoleUI
{
public:

    ConsoleUI(); 

    void WelcomeMenu();
    void features();
    void listingAndSorting();

private:

    ScientistService sService;
    ComputerService cService;
    ConnectionService coService;


    void display(vector<Scientist> scientists);
    void displayComputers(vector<Computer> computers);
    void displayConnections();
    void readComputers();
    void readScientists();

    void displayListOfComputersAlpha();
    void displayListOfComputersReversedAlpha();
    void displayListOfComputersYoung();
    void displayListOfComputersOld();

    void displaySortOptions();
    void displayComputerSortOptions();
    void displayListOfScientistsAlpha();
    void displayListOfScientistsReversedAlpha();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();




    void searchComputer();
    void searchBuiltYear();
    void searchComputerType();
    void searchRandomComputer();
    void searchBuilt();
    void searchName();
    void searchDateOfBirth();
    void searchGender();
    void searchRandomScientist();
    void deleteOptions();
    void editOptions();
    void editName();




    void stats();

    void link();

    void displayScientistComputerConnections();
    void displayComputerScientistConnections();
};

#endif // CONSOLEUI_H
