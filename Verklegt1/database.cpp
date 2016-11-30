#include "database.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Default constructor
DataBase::DataBase()
{

}

// TODO: sækja úr textaskrá og skrifa í vector EINU SINNI
// Það er dýrt að skrifa í og sækja ur textaskrá svo að það er best að takmarka það
void DataBase::getInfo()
{



}

// Upplýsingar eru byrjaðar að berast hingað frá consoleu-i
// TODO: bæta scientistum inn í textaskrá
// þetta ætti að gerast (eins og er) þannig að í hvert skipti sem add er keirt er bætt einum scientist inn í skránna
void DataBase::returnInfo(Scientist scientist)
{   
    fstream outputFile;
    outputFile.open("list.txt", ios::app);

    outputFile << scientist.getName() << " " << scientist.getSecondName() << endl;
    outputFile << scientist.getGender() << endl;
    outputFile << scientist.getDateOfBirth() << endl;
    outputFile << scientist.getDateOfDeath() << endl << endl;
}

