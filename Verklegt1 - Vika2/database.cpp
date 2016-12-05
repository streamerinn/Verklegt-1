#include "database.h"
#include <sstream>
#include <iostream>
#include <QtSql>

using namespace std;

//Default constructor
DataBase::DataBase()
{

}

void DataBase::initTxtFile()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Skil2DB.sqlite";
    db.setDatabaseName(dbName);
    ifstream infoRead("info.txt");

    if(infoRead)
    {
        cout << "Database exists" << endl;
    }
    else    // ef info skráin er ekki til er hún sjálfkrafa búin til og fólki er bætt við.
    {
        fstream info("info.txt", fstream::out);

        info << "Charles Babbage" << ',' << "Male" << ',' << "1791" << ',' << "1871" << endl;
        info << "Ada Lovelace" << ',' << "Female" << ',' << "1815" << ',' << "1852" << endl;
        info << "Donald E. Knuth" << ',' << "Male" << ',' << "1974" << ',' << "0" << endl;
        info << "Edsger W. Dijkstra" << ',' << "Male" << ',' << "1930" << ',' << "2002" << endl;
        info << "Blaise Pascale" << ',' << "Male" << ',' << "1623" << ',' << "1662" << endl;
        info << "Herman Hollerith" << ',' << "Male" << ',' << "1860" << ',' << "1929" << endl;
        info << "Alan Turing" << ',' << "Male" << ',' << "1912" << ',' << "1954" << endl;
        info << "John von Neumann" << ',' << "Male" << ',' << "1903" << ',' << "1957" << endl;
        info << "Margaret Heafield Hamilton" << ',' << "Female" << ',' << "1936" << ',' << "0" << endl;
        info << "Dennis MacAlistair Ritchie" << ',' << "Male" << ',' << "1941" << ',' << "2011" << endl;

        info.close();

        cout << "Database created" << endl;
    }
}

vector<Scientist> DataBase::readingTxt()
{
    vector<Scientist> scientistVector;
    string line;
    string name;
    string gender;
    string dateOfBirthStr;
    string dateOfDeathStr;
    int dateOfBirth;
    int dateOfDeath;

    ifstream info("info.txt");
    //les inn upplýsingar úr textaskjalinu.
    if(info.is_open() && info.good())
    {
        while(!info.eof())
        {
            while(getline(info, line))
            {
                stringstream linestream(line);
                getline(linestream, name, ',');
                getline(linestream, gender, ',');
                getline(linestream, dateOfBirthStr, ',');
                getline(linestream, dateOfDeathStr, ',');

                if(!dateOfBirthStr.empty() && !dateOfDeathStr.empty())
                {
                    dateOfBirth = stoi(dateOfBirthStr);
                    dateOfDeath = stoi(dateOfDeathStr);
                }

                Scientist tempScientist(name, gender, dateOfBirth, dateOfDeath);

                scientistVector.push_back(tempScientist);
            }
        }
    }
    else
    {
        cout << "Unable to open file";
    }

    return scientistVector;
}
// Í hvert skipti sem readScientists er keyrt(í consoleUI) bætist einn scientist við í skrá.
void DataBase::returnInfo(Scientist scientist)
{   
    fstream outputFile;
    outputFile.open("info.txt", ios::app);

    outputFile << scientist.getName() << ',';
    outputFile << scientist.getGender() << ',';
    outputFile << scientist.getDateOfBirth() << ',';
    outputFile << scientist.getDateOfDeath() << endl;
}

