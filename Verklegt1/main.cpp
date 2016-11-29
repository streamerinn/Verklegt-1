#include "consoleui.h"
#include "Scientist.h"
#include "database.h"

using namespace std;

int main()
{
    ConsoleUI ui;

    ui.WelcomeMenu();
    ui.createScientist();

    return 0;
}
