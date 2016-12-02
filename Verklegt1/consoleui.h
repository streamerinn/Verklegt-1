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
    //void sortScientist();
    void WelcomeMenu();
    void features();
    void listOrSortScientist();
    //void searchName();
    //void searchDateOfBirth();
    //void searchGender();
    //void searchRandomScientist();
    //void displayList();


private:

    ScientistService service;

    void display(vector<Scientist> scientists);
    void readScientists();

    void displayListOfScientistsAlpha();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();    

    void searchName();
    void searchDateOfBirth();
    void searchGender();
    void searchRandomScientist();
};

#endif // CONSOLEUI_H
