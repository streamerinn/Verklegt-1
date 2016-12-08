#include "scientistdatabase.h"
#include <sstream>
#include <iostream>

using namespace std;

//Default constructor
ScientistDatabase::ScientistDatabase()
{
    QString connectionName = "scientistDB";
    dbName = "Skil2DB.sqlite";
    if(!connectionCheck(connectionName))
    {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName(dbName);
        db.open();
    }
    else
    {
        db = QSqlDatabase::database(connectionName);
    }
}
//Destructor
ScientistDatabase::~ScientistDatabase()
{
    QSqlDatabase::removeDatabase(dbName);
    db.close();
}

bool ScientistDatabase::connectionCheck(QString name)
{
    bool connected;
    if(QSqlDatabase::contains(name))
    {
        connected = true;
    }
    else
    {
        connected = false;
    }
    return connected;
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

void ScientistDatabase::deleteScientist(int id)
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists where ID = ?");

    // herna er verið ad replacea "?" med ID breytunni
    query.addBindValue(id);

    // execute query
    query.exec();
}

/*
void ScientistDatabase::editScientistName(int id){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET name=")
}
*/


void ScientistDatabase::editScientist(int id)
{
   QSqlQuery query;
   query.prepare("UPDATE scientists SET name=' ', gender= ' ', birthDate = '0', deathDate = '0' WHERE ID = ?");
    // aaaaaaaaaaaaaaaa klara
   query.addBindValue(id);

   query.exec();
}

