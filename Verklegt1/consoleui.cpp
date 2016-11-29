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
    vector<Scientist> scientists = service.getScientists();

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
*/

void ConsoleUI::readScientists()
{
    Scientist temp;

    vector<Scientist> scientists = service.getScientists();

    cout << "Reading Scientists: " << endl;

    string tempName;
    cout << "Please enter a name: " << endl;
    cin >> tempName;
    temp.setName(tempName);

    string tempGender;
    cout << "Please enter the gender: " << endl;
    cin >> tempGender;
    temp.setGender(tempGender);

    int tempDateOfBirth;
    cout << "Please enter date of birth: " << endl;
    cin >> tempDateOfBirth;
    temp.setDateOfBirth(tempDateOfBirth);

    int tempDateOfDeath;
    cout << "Please enter death date: " << endl;
    cin >> tempDateOfDeath;
    temp.setDateOfDeath(tempDateOfDeath);

    cout << endl;

    cout << temp.getName();

    cout << scientists[0].getName() << endl;
}

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
         /*string name;
         string gender;
         int dateOfBirth;
         int dateOfDeath;

         // Get name
         cin.ignore();
         cout << "Enter the scientist's name: ";
         getline(cin,name);


         // Get gender
         cout << "Enter the scientist's gender, press m for male and f for female: ";
         cin >> gender;

         // Get date of birth
         cout << "Enter the scientist's date of birth: ";
         cin >> dateOfBirth;

         // Get dateOfDeath
         cout << "Enter the scientist's date of death: ";
         cin >> dateOfDeath;

         Scientist newScientist = Scientist(name, gender, dateOfBirth, dateOfDeath);

         cout << newScientist.getName();*/

         //TODO: Villuchecka og bara senda áfram ef accurate
         //TODO: gera business layer og tengja þetta saman

        readScientists();

        //_service.addScientist();
     }
}
