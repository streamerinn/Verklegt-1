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

    /*** Display föll ***/

    void display(vector<Scientist> scientists);
    void displayComputers(vector<Computer> computers);
    void displayScientistConnections(vector<Scientist> scientists);
    void displayConnections();

    // Displayer upplýsingar um hvernig það er hægt að sorta
    void displaySortOptions(); // Scientist
    void displayComputerSortOptions(); // Computer

    // Display allan listann af Scientists
    void displayListOfComputersAlpha();
    void displayListOfComputersReversedAlpha();
    void displayListOfComputersYoung();
    void displayListOfComputersOld();

    // Display allan listann af Computerss
    void displayListOfScientistsAlpha();
    void displayListOfScientistsReversedAlpha();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();

    // Less inn upplýsingar um Scientist/Computer sem á að búa til
    void readComputers();
    void readScientists();

    // Föll sem breyta upplýsingum í database
    void deleteOptions();
    void editOptions();
    void link(); // connectar scientist við computer

    // Search möbuleikar fyrir computers
    void searchComputer();
    void searchBuiltYear();
    void searchComputerType();
    void searchRandomComputer();
    void searchBuilt();

    // Search möbuleikar fyrir scientists
    void searchName();
    void searchDateOfBirth();
    void searchGender();
    void searchRandomScientist();

    void stats();

    void displayScientistComputerConnections();
    void displayComputerScientistConnections();

    void listScientistConnections();
    void listComputerConnections();
};

#endif // CONSOLEUI_H
