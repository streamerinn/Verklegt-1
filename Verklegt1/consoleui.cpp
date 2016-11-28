#include <iostream>
#include <string>
#include "consoleui.h"

using namespace std;

//efsta lagið

ConsoleUI::ConsoleUI()
{

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
*/

/*void ConsoleUI::readScientists(vector <Scientist> &scientists)
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
void ConsoleUI::run()
{
     cout << "Please enter one of the following commands" << endl;
     cout << "list - This will list all the performances in the system" << endl;
     cout << "add - This will add a new performer" << endl;

     string command;
     cin >> command;

     if(command == "list")
     {
        displayListOfScientists();
     }
     else if(command == "add")
     {
        //readScientists(scientists);
        //_service.addScientist();
     }
}
