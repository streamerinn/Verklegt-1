#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "consoleui.h"
#include "windows.h"

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
    cout << TAB << TAB << TAB << " famous computer scientists and computers. " << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}
//Menu með updated MAXIMUM THREEDEE
void ConsoleUI::features()
{
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
    cout << TAB << " _____    _____   ____________   ______  _____   _____   _____" << endl;
    cout << TAB << "|\\ __/\\  /\\__ /| |\\ _________/| |\\ ___/\\|\\__ /| |\\ __/\\ /\\__ /|" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0d);
    cout << TAB << "| |  \\ \\/ /  | | | |   ______|/ | |   \\  |  | | | |  | | |  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
    cout << TAB << "| |   \\  /   | | | |  |___/|    | |    \\ |  | | | |  | | |  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
    cout << TAB << "| |    \\/    | | | |   ___|/__  | |  |\\ \\|  | | | |  | | |  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
    cout << TAB << "| |  |\\__/|  | | | |  |______/| | |  | \\    | | | |  |___|  | |" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a);
    cout << TAB << " \\|__|    |__|/   \\|_________|/  \\|__|/ \\___|/   \\|_________|/" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "The list below shows you all possible features on what you can do." << endl;
    cout << endl;
    cout << TAB << "press H to show all options." << endl;
    cout << TAB << "Press 1 to create a new scientist." << endl;
    cout << TAB << "Press 2 to list all scientists." << endl;
    cout << TAB << "Press 3 to search for a scientist." << endl;
    cout << TAB << "Press 4 to get the database stats." << endl;
    cout << TAB << "Press 5 to add a computer." << endl;
    cout << TAB << "Press 6 to list all computers. " << endl;
    cout << TAB << "Press 7 to search for a computer. " << endl;
    cout << TAB << "Press 8 to link Scientists and computers." << endl;
    cout << TAB << "Press 9 to delete or edit a scientist or a computer." << endl;
    cout << TAB << "Press Q to quit the program." << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;
}

void ConsoleUI::readComputers()
{
    Computer temp;

    string tempComputerName = " ";
    int tempYearBuilt;
    char tempBuilt = ' ';
    int tempMade = 0;
    string tempType;

    // Get name.
    cout << TAB << "Please enter a computer name: ";

    getline(cin, tempComputerName);
    while(tempComputerName.empty())
    {
        if(tempComputerName.empty())
        {
            cout << TAB << "You cannot enter an empty computer name. Please try again: ";
            ws(cin);
            getline(cin, tempComputerName);
        }
    }

    temp.setName(tempComputerName);

    // Get computer type.

    bool validType = false;
    int type;

    cout << TAB << "Please enter what type the computer is" << endl;
    cout << TAB << "1. for Mechanical" << endl;
    cout << TAB << "2. for Electronic" << endl;
    cout << TAB << "3. for Tansistor" << endl;

    while(validType == false)
    {
        cout << TAB;
        cin >> type;

        if((type > 3)||(type < 1))
        {
            cout << TAB << type << " is not a valid option" << endl;
            cout << TAB <<"Please enter a valid option: ";
        }
        if(type == 1)
        {
            tempType = "Mechanical";
            temp.setType(tempType);
            validType = true;
        }
        else if(type == 2)
        {
            tempType = "Electronic";
            temp.setType(tempType);
            validType = true;
        }
        else if(type == 3)
        {
            tempType = "Transistor";
            temp.setType(tempType);
            validType = true;
        }
    }
    temp.setType(tempType);

    // Get if the computer was built or not.
    cout << TAB << "Please enter if the computer was built or not(Enter Y for yes or N for no): ";
    cin >> tempBuilt;
    if(tempBuilt == 'y' || tempBuilt == 'Y')
    {
        tempMade = 1;
        cout << TAB << "When was it built? ";
        cin >> tempYearBuilt;
        while(tempYearBuilt > 2016 || tempYearBuilt <= 0)
        {
            cout << TAB << "Not a valid date, try again: ";
            cin >> tempYearBuilt;
        };

        temp.setYearBuilt(tempYearBuilt);
    }
    else
    {
        temp.setYearBuilt(0);
    }

    temp.setBuilt(tempMade);

    cService.create(temp);
}

