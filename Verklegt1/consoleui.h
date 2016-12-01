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
    void WelcomeMenu();
    void features();
    void listOrSortScientist();
    void searchName();
    void searchDateOfBirth();
    void searchGender();

    friend istream& operator >> (istream& in, Scientist& rhs);

private:
    ScientistService service;

    void display(vector<Scientist> scientists);

    void displayListOfScientists();
    void displayListOfScientistsYoung();
    void displayListOfScientistsOld();
    void readScientists();
};

#endif // CONSOLEUI_H
