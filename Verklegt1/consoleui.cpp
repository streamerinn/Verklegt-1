#include <iostream>
#include <string>
#include <limits>
#include "consoleui.h"

using namespace std;

const char TAB = '\t';

ConsoleUI::ConsoleUI()
{
    WelcomeMenu();
}

void ConsoleUI::WelcomeMenu()
{
    cout << endl;
    cout << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << TAB << TAB << " Welcome! This program will store or show" << endl;
    cout << TAB << TAB << TAB << "      famous computer scientists. " << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}

void ConsoleUI::features()
{
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "     ___      ___      __________   ____   ___   ___     ___" << endl;
    cout << TAB << "    /  \\\\    /  \\\\    |   ______|| |   \\\\ |  || |  ||   |  ||" << endl;
    cout << TAB << "   /    \\\\  /    \\\\   |  ||__      |    \\\\|  || |  ||   |  ||" << endl;
    cout << TAB << "  /  /\\  \\\\/  /\\  \\\\  |   ___||    |  |\\ \\|  || |  ||   |  ||" << endl;
    cout << TAB << " /  // \\     // \\  \\\\ |  ||_____   |  ||\\    || |   \\\\_/   ||" << endl;
    cout << TAB << "/__//   \\___//   \\__\\\\|_________|| |__|| \\___||  \\________//" << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "The list below shows you all possible features on what you can do." << endl;
    cout << endl;
    cout << TAB << "press H to show all options" << endl; //eitthvað svona er sniðgt;
    cout << TAB << "Press 1 to create a new scientist." << endl;
    cout << TAB << "Press 2 to list all scientists." << endl;
    cout << TAB << "Press 3 to search for a scientist." << endl;
    cout << TAB << "Press 4 to get the database stats" << endl;
    cout << TAB << "Press Q to quit the program." << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}

void ConsoleUI::readScientists()
{
    Scientist temp;

    string tempName;
    cout << TAB << "Please enter a name: ";

    cin.ignore();
    getline(cin, tempName);
    do
    {
        if(tempName.empty())
        {
            cout << TAB << "You cannot enter a empty name. Please try again: ";
            ws(cin);
            getline(cin, tempName);
        }
    }
    while(tempName.empty());

    temp.setName(tempName);

    bool validGender = false;
    string tempGender;

    string gender;
    cout << TAB << "Please enter the gender(M for male, F for female): ";

    while(validGender == false)
    {       
        ws(cin);
        getline(cin, gender);

        if(gender != "M" && gender != "m" && gender != "F" && gender != "f")
        {
            cout << TAB << gender << " is not a valid option" << endl;
            cout << TAB <<"Please enter a valid option: ";
        }
        if(gender == "M"||gender== "m")
        {
            tempGender = "Male";
            temp.setGender(tempGender);
            validGender = true;
        }
        else if(gender == "F" || gender == "f")
        {
            tempGender = "Female";
            temp.setGender(tempGender);
            validGender = true;
        }
    }

    int tempDateOfBirth = 2017;
    int tempDateOfDeath = -1;
    cout << TAB << "Please enter date of birth: ";

    do
    {
        cin >> tempDateOfBirth;
        if(tempDateOfBirth > 2016)
        {
            cout << TAB << "Invalid date. Please try again: " << endl;
            cin >> tempDateOfBirth;
        }
        else if(tempDateOfBirth < 0)
        {
            cout << TAB << "A person cannot have a negative date of birth. Please try again: " << endl;
            cin >> tempDateOfBirth;
        }
        if(!cin)
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
    while(tempDateOfBirth > 2016 && tempDateOfBirth < 0);


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
                cout << TAB << "Invalid date, that is not a year, try again: " << endl;
                cout << TAB << "Please enter a date of death(Enter 0 if the scientist is still alive): ";
                cin >> tempDateOfDeath;
            }
        }
        else if((tempDateOfDeath < tempDateOfBirth)&&(tempDateOfDeath != 0) && (tempDateOfDeath < 2017))
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
        temp.setDateOfDeath(tempDateOfDeath);

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
    service.create(temp);
}