void ConsoleUI::displayComputers(vector<Computer> computers)
{
    cout << setw(55) << "COMPUTERS" << endl;
    cout << TAB << setw(15) << "Name" <<setw(20) << "Type" <<setw(20)<< "was it built?"
         << setw(20) << "Year made" << endl;
    cout << "\t___________________________________________________________________________" << endl;
    for(size_t i = 0; i < computers.size(); i++)
    {
    cout << TAB << setw(15) << computers[i].getComputerName() << setw(20) << computers[i].getType();
        if(computers[i].getBuilt()==1)
            cout << setw(20) << "Yes";
        else
            cout << setw(20) << "No";

        if(computers[i].getBuilt()== 0)
            cout << setw(20) << "N/A" << endl;
        else
            cout << setw(20) << computers[i].getYearBuilt() << endl;

         cout << "\t---------------------------------------------------------------------------" << endl;
    }
}



void ConsoleUI::displayScientistConnections(vector<Scientist> scientist)
{
    cout << "\t Scientists and ID's"  << endl;
    cout << "\t___________________________" << endl;
    for(size_t i = 0; i < scientist.size(); i++)
    {
    cout << "\t ID: " << scientist[i].getID() << " " << scientist[i].getName() << endl;
    //cout << TAB << "----------------------------------------------------------------------------" << endl;

  }
    cout << TAB << "---------------------------" << endl;

}





void ConsoleUI::searchComputer()
{
    string name;
    cout << TAB << "Enter the name of the Computer you want to find: ";
    cin.ignore();
    getline(cin, name);

    vector<Computer> temp = cService.searchComputerName(name);
    if(temp.size() == 0)
    {
        cout << TAB << "There are no computers with the name" << name << " in our database. Please try again!";

    }
    else
    {
        displayComputers(temp);
    }


}

void ConsoleUI::searchBuiltYear()
{
    int year = 0;
    cout << TAB << "Enter the Computers built year: ";
    cin >> year;

    vector<Computer> temp = cService.searchYearOfBuild(year);
    if (temp.size() == 0)
    {
        cout << TAB << "There are no Computers in our database built " << year << ". Please try again!";
    }

    else
    {
        displayComputers(temp);
    }
}

void ConsoleUI::searchComputerType()
{
    char choice;

    cout << TAB << "Which type of computer do you want to search? " << endl;
    cout << TAB << "Press 'M' for Mechanical" << endl;
    cout << TAB << "Press 'E' for Electronical" << endl;
    cout << TAB << "Press 'T' for Transistor" << endl;
    cin >> choice;



    vector<Computer> temp = cService.searchType(choice);
    if (temp.size() == 0)
    {
        cout << TAB << "No builts found";
    }
    else
    {
        displayComputers(temp);
    }

}

void ConsoleUI::searchBuilt()
{

    char built;


    cout << TAB << "Search by built - (Y/y = Built)(N/n = not built)  " << endl;
    cout << TAB;

    cin >> built;






    vector<Computer> temp = cService.searchBuilt(built);

    displayComputers(temp);
 }


void ConsoleUI::searchRandomComputer()
{
    vector<Computer> temp = cService.searchRandomComputer();
    displayComputers(temp);

}


