#include "database.h"
#include <sstream>
#include <iostream>

using namespace std;

//Default constructor
DataBase::DataBase()
{

}

void DataBase::initTxtFile()
{
    ifstream infoRead("info.txt");

    if(infoRead)
    {
        cout << "Database exists" << endl;
    }
    else    // ef info skráin er ekki til búum við hana til og setjum þetta fólk inn í hana
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

// TODO: sækja úr textaskrá og skrifa í vector EINU SINNI
// Það er dýrt að skrifa í og sækja ur textaskrá svo að það er best að takmarka það
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
    //les inn upplýsingar úr textaskjalinu
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

/*operator DataBase::redd()
{

}*/

// Upplýsingar eru byrjaðar að berast hingað frá consoleu-i
// TODO: bæta scientistum inn í textaskrá
// þetta ætti að gerast (eins og er) þannig að í hvert skipti sem add er keirt er bætt einum scientist inn í skránna
void DataBase::returnInfo(Scientist scientist)
{   
    fstream outputFile;
    outputFile.open("info.txt", ios::app);

    outputFile << scientist.getName() << ',';
    outputFile << scientist.getGender() << ',';
    outputFile << scientist.getDateOfBirth() << ',';
    outputFile << scientist.getDateOfDeath() << endl;
}

