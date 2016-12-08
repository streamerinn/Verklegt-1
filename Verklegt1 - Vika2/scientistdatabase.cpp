#include "scientistdatabase.h"
#include <sstream>
#include <iostream>

using namespace std;

//Constructor
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
//Notað til að checka hvort database-inn sé tengdur
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
//Tekur upplýsingar úr Scientists töflunni og skilar þeim í vector
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
//Bætir scientist í Scientists töfluna
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
//Eyðir scientist úr Scientists töflunni
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



//Breytir scientist í Scientists töflunni
void ScientistDatabase::editScientist(int id)
{
   QSqlQuery query;
   query.prepare("UPDATE scientists SET name=' ', gender= ' ', birthDate = '0', deathDate = '0' WHERE ID = ?");
    // aaaaaaaaaaaaaaaa klara
   query.addBindValue(id);

   query.exec();
}

vector<Scientist> ScientistDatabase::scientistsConnectedToComputers(int computerID)
{
    QSqlQuery query(db);
    vector<Scientist> connectedScientist;

    query.prepare("SELECT b.id, b.name, b.gender, b.birthDate, b.deathDate FROM Connections a, Scientists b WHERE a.computersID = ? AND b.id = a.scientistsID");
    query.addBindValue(computerID);
    query.exec();

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int birthDate = query.value("birthDate").toUInt();
        int deathDate;

        if(!query.value("deathDate").isNull())
        {
            deathDate = query.value("deathDate").toUInt();
        }
        else
        {
            deathDate = 0;
        }

        connectedScientist.push_back(Scientist(id, name, gender, birthDate, deathDate));
    }
    return connectedScientist;
}
