#include <iostream>
#include <string>
#include "consoleui.h"
#include "performer.h"

using namespace std;

//efsta lagið

ConsoleUI::ConsoleUI()
{

}

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
        //readScientists();
        //_service.addPerformer();
     }
}

void ConsoleUI::displayListOfScientists()
{
    vector<Performer> performers = _service.getPerformers();

    for(size_t i = 0; i < performers.size(); i++)
    {
        cout << performers[i].getName() << endl;
        cout << performers[i].getGender() << endl;
        cout << performers[i].getDateOfBirth() << endl;
        cout << performers[i].getDateOfDeath() << endl;
    }
}

void ConsoleUI::readScientists(vector <Performer> &performers)
{

    Performer temp;

    cout << "Reading Scientists: " << endl;

    cout << "Please enter a name: " << endl;
    cin >> temp.getName();
    cout << "Please enter the gender: " << endl;
    cin >> temp.getGender();
    cout << "Please enter date of birth: " << endl;
    cin >> temp.getDateOfBirth();
    cout << "Please enter death date: " << endl;
    cin >> temp.getDateOfDeath();
    performers.push_back(temp);
    cout << endl;
}


