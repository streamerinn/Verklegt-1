#include <iostream>
#include <string>
#include "consoleui.h"

using namespace std;

const char TAB = '\t';

//efsta lagið

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
    cout << TAB <<"--------------------------------------------" << endl;
    cout << endl;

    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "The list below shows you all possible features on what you can do." << endl;
    cout << endl;

    // Menu list
    cout << TAB << "Press 1 to create a new scientist." << endl;
    cout << TAB << "Press 2 to list all scientists." << endl;
    cout << TAB << "Press 3 to search for a scientist." << endl;
    cout << TAB << "Press Q to quit the program." << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}

void ConsoleUI::displayListOfScientists()
{
    vector<Scientist> scientists = _service.getScientists();

    for(size_t i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i].getName() << endl;
        cout << scientists[i].getGender() << endl;
        cout << scientists[i].getDateOfBirth() << endl;
        cout << scientists[i].getDateOfDeath() << endl;
    }
}
/*
istream& operator >> (istream& in, Scientist& rhs) //overload-ar cin operatorinn;
{
    in >> rhs._name;
    in >> rhs._gender;
    in >> rhs._dateOfBirth;
    in >> rhs._dateOfDeath;

    return in;
}
/*
/*
void ConsoleUI::readScientists(vector <Scientist> &scientists)
{
    Scientist temp;

    cout << "Reading Scientists: " << endl;

    cout << "Please enter a name: " << endl;
    cin >> temp._name;
    cout << "Please enter the gender: " << endl;
    cin >> temp._gender;
    cout << "Please enter date of birth: " << endl;
    cin >> temp._dateOfBirth;
    cout << "Please enter death date: " << endl;
    cin >> temp._dateOfDeath;
    scientists.push_back(temp);
    cout << endl;
}
*/
void ConsoleUI::createScientist()
{
     int choice;
     cin >> choice;

     if(choice == 2)
     {
        displayListOfScientists();
     }
     else if(choice == 1)
     {
        //readScientists(scientists);
        //_service.addScientist();
     }
}
