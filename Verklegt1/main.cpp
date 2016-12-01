#include "consoleui.h"

using namespace std;

int main()
{
    DataBase db;
    db.initTxtFile();
    ConsoleUI ui;


    ui.WelcomeMenu();
    ui.features();
    ui.listOrSortScientist();

    return 0;
}
