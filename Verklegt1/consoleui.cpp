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
        vector<Performer> performers = _service.getPerformers();

        for(size_t i = 0; i < performers.size(); i++)
        {
            cout << performers[i].getName() << endl;
            cout << performers[i].getGender() << endl;
            cout << performers[i].getBorne() << endl;
            cout << performers[i].getDied() << endl;
        }
     }
     else if(command == "add")
     {
        string name;
        int age;

        cin >> name;
        cin >> age;

        Performer newPerformer;

        //_service.addPerformer();
     }
}
