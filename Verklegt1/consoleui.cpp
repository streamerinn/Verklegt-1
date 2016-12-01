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

}

void ConsoleUI::features()
{
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << TAB << "The list below shows you all possible features on what you can do." << endl;
    cout << endl;

    cout << TAB << "press H to show all options" << endl; //eitthvað svona er sniðgt;
    cout << TAB << "Press 1 to create a new scientist." << endl;
    cout << TAB << "Press 2 to list all scientists." << endl;
    cout << TAB << "Press 3 to search for a scientist." << endl;
    cout << TAB << "Press 4 to search for scientist born in specific year." << endl;
    cout << TAB << "Press 5 to display list of males or females" << endl;
    cout << TAB << "Press Q to quit the program." << endl;
    cout << TAB << "----------------------------------------------------------------------------" << endl;
    cout << endl;

   /* vector<Scientist> temp = service.getScientists();
    // testing txt file
    cout << "\t |Name: " << temp[0].getName() << endl;
    cout << "\t |Gender: " << temp[0].getGender() << endl;
    cout << "\t |Born: " << temp[0].getDateOfBirth() << endl;
    cout << "\t |Died: " << temp[0].getDateOfDeath() << endl;
    // no longer testing txt*/
}


void ConsoleUI::readScientists()
{
    Scientist temp;

    //vector<Scientist> scientists = service.getScientists();

    cout << "Reading Scientists: " << endl;

    string tempName;
    cout << "Please enter a name: " << endl;
    cin.ignore(64,'\n');
    do
    {
        if(tempName.empty())
        {
            getline(cin, tempName);
            cout << "You cannot enter a empty name. Please try again: " << endl;
        }
    }while(tempName.empty());


    temp.setName(tempName);

    string tempGender;
    char gender;
        cout << "Please enter the gender(M for male, F for female): " << endl;
        cin >> gender;
        if(gender == 'M'||gender=='m')
        {
            tempGender = "Male";
            temp.setGender(tempGender);
        }
        else if(gender == 'F'||gender == 'f')
        {
            tempGender = "Female";
            temp.setGender(tempGender);
        }

    int tempDateOfBirth;
    int tempDateOfDeath;
    cout << "Please enter date of birth: " << endl;

    do
    {
        cin >> tempDateOfBirth;
        if(tempDateOfBirth > 2016)
        {
            cout << "Invalid date. Please try again: " << endl;
        }
        else if(tempDateOfBirth < 0)
        {
            cout << "A person cannot have a negative date of birth. Please try again: " << endl;
        }
    }while(tempDateOfBirth > 2016 || tempDateOfBirth < 0);

    temp.setDateOfBirth(tempDateOfBirth);

    cout << "Please enter date of death(Enter 13337 if the scientist is still alive): " << endl;

    do
    {
        cin >> tempDateOfDeath;
        if(tempDateOfDeath < tempDateOfBirth)
        {
            cout << "Not possible. A person cannot die before it is born. Please try again: " << endl;
        }
        else if(tempDateOfDeath == 13337)
        {
            std::string s = std::to_string(tempDateOfDeath);
        }
    }while(tempDateOfDeath < tempDateOfBirth);

    temp.setDateOfDeath(tempDateOfDeath);

    cout << endl;

    char cont;
    cout << "Do you want to add another scientist? Press Y/y for yes or N/n for no: ";
    cin >> cont;
    if(cont == 'y' || cont == 'Y')
    {
        readScientists();
    }
    else
    {
        features();
    }

    //scientists.push_back(temp);

    //flytur upplýsingar inn í ScientistService
    service.create(temp);
}

void ConsoleUI::displayListOfScientists()
{
    vector<Scientist> scientists = service.getScientists();
     cout << "\t information about all listed scientist" << endl;
     cout << "\t___________________________________________________________________________" << endl;
     for(size_t i = 0; i < scientists.size(); i++)
     {
         cout << "\t |Name: " << scientists[i].getName() << endl;
         cout << "\t |Gender: " << scientists[i].getGender() << endl;
         cout << "\t |Born: " << scientists[i].getDateOfBirth() << endl;
         cout << "\t |Died: " << scientists[i].getDateOfDeath() << endl;
         cout << TAB << "----------------------------------------------------------------------------" << endl;
     }
 }

void ConsoleUI::displayListOfScientistsYoung()
{
    vector<Scientist> scientists = service.getScientistsYoung();
    cout << "\t information about all listed scientist" << endl;
    cout << "\t___________________________________________________________________________" << endl;
    for(size_t i = 0; i < scientists.size(); i++)
    {
        cout << "\t |Name: " << scientists[i].getName() << endl;
        cout << "\t |Gender: " << scientists[i].getGender() << endl;
        cout << "\t |Born: " << scientists[i].getDateOfBirth() << endl;
        cout << "\t |Died: " << scientists[i].getDateOfDeath() << endl;
        cout << TAB << "----------------------------------------------------------------------------" << endl;
    }
}

