#include "consoleui.h"

using namespace std;

int main()
{
    DataBase db;
    ConsoleUI ui;

    for(vector<Scientist>::iterator i = db.readingTxt().begin(); i != db.readingTxt().end(); ++i)
    {
        cout << i -> getName() << endl;
    }
    ui.WelcomeMenu();
    ui.features();
    ui.listOrSortScientist();

    return 0;
}
