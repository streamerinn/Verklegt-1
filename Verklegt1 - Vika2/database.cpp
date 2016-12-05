#include "database.h"
#include <sstream>
#include <iostream>

using namespace std;

//Default constructor
DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    dbName = "Skil2DB.sqlite";
    db.setDatabaseName(dbName);
}

vector<Scientist> DataBase::readingTxt()
{
    vector<Scientist> sVector;


    //db.setDatabaseName(dbName);

    db.open();
    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int dateOfBirth = query.value("birthDate").toUInt();
        int dateOfDeath = query.value("deathDate").toUInt();

        sVector.push_back(Scientist(id, name, gender, dateOfBirth, dateOfDeath));
    }
    db.close();
    QSqlDatabase::removeDatabase(dbName);

    return sVector;
}

/*vector<Scientist> DataBase::dbScientists(vector<Scientist> sv)
{
    vector<Scientist> scientistVector = sv;

    return scientistVector;
}*/
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

void DataBase::insertTable(Scientist scientist)
{
    db.open();
    QSqlQuery query(db);

    query.exec("INSERT INTO SCIENIST");

     //upplýsingar um scientist koma hingað og eru síðan settar inn í gagnasagnið

    query.value("id").toUInt() = scientist.getId();
    query.value("name").toString().toStdString() = scientist.getName();
    query.value("gender").toString().toStdString() = scientist.getGender();
    query.value("birthDate").toUInt() = scientist.getDateOfBirth();
    query.value("deathDate").toUInt() = scientist.getDateOfDeath();
}