void ConsoleUI::display(vector<Scientist> scientists)
{
    cout << "\t Information about all listed scientists" << endl;
    cout << "\t___________________________________________________________________________" << endl;
    for(size_t i = 0; i < scientists.size(); i++)
    {
        int tempAge;
        if (scientists[i].getDateOfDeath() != 0)
        {
            tempAge = scientists[i].getDateOfDeath() - scientists[i].getDateOfBirth();
        }
        else
        {
            tempAge = 2016 - scientists[i].getDateOfBirth();
        }

        cout << "\t |Name: " << scientists[i].getName() << endl;
        cout << "\t |Gender: " << scientists[i].getGender() << endl;
        cout << "\t |Born: " << scientists[i].getDateOfBirth() << endl;

        if(scientists[i].getDateOfDeath() == 0)
        {
            cout << "\t |Age: " << tempAge << endl;
            cout << "\t |Still alive " << endl;
        }
        else
        {
            cout << "\t |Died: " << scientists[i].getDateOfDeath() << endl;
            cout << "\t |Died at the age of " << tempAge << endl;
        }

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
        cout << TAB << "There is no scientist in our database with that date of birth, please try again: " << endl;
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
    cout << TAB;

    cin >> gender;

    vector<Scientist> temp = service.searchGender(gender);
    if(temp.size() == 0)
    {
        if(gender == 'M' || gender == 'm')
        {
            cout << TAB << "There are no male scientists. " << endl;
        }
        if(gender == 'F' || gender == 'f')
        {
            cout << TAB << "There are no female scientists. " << endl;
        }
    }
    else
    {
        display(temp);
    }
}

void ConsoleUI::searchRandomScientist()
{
    vector<Scientist> temp = service.searchRandom();
    display(temp);
}

void ConsoleUI::stats()
{
    size_t dead;

    vector<Scientist> males = service.searchGender('M');
    vector<Scientist> females = service.searchGender('F');
    vector<Scientist> alive = service.searchDateOfDeath(0);
    vector<Scientist> total = service.getScientists();

    dead = total.size() - alive.size();

    cout << TAB << "---------------------------" << endl;
    cout << TAB << "The database consists of:" << endl;
    cout << TAB << males.size() << " male scientists" << endl;
    cout << TAB << females.size() << " female scientists" << endl;
    cout << TAB << alive.size() << " alive scientists" << endl;
    cout << TAB << dead << " dead scientists" << endl;
    cout << TAB << "----------------------------" << endl << endl;

}

void ConsoleUI::listOrSortScientist()
{
    string CHOICE = "/0";

    while(CHOICE[0] != 'q' && CHOICE[0] != 'Q')
    {
        vector<Scientist> temp = service.getScientists();

        cout << TAB << "Please choose a feature: ";
        ws(cin);
        getline(cin, CHOICE);

        if(CHOICE.length() > 1)
        {
            cout << TAB << "invalid input" << endl;
        }
        else
        {
            if(CHOICE[0] == 'h' || CHOICE[0] == 'H')
            {
                features();
            }

            else if(CHOICE[0] == '1')
            {
                cout << endl;
                cout << TAB << ">>> Reading Scientists <<<" << endl << endl;
                readScientists();
            }

            else if(CHOICE[0] == '2')
            {
                char sort;
                cout << endl;
                cout << TAB << "How should the list be sorted?" << endl;
                cout << TAB << "Press 1 for alphabetical order." << endl;
                cout << TAB << "Press 2 to sort from youngest to oldest." << endl;
                cout << TAB << "Press 3 to sort from oldest to youngest." << endl;
                cout << TAB << "Press any other number to go BACK to the menu." << endl;
                cout << TAB << "" << endl;
                cout << TAB << "----------------------------------------------------------------------------" << endl;
                cout << TAB;

                cin >> sort;
                if(sort == '1')
                {
                    displayListOfScientistsAlpha();
                }
                else if(sort == '2')
                {
                    displayListOfScientistsYoung();
                }
                else if(sort == '3')
                {
                    displayListOfScientistsOld();
                }
                else
                {
                    features();
                }
            }

            else if(CHOICE[0] == '3')
            {
                char searchOptions;

                cout << endl;
                cout << TAB << "What do you want to search for?" << endl;
                cout << TAB << "Press 1 to search for a scientist witch a specific name." << endl;
                cout << TAB << "Press 2 to search for all scientists born in a specific year." << endl;
                cout << TAB << "Press 3 to search for all scientists with a specific gender." << endl;
                cout << TAB << "Press 4 to search for a random Scientist." << endl;
                cout << TAB << "Press any other number to go BACK to the menu." << endl;
                cout << TAB << "" << endl;
                cout << TAB << "----------------------------------------------------------------------------" << endl;
                cout << TAB;

                cin >> searchOptions;

                if(searchOptions == '1')
                {
                    searchName();
                }
                else if(searchOptions == '2')
                {
                    searchDateOfBirth();
                }
                else if(searchOptions == '3')
                {
                    searchGender();
                }
                else if(searchOptions == '4')
                {
                    searchRandomScientist();
                }
                else
                {
                    features();
                }
            }

            else if(CHOICE[0] == '4')
            {
                stats();
            }
            else
            {
                cout << TAB << "invalid input" << endl;
            }
        }
    }
}

