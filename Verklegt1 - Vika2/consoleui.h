#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>

#include "scientistservice.h"
#include "scientist.h"
#include "computerservice.h"
#include "computer.h"
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

    /*** Display functions ***/

    // displays scientists
    void display(vector<Scientist> scientists);
    // displays computers
    void displayComputers(vector<Computer> computers);

    // Displays informations about how the user can sort.
    void displaySortOptions(); // Scientist
    void displayComputerSortOptions(); // Computer

    // Display all Scientists lists.
    void displayListOfComputersAlpha();
    void displayListOfComputersReversedAlpha();
    void displayListOfComputersYoung();
    void displayListOfComputersOld();

    // Display allan Computers list.
    void displayListOfScientistsAlpha();
    void displayListOfScientistsReversedAlpha();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();

    void stats();

    // Displays the computers and which scientist are connected.
    void displayScientistComputerConnections();
    // Displays the scientists are connected to which computer.
    void displayComputerScientistConnections();

    // Shows all connections for both computers and scientists.
    void listScientistConnections();
    void listComputerConnections();

    /***Display functions come to an end***/

    //

    // Read input from user to create scientists and computers.
    void readComputers();
    void readScientists();   

    // Functions that change the information in database.
    void deleteOptions();
    void editOptions();
    void link(); // connectar scientist við computer

    /***Search functions***/

    // Search possibilities for computers.
    void searchComputer();
    void searchBuiltYear();
    void searchComputerType();
    void searchRandomComputer();
    void searchBuilt();

    // Search possibilities for scientists
    void searchName();
    void searchDateOfBirth();
    void searchGender();
    void searchRandomScientist();

};

#endif // CONSOLEUI_H
