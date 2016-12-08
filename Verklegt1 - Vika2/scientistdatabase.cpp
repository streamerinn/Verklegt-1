#include "scientistdatabase.h"
#include <sstream>
#include <iostream>

using namespace std;

//Default constructor
ScientistDatabase::ScientistDatabase()
{
    dbName = "Skil2DB.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.open();
}
//Destructor
ScientistDatabase::~ScientistDatabase()
{
    QSqlDatabase::removeDatabase(dbName);
    db.close();
}

vector<Scientist> ScientistDatabase::scientistDB()
{
    vector<Scientist> sVector;

    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int dateOfBirth = query.value("birthDate").toUInt();
        int dateOfDeath;

        if(!query.value("deathDate").isNull())
        {
            dateOfDeath = query.value("deathDate").toUInt();
        }
        else
        {
            dateOfDeath = 0;
        }

        sVector.push_back(Scientist(id, name, gender, dateOfBirth, dateOfDeath));
    }

    return sVector;
}

void ScientistDatabase::insertRow(Scientist scientist)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(scientist.getName());
    QString gender = QString::fromStdString(scientist.getGender());
    QString birth = QString::number(scientist.getDateOfBirth());
    QString death = QString::number(scientist.getDateOfDeath());

    query.prepare("INSERT INTO Scientists (name, gender, birthDate, deathDate) VALUES (:name, :gender, :born, :died)");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":born", birth);
    query.bindValue(":died", death);
    query.exec();
}

void ScientistDatabase::deleteScientist(char id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Scientists where ID = ?");

    // herna er verið ad replacea "?" med ID breytunni
    query.addBindValue(id);

    // execute query
    query.exec();
}