void ConsoleUI::displayListOfScientistsOld()
{
    vector<Scientist> scientists = service.getScientistsOld();
    cout << "\t information about all listed scientist" << endl;
    cout << "\t___________________________________________________________________________" << endl;
    for(size_t i = 0; i < scientists.size(); i++)
    {
        cout << "\t |Name: " << scientists[i].getName() << endl;
        cout << "\t |Gender: " << scientists[i].getGender() << endl;
        cout << "\t |Born: " << scientists[i].getDateOfBirth() << endl;
        cout << "\t |Died: " << scientists[i].getDateOfDeath() << endl;
        cout << TAB << "----------------------------------------------------------------------------" << endl;
    }
}

void ConsoleUI::listOrSortScientist() //vantar meira lýsandi nafn á fallinu
{
    char choice;

    while(choice != 'q' && choice != 'Q')
    {
        vector<Scientist> temp = service.getScientists();
        cin >> choice;

        if(choice == 'h' || 'H')
        {
            features();
        }


        if(choice == '2')
        {

            char sort;
            cout << TAB << "How should the list be sorted?" << endl;
            cout << TAB << "Press 1 for alphabetical order." << endl;
            cout << TAB << "Press 2 to sort from youngest to oldest." << endl;
            cout << TAB << "Press 3 to sort from oldest to youngest." << endl;
            cout << TAB << "" << endl;
            cout << TAB << "----------------------------------------------------------------------------" << endl;

            cin >> sort;

            if(sort == '1')
            {
                displayListOfScientists();
            }
            if(sort == '2')
            {
                displayListOfScientistsYoung();
            }
            if(sort == '3')
            {
                displayListOfScientistsOld();
            }
        }
        else if(choice == '1')
        {
            readScientists();
        }
        else if(choice == '3')
          {

              string nafn;
              cout << "Enter name of scientists you want to find: ";
              cin >> nafn;
              int counter = 0;
              cout << "\t information about requested scientist" << endl;
              cout << "\t___________________________________________________________________________" << endl;
              for(size_t i = 0; i<temp.size() ;i++)
              {
                  if(temp[i].getName()== nafn)
                  {
                      cout << "\t |Name: " << temp[i].getName() << endl;
                      cout << "\t |Gender: " << temp[i].getGender() << endl;
                      cout << "\t |Born: " << temp[i].getDateOfBirth() << endl;
                      cout << "\t |Died: " << temp[i].getDateOfDeath() << endl;
                      counter ++;
                  }

              }
              if(counter == 0)
              {
                  cout << "No scientist name " << nafn << " in our data, try again" << endl;
              }

          }
          else if(choice == '4')
          {
              int year = 0;
              cout << "Enter the the year of birth of the Scientist: ";
              cin >> year;
              int counter = 1;
              cout << "\t All scientist born in year"<< year << endl;
              cout << "\t___________________________________________________________________________" << endl;
              for(size_t i = 0; i < temp.size(); i++)
              {
                  if(year==temp[i].getDateOfBirth())
                  {
                      cout << "\t |Scientist " << counter << " Born in year " << year << endl;
                      cout << "\t |Name: " <<temp[i].getName() << endl;
                      cout << "\t |Gender: " <<temp[i].getGender() << endl;
                      cout << "\t |Born: " <<temp[i].getDateOfBirth() << endl;
                      cout << "\t |Died: "<<temp[i].getDateOfDeath() << endl;
                      counter ++;
                  }
              }
              if(counter == 1)
              {
                  cout << "No Scientist in our data born that year, try again" << endl;
              }
          }
          else if(choice == '5')
          {
              char sex;
              cout << "Press F for list of females." << endl;
              cout << "Press M for list of males." << endl;
              cin >> sex;

              if(sex == 'F'||sex=='f')
              {
                  int counter = 1;
                  cout << "\t All women in our data" << endl;
                  cout << "\t___________________________________________________________________________" << endl;
                  for(size_t i = 0; i < temp.size();i++)
                  {
                      if(temp[i].getGender()=="Female")
                      {
                          cout << "\t|  Scientist #" << counter << endl;
                          cout << "\t|  Name: " << temp[i].getName() << endl;
                          cout << "\t|  Born: " << temp[i].getDateOfBirth() << endl;
                          cout << "\t|  Died: " << temp[i].getDateOfDeath() << endl;
                          cout << "\t| " << endl;
                          counter++;
                      }
                  }
              }
              else if(sex=='M'||sex=='m')
              {
                  int counter = 1;
                  cout << "\t All men in our data" << endl;
                  cout << "\t___________________________________________________________________________" << endl;
                  for(size_t i = 0; i < temp.size();i++)
                  {
                      if(temp[i].getGender()=="Male")
                      {
                          cout << "\t|  Scientist #" << counter << endl;
                          cout << "\t|  Name: " << temp[i].getName() << endl;
                          cout << "\t|  Born: " << temp[i].getDateOfBirth() << endl;
                          cout << "\t|  Died: " << temp[i].getDateOfDeath() << endl;
                          cout << "\t| " << endl;
                          counter++;
                      }
                  }
              }
          }
      }
  }
