#include <iostream>
#include <string>
#include <limits>
#include "consoleui.h"

using namespace std;

const char TAB = '\t';

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::WelcomeMenu()
{
    cout << endl;
    cout << endl;
    cout << TAB << "--------------------------------------------" << endl;
    cout << TAB << " Welcome! This program will store or show" << endl;
    cout << TAB << " famous computer scientists. " << endl;
    cout << TAB << "--------------------------------------------" << endl;
    cout << endl;
}

void ConsoleUI::features()
{
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "     __       __      __________   ___    __   __      __" << endl;
    cout << TAB << "    /  \\     /  \\     |   ______| |   \\  |  | |  |    |  |" << endl;
    cout << TAB << "   /    \\   /    \\    |  |___     |    \\ |  | |  |    |  |" << endl;
    cout << TAB << "  /  /\\  \\_/  /\\  \\   |   ___|    |  |\\ \\|  | |  |    |  |" << endl;
    cout << TAB << " /  /  \\     /  \\  \\  |  |______  |  | \\    | |   \\__/   |" << endl;
    cout << TAB << "/__/    \\___/    \\__\\ |_________| |__|  \\___|  \\________/ " << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "The list below shows you all possible features on what you can do." << endl;
    cout << endl;
    cout << TAB << "press H to show all options" << endl; //eitthvað svona er sniðgt;
    cout << TAB << "Press 1 to create a new scientist." << endl;
    cout << TAB << "Press 2 to list all scientists." << endl;
    cout << TAB << "Press 3 to search for a scientist." << endl;
    cout << TAB << "Press Q to quit the program." << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}
void ConsoleUI::readScientists()
{
    Scientist temp;

    string tempName;
    cout << TAB << "Please enter a name: ";
    cin.ignore(64,'\n');
    getline(cin, tempName);
    do
    {
        if(tempName.empty())
        {
            getline(cin, tempName);
            cout << TAB << "You cannot enter a empty name. Please try again: " << endl;
            getline(cin, tempName);
        }
    }
    while(tempName.empty());
    temp.setName(tempName);

    bool validGender = false;
    string tempGender;

    char gender;
    cout << TAB << "Please enter the gender(M for male, F for female): ";

        while(validGender == false)
        {
            cin >> gender;

            if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
            {
                cout << TAB << gender << " That is not a valid option." << endl;
                cout << TAB <<" Please enter a valid option: " << endl;
            }
            if(gender == 'M'||gender=='m')
            {
                tempGender = "Male";
                temp.setGender(tempGender);
                validGender = true;
            }
            else if(gender == 'F'||gender == 'f')
            {
                tempGender = "Female";
                temp.setGender(tempGender);
                validGender = true;
            }
        }
            int tempDateOfBirth;
            int tempDateOfDeath;
            cout << TAB << "Please enter date of birth: ";

            do
            {
                cin >> tempDateOfBirth;
                if(tempDateOfBirth > 2016)
                {
                    cout << TAB << "Invalid date. Please try again: " << endl;
                }
                else if(tempDateOfBirth < 0)
                {
                    cout << TAB << "A person cannot have a negative date of birth. Please try again: ";
                }
                else if(!cin)
                {
                    while((!cin))
                    {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << TAB << "That is not a date, please try again: " << endl;
                    cout << TAB << "Please enter date of birth: ";
                    cin >> tempDateOfBirth;
                    }
                }

            }
            while(tempDateOfBirth > 2016 || tempDateOfBirth < 0);

            temp.setDateOfBirth(tempDateOfBirth);

            cout << TAB << "Please enter a date of death(Enter 0 if the scientist is still alive): ";

            do
           {
                cin >> tempDateOfDeath;
                if(!cin)
                    {
                        while((!cin))
                        {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << TAB << "Invalid date, that is not a year, try again:" << endl;
                        cout << TAB << "Please enter a date of death(Enter 0 if the scientist is still alive): ";
                        cin >> tempDateOfDeath;
                        }
                    }
                else if((tempDateOfDeath < tempDateOfBirth)&&(tempDateOfDeath != 0))
                {
                    cout << TAB << "Not possible. A person cannot die before it is born." << endl;
                    cout << TAB << "Please enter a date of death(Enter 0 if the scientist is still alive): ";
                    cin.clear();
                    cin >> tempDateOfDeath;
                }

            }
            while((tempDateOfDeath < tempDateOfBirth)&&(tempDateOfDeath != 0));

                if(tempDateOfDeath > 2016)
                {
                    cout << TAB << "Not possible. A person cannot die beyond the current year." << endl;
                }

            cout << endl;

            char cont;
            cout << TAB << "Do you want to add another scientist? Press Y/y for yes or N/n for no: ";
            cin >> cont;
            if(cont == 'y' || cont == 'Y')
            {
                readScientists();
            }
            else
            {
                features();
            }

    //flytur upplýsingar inn í ScientistService
    service.create(temp);
}