// Tengja saman scientis(t) við computer(s) og vice versa
void ConsoleUI::link()
{
    bool scientistExists = false;
    bool computerExists = false;
    bool correctSOption = false;
    bool correctCOption = false;

    string scientistName;
    string computerName;

    string scientistOption;
    string computerOption;

    size_t SOption;
    size_t COption;
    int scientistID = 0;
    int computerID = 0;

    vector<int> IDs;

    //while((scientistExists == false) || (computerName == false))
    //{
        while(scientistExists == false)
        {
            cout << TAB << "Pleas enter a scientist name: ";
            ws(cin);
            getline(cin, scientistName);
            vector<Scientist> temp1 = sService.searchName(scientistName);
            if(temp1.size() == 0)
            {
                cout << TAB << "There is no scientist with the name " << scientistName << " in our data, please try again: " << endl;
            }
            else if(temp1.size() > 1)
            {
                cout << TAB << "There is more than one " << scientistName << ". Which one is correct?" << endl;
                cout << TAB <<"-------------------------------------------------------------------------------------" << endl;

                for(size_t i = 0; i < temp1.size(); i++)
                {

                    if(temp1[i].getDateOfDeath() == 0)
                    {
                        cout << TAB << i+1 << setw(15) << temp1[i].getName() << setw(15) << temp1[i].getGender() << setw(15) << temp1[i].getDateOfBirth();
                        cout << setw(15) << "Alive" << endl;
                    }
                    else
                    {
                        cout << TAB  << i+1 << setw(15) << temp1[i].getName() << setw(15) << temp1[i].getGender();
                        cout << setw(15) << temp1[i].getDateOfBirth() << setw(15) << temp1[i].getDateOfDeath() << endl;
                    }
                    cout << TAB <<"-------------------------------------------------------------------------------------" << endl;
                }

                while(correctSOption == false)
                {
                    cout << TAB << "Please enter the correct number: ";
                    cin >> SOption;


                    if(SOption > temp1.size() || SOption < 1 || !cin)
                    {
                        cout << TAB << "That is not a valid number, please try again" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        scientistID = temp1[SOption-1].getID();
                        correctSOption = true;
                        scientistExists = true;
                    }
                }
            }
            else
            {                                
                scientistID = temp1[0].getID();
                scientistExists = true;
            }
        }



        while(computerExists == false)
        {
            cout << TAB << "Please enter a computer name: ";
            ws(cin);
            getline(cin, computerName);
            vector<Computer> temp2 = cService.searchComputerName(computerName);
            if(temp2.size() == 0)
            {
                cout << TAB << "There is no scientist with the name " << computerName << " in our data, please try again: " << endl;
            }
            else if(temp2.size() > 1)
            {
                cout << TAB << "There is more than one " << computerName << ". Which one is correct?" << endl;
                cout << TAB <<"-------------------------------------------------------------------------------------" << endl;

                for(size_t i = 0; i < temp2.size(); i++)
                {
                    cout << TAB << i+1 << setw(15) << temp2[i].getComputerName() << setw(20) << temp2[i].getType();

                    if(temp2[i].getBuilt()==1)
                        cout << setw(20) << "Yes";
                    else
                        cout << setw(20) << "No";

                    if(temp2[i].getBuilt()== 0)
                        cout << setw(20) << "N/A" << endl;
                    else
                        cout << setw(20) << temp2[i].getYearBuilt() << endl;
                }

                while(correctCOption == false)
                {
                    cout << TAB << "Please enter the correct number: ";
                    cin >> COption;

                    if(COption > temp2.size() || COption < 1 || !cin)
                    {
                        cout << TAB << "That is not a valid number, please try again" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    else
                    {
                        computerID = temp2[COption-1].getID();
                        correctCOption = true;
                        computerExists = true;
                    }
                }
            }

            else
            {
                computerID = temp2[0].getID();
                computerExists = true;
            }
        }


        // sækir ID-in
        //scientistID = sService.searchID(scientistName);
        //computerID = cService.searchID(computerName);
        //scientistID = temp1[SOption-1];
        //computerID = temp2[COption-1];

        IDs.push_back(scientistID);
        IDs.push_back(computerID);

        // sendir ID-in í connection service
        coService.getIDs(IDs);
    //}
}

void ConsoleUI::readScientists()
{
    Scientist temp;

    string tempName;
    cout << TAB << "Please enter a name: ";

    getline(cin, tempName);
    do
    {
        if(tempName.empty())
        {
            cout << TAB << "You cannot enter an empty name. Please try again: ";
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
    cout << TAB << "Please enter a year of birth: ";
    cin >> tempDateOfBirth;

    do
    {
        if(tempDateOfBirth > 2016)
        {
            cout << TAB << "Invalid date. Please try again: ";
            cin >> tempDateOfBirth;
        }
        else if(tempDateOfBirth < 0)
        {
            cout << TAB << "A person cannot have a negative date of birth. Please try again: ";
            cin >> tempDateOfBirth;
        }
     }while(tempDateOfBirth > 2016 || tempDateOfBirth < 0);

    do
    {
        if(tempDateOfBirth > 2016)
        {
            cout << TAB << "Invalid date. Please try again: ";
            cin >> tempDateOfBirth;
        }
        else if(tempDateOfBirth < 0)
        {
            cout << TAB << "A person cannot have a negative date of birth. Please try again: ";
            cin >> tempDateOfBirth;
        }
     }while(tempDateOfBirth > 2016 || tempDateOfBirth < 0);

     do
     {
        if(!cin)
        {
            while((!cin))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << TAB << "That is not a date, please try again: ";
                cin >> tempDateOfBirth;
            }
        }
    }while(tempDateOfBirth > 2016 && tempDateOfBirth < 0);

    temp.setDateOfBirth(tempDateOfBirth);

    cout << TAB << "Please enter a year of death(Enter 0 if the scientist is still alive): ";
    cin >> tempDateOfDeath;

    do
    {
        if(!cin)
        {
            while((!cin))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << TAB << "Invalid date, that is not a year, try again: ";
                cin >> tempDateOfDeath;
            }
        }
        else if((tempDateOfBirth > tempDateOfDeath) && (tempDateOfDeath != 0))
        {
            cout << TAB << "Not possible. A person cannot die before it is born, try again: ";
            cin >> tempDateOfDeath;
        }
        else if(tempDateOfDeath > 2016 && (tempDateOfDeath != 0))
        {
            cout << TAB << "Not possibe. A person cannot die beyond the current year, try again: ";
            cin >> tempDateOfDeath;
        }
        else
        {
            break;
        }

    }while((tempDateOfBirth > tempDateOfDeath) || ((tempDateOfDeath > 2016) && (tempDateOfDeath != 0)));

    temp.setDateOfDeath(tempDateOfDeath);
    cout << endl;

    sService.create(temp);

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
}

void ConsoleUI::display(vector<Scientist> scientists)
{
    {
        cout << setw(55) << "SCIENTISTS" << endl;
        cout << TAB <<"-------------------------------------------------------------------------------------" << endl;
        cout << TAB << setw(15) << "Name" <<setw(15) << "Gender" <<setw(15 )<< "Born"
             << setw(15) << "Died" << setw(20) << "Age" << endl;
        cout << TAB <<"-------------------------------------------------------------------------------------" << endl;
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

            if(scientists[i].getDateOfDeath() == 0)
            {
                cout << TAB << setw(15) << scientists[i].getName() << setw(15) << scientists[i].getGender() << setw(15) << scientists[i].getDateOfBirth();
                cout << setw(15) << "Alive" << setw(20) << tempAge << endl;
            }
            else
            {
                cout << TAB << setw(15) << scientists[i].getName() << setw(15) << scientists[i].getGender();
                cout << setw(15) << setw(15) << scientists[i].getDateOfBirth() << setw(15) << scientists[i].getDateOfDeath() << setw(20) << "age when died " << tempAge << endl;
            }

            cout << TAB << setw(15) <<"-------------------------------------------------------------------------------------" << endl;
        }
    }
}

