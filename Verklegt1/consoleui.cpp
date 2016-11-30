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
    cout << TAB << "--------------------------------------------" << endl;
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

void ConsoleUI::readScientists()
{
    Scientist temp;

    //vector<Scientist> scientists = service.getScientists();


    cout << "Reading Scientists: " << endl;

    string tempName;
    string temp2Name;
    cout << "Please enter a name: " << endl;
    cin >> tempName >> temp2Name;
    //getline(cin, tempName);
    //cin.ignore(64,'\n');
    //cin.clear();
    temp.setName(tempName);
    temp.setsecondName(temp2Name);

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

    //scientists.push_back(temp);

    //flytur upplýsingar inn í ScientistService
    service.create(temp);


}

void ConsoleUI::displayListOfScientists()
{
    vector<Scientist> scientists = service.getScientists();

    for(size_t i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i].getName() << " " << scientists[i].getSecondName() << endl;
        cout << scientists[i].getGender() << endl;
        cout << scientists[i].getDateOfBirth() << endl;
        cout << scientists[i].getDateOfDeath() << endl;
    }
}

void ConsoleUI::createScientist() //vantar meira lýsandi nafn á fallinu
{

    char choice;

    while(choice != 'q' && choice != 'Q')
    {
        cin >> choice;

        if(choice == '2')
        {
            displayListOfScientists();
        }
        else if(choice == '1')
        {
            readScientists();
        }
    }
}