void ConsoleUI::display(vector<Scientist> scientists)
{
    cout << "\t Information about all listed scientists" << endl;
    cout << "\t___________________________________________________________________________" << endl;
    for(size_t i = 0; i < scientists.size(); i++)
    {
        cout << "\t |Name: " << scientists[i].getName() << endl;
        cout << "\t |Gender: " << scientists[i].getGender() << endl;
        cout << "\t |Born: " << scientists[i].getDateOfBirth() << endl;
        if(scientists[i].getDateOfDeath() == 0)
            cout << "\t |Still alive " << endl;
        else
            cout << "\t |Died: " << scientists[i].getDateOfDeath() << endl;
        cout << TAB << "----------------------------------------------------------------------------" << endl;
    }
}

void ConsoleUI::displayListOfScientistsAlpha()
{
    vector<Scientist> scientists = service.getScientistsAlpha();
    display(scientists);
}

void ConsoleUI::displayListOfScientistsYoung()
{
    vector<Scientist> scientists = service.getScientistsYoung();
    display(scientists);
}

void ConsoleUI::displayListOfScientistsOld()
{
    vector<Scientist> scientists = service.getScientistsOld();
    display(scientists);
}

void ConsoleUI::searchName()
{
     string name;
     cout << TAB << "Enter the name of the scientist you want to find: ";
     cin.ignore();
     getline(cin, name);

     vector<Scientist> temp = service.searchName(name);
     if(temp.size() == 0)
     {
         cout << TAB << "There is no scientist with the name " << name << " in our data, please try again: " << endl;
     }
     else
     {
         display(temp);
     }
}

void ConsoleUI::searchDateOfBirth()
{
    int year = 0;
    cout << TAB << "Enter the scientists year of birth: ";
    cin >> year;

    vector<Scientist> temp = service.searchDateOfBirth(year);
    if(temp.size() == 0)
    {
        cout << TAB << "There is no scientist in our database with that date of birth, please try again:" << endl;
    }
    else
    {
        display(temp);
    }
}

void ConsoleUI::searchGender()
{
    char gender;
    cout << TAB << "Please enter a gender(M for male, F for female): " << endl;

    cin >> gender;

    vector<Scientist> temp = service.searchGender(gender);
    if(temp.size() == 0)
    {
        if(gender == 'M' || gender == 'm')
        {
            cout << TAB << "There are no male scientists, try again:" << endl;
        }
        if(gender == 'F' || gender == 'f')
        {
            cout << TAB << "There are no female scientists, try again:" << endl;
        }
    }
    else
    {
        display(temp);
    }
}

void ConsoleUI::listOrSortScientist()
{
    string choice;

    while(choice != "q" && choice != "Q")
    {
        vector<Scientist> temp = service.getScientists();

        cout << TAB << "Please choose a feature: ";
        cin >> choice;
        cout << endl;

        if(choice == "h" || choice == "H")
        {
            features();
        }

        else if(choice == "1")
        {
            cout << TAB << ">>> Reading Scientists <<<" << endl << endl;
            readScientists();
        }

        else if(choice == "2")
        {
            string sort;
            cout << TAB << "How should the list be sorted?" << endl;
            cout << TAB << "Press 1 for alphabetical order." << endl;
            cout << TAB << "Press 2 to sort from youngest to oldest." << endl;
            cout << TAB << "Press 3 to sort from oldest to youngest." << endl;
            cout << TAB << "Press any other number to go BACK to the menu." << endl;
            cout << TAB << "" << endl;
            cout << TAB << "----------------------------------------------------------------------------" << endl;
            cout << TAB;

            cin >> sort;
            if(sort == "1")
            {
                displayListOfScientistsAlpha();
            }
            else if(sort == "2")
            {
                displayListOfScientistsYoung();
            }
            else if(sort == "3")
            {
                displayListOfScientistsOld();
            }
            else
            {
                features();
            }
        }

        else if(choice == "3")
        {
            int searchOptions = 0;

            cout << TAB << "What do you want to search for?" << endl;
            cout << TAB << "Press 1 to search for a scientist witch a specific name." << endl;
            cout << TAB << "Press 2 to search for all scientists born in a specific year." << endl;
            cout << TAB << "Press 3 to search for all scientists with a specific gender." << endl;

            cout << TAB;
            cin >> searchOptions;

            if(searchOptions == 1)
            {
                searchName();
            }
            else if(searchOptions == 2)
            {
                searchDateOfBirth();
            }
            else if(searchOptions == 3)
            {
                searchGender();
            }
        }
    }
}