void ConsoleUI::displayListOfComputersAlpha()
{
    vector<Computer> computers = cService.getComputersAlpha();
    displayComputers(computers);
}

void ConsoleUI::displayListOfComputersReversedAlpha()
{
    vector<Computer> computers = cService.getComputersReversedAlpha();
    displayComputers(computers);
}


void ConsoleUI::displayListOfComputersYoung()
{
    vector<Computer> computers = cService.getComputersYoung();
    displayComputers(computers);
}

void ConsoleUI::displayListOfComputersOld()
{
    vector<Computer> computers = cService.getComputersOld();
    displayComputers(computers);
}


void ConsoleUI::displayListOfScientistsAlpha()
{
    vector<Scientist> scientists = sService.getScientistsAlpha();
    display(scientists);
}

void ConsoleUI::displayListOfScientistsReversedAlpha()
{
    vector<Scientist> scientists = sService.getScientistsReversedAlpha();
    display(scientists);
}


void ConsoleUI::displayListOfScientistsYoung()
{
    vector<Scientist> scientists = sService.getScientistsYoung();
    display(scientists);
}

void ConsoleUI::displayListOfScientistsOld()
{
    vector<Scientist> scientists = sService.getScientistsOld();
    display(scientists);
}

void ConsoleUI::searchName()
{
     string name;
     cout << TAB << "Enter the name of the scientist you want to find: ";
     cin.ignore();
     getline(cin, name);

     vector<Scientist> temp = sService.searchName(name);
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

    vector<Scientist> temp = sService.searchDateOfBirth(year);
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

    vector<Scientist> temp = sService.searchGender(gender);
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

void ConsoleUI::deleteOptions()
{
    char deleteButton;
    int id;

    cout << TAB << "Press 1 to delete a scientist. " << endl;
    cout << TAB << "Press 2 to delete a computer. " << endl;
    cout << TAB;
    cin >> deleteButton;

    if(deleteButton == '1')
    {
        cout << TAB << "Enter ID of scientist to delete: ";
        cin >> id;
        sService.deleteScientist(id);
    }

    else if(deleteButton == '2')
    {
        cout << TAB << "Enter ID of computer to delete: ";
        cin >> id;
        cService.deleteComputer(id);
        //cout << cService.deleteComputer(id);
    }
}


void ConsoleUI::editName()
{
    /*
    cout << "Please enter your current name: ";
    cin >> name;
    if(name == )
    */
}

void ConsoleUI::editOptions()
{
    char editButton;
    int id;

    cout << TAB << "Press 1 to edit a scientist. " << endl;
    cout << TAB << "Press 2 to edit a computer. " << endl;
    cout << TAB;
    cin >> editButton;
    // #Edit scientist:
    if(editButton == '1')
    {
        editName();

        //sService.editScientist(id);
        // cout Edit what?
        //cout << "Please edit name.";


        //if(what == name){
            //editScientist(id, newname);




       // cout << TAB << "Enter ID of scientist to edit: ";
        //cin >> id;
        //sService.editScientist(id);
    }
    else if(editButton == '2')
    {
        cout << TAB << "Enter ID of computer to edit: ";
        cin >> id;
        cService.editComputer(id);
    }


}

void ConsoleUI::searchRandomScientist()
{
    vector<Scientist> temp = sService.searchRandom();
    display(temp);
}

void ConsoleUI::stats()
{
    size_t dead;

    vector<Scientist> males = sService.searchGender('M');
    vector<Scientist> females = sService.searchGender('F');
    vector<Scientist> alive = sService.searchDateOfDeath(0);
    vector<Scientist> total = sService.getScientists();
    vector<Computer> computers = cService.getComputers();
    int totalConnections = coService.getConnections();

    dead = total.size() - alive.size();

    cout << TAB << "---------------------------" << endl;
    cout << TAB << "The database consists of:" << endl;
    cout << TAB << males.size() << " male scientists" << endl;
    cout << TAB << females.size() << " female scientists" << endl;
    cout << TAB << alive.size() << " alive scientists" << endl;
    cout << TAB << dead << " dead scientists" << endl;
    cout << TAB << computers.size() << " computers" << endl;
    cout << TAB << totalConnections << " connections" << endl;
    cout << TAB << "----------------------------" << endl << endl;

}

void ConsoleUI::displayComputerSortOptions()
{
    cout << endl;
    cout << TAB << "How should the list be sorted?" << endl;
    cout << TAB << "Press 1 for alphabetical order." << endl;
    cout << TAB << "Press 2 for reversed alphabetical order." << endl;
    cout << TAB << "Press 3 to sort from newer to older." << endl;
    cout << TAB << "Press 4 to sort from older to newest." << endl;
    cout << TAB << "Press any other number to go BACK to the menu." << endl;
    cout << TAB << "" << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB;
}

void ConsoleUI::displaySortOptions()
{
    cout << endl;
    cout << TAB << "How should the list be sorted?" << endl;
    cout << TAB << "Press 1 for alphabetical order." << endl;
    cout << TAB << "Press 2 for reversed alphabetical order." << endl;
    cout << TAB << "Press 3 to sort from youngest to oldest." << endl;
    cout << TAB << "Press 4 to sort from oldest to youngest." << endl;
    cout << TAB << "Press any other number to go BACK to the menu." << endl;
    cout << TAB << "" << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB;
}

void ConsoleUI::listingAndSorting()
{
    string choice = "/0";

    while(choice[0] != 'q' && choice[0] != 'Q')
    {
        vector<Scientist> temp = sService.getScientists();

        cout << TAB << "Please choose a feature: ";
        ws(cin);
        getline(cin, choice);

        if(choice.length() > 1)
        {
            cout << TAB << "invalid input" << endl;
        }
        else
        {
            if(choice[0] == 'h' || choice[0] == 'H')
            {
                features();
            }

            else if(choice[0] == '1')
            {
                cout << endl;
                cout << TAB << ">>> Reading Scientist(s) <<<" << endl << endl;
                readScientists();
            }

            else if(choice[0] == '2')
            {
                char sort;

                displaySortOptions();

                cin >> sort;
                if(sort == '1')
                {
                    displayListOfScientistsAlpha();
                }
                else if(sort == '2')
                {
                    displayListOfScientistsReversedAlpha();
                }
                else if(sort == '3')
                {
                    displayListOfScientistsYoung();
                }
                else if(sort == '4')
                {
                    displayListOfScientistsOld();
                }
                else
                {
                    features();
                }
            }

            else if(choice[0] == '3')
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

            else if(choice[0] == '4')
            {
                stats();
            }
            else if (choice[0] == '5')
            {
                cout << endl;
                cout << TAB << ">>> Reading Computer(s) <<<" << endl << endl;
                readComputers();
            }
            else if (choice[0] == '6')
            {
                char sortComputer;
                displayComputerSortOptions();

                cin >> sortComputer;

                if(sortComputer == '1')
                {
                    displayListOfComputersAlpha();
                }
                else if(sortComputer == '2')
                {
                    displayListOfComputersReversedAlpha();
                }
                else if(sortComputer == '3')
                {
                    displayListOfComputersYoung();
                }
                else if(sortComputer == '4')
                {
                    displayListOfComputersOld();
                }
                else
                {
                    features();
                }
            }
            else if(choice[0] == '7')
            {
                char searchOptions;

                cout << endl;
                cout << TAB << "What do you want to search for?" << endl;
                cout << TAB << "Press 1 to search by Computer's name." << endl;
                cout << TAB << "Press 2 to search for all computers built in a specific year." << endl;
                cout << TAB << "Press 3 to search for all computers of a specific type." << endl;
                cout << TAB << "Press 4 to search for a random Computer." << endl;
                cout << TAB << "Press 5 to search for a built Computer." << endl;
                cout << TAB << "Press any other number to go BACK to the menu." << endl;
                cout << TAB << "" << endl;
                cout << TAB << "----------------------------------------------------------------------------" << endl;
                cout << TAB;

                cin >> searchOptions;

                if(searchOptions == '1')
                {
                    searchComputer();
                }
                else if(searchOptions == '2')
                {
                    searchBuiltYear();
                }
                else if(searchOptions == '3')
                {
                    searchComputerType();
                }
                else if(searchOptions == '4')
                {
                    searchRandomComputer();
                }
                else if(searchOptions == '5')
                {
                    searchBuilt();
                }
                else
                {
                    features();
                }
            }

            else if(choice[0] == '8')
            {
                cout << TAB << ">>> Linking Scientists and Computers <<<" << endl;
                link();

            }
            else if(choice[0] == '9')
            {
                char option;
                cout << TAB << "Enter 1 to delete a scientist or a computer. " << endl;
                cout << TAB << "Enter 2 to edit a scientist or a computer. " << endl;
                cout << TAB;
                cin >> option;

                if(option == '1')
                {
                    deleteOptions();
                }
                else if(option == '2')
                {
                    editOptions();
                }
            }
            else if(choice[0] == 'q' || choice[0] == 'Q')
            {
                break;
            }
            else
            {
                cout << TAB << "invalid input" << endl;
            }
        }
    }
}
