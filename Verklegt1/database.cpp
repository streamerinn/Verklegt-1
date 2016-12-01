#include "database.h"
#include <sstream>
#include <iostream>

using namespace std;

//Default constructor
DataBase::DataBase()
{

}

// TODO: sækja úr textaskrá og skrifa í vector EINU SINNI
// Það er dýrt að skrifa í og sækja ur textaskrá svo að það er best að takmarka það
vector<Scientist> DataBase::readingTxt()
{
    vector<Scientist> scientistVector;
    string line;
    string name;
    string gender;
    string dateOfBirth;
    string dateOfDeath;

    ifstream info("C:\\Coding\\Qt\\Verklegt-1-master\\Verklegt-1\\Verklegt1\\list.txt");
    //les inn upplýsingar úr textaskjalinu
    if(info.is_open())
    {
        while(!info.eof())
        {
            while(getline(info, line))
            {
                stringstream linestream(line);
                getline(linestream, name, ',');
                getline(linestream, gender, ',');
                getline(linestream, dateOfBirth, ',');
                getline(linestream, dateOfDeath, ',');

                Scientist tempScientist(name, gender, stoi(dateOfBirth), stoi(dateOfDeath));

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
    outputFile.open("C:/Users/Leifur/Documents/Skolinn/VerklegtNamsskeid/Verklegt-1/build-LayeredArchitecture-Desktop_Qt_5_7_0_MinGW_32bit-Debug", ios::app);

    outputFile << scientist.getName() << " " << scientist.getSecondName() << endl;
    outputFile << scientist.getGender() << endl;
    outputFile << scientist.getDateOfBirth() << endl;
    outputFile << scientist.getDateOfDeath() << endl;
}

