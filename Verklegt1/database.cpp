#include "database.h"

using namespace std;

//Default constructor
DataBase::DataBase()
{

}

// TODO: sækja úr textaskrá og skrifa í vector EINU SINNI
// Það er dýrt að skrifa í og sækja ur textaskrá svo að það er best að takmarka það
vector<Scientist> DataBase::readingTxt()
{
    ifstream info;
    Scientist aScientis;
    info.open("info.txt");
    if(info.is_open())
    {
        /*Scientist temp;
        while(!info.eof())
        {
            savedData.push_back(temp);
        }*/

        /*while(info >> aScientis.getName() >> aScientist.getGender() >> aScientis.getDateOfBirth() >> aScientis.getDateOfDeath())
        {
            savedData.push_back(aScientist);
        }*/
    }
    return savedData;

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

