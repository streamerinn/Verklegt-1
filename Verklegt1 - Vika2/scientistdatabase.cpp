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

    QString Sid;
    Sid = QString::number(id);
    QSqlQuery query(db);

    query.prepare("DELETE FROM Computers where ID = (:Sid)");
    query.bindValue(":Sid", Sid);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        //query.exec();
        qDebug("Deleted!");
    }

}

void ScientistDatabase::editScientist(int id, string gender, string name, int birth, int death)
{
    QString Sid;
    QString birthYear;
    //QString builts(built);
    QString deaths;
    QString names;
    QString genders;

    names = QString::fromStdString(name);
    Sid = QString::number(id);
    birthYear = QString::number(birth);
    //builts()  //QString::char(built);
    genders = QString::fromStdString(gender);
    deaths = QString::number(death);

    QSqlQuery query(db);
    //query.prepare("UPDATE Computers where ID = (:Compid);");
    query.prepare("UPDATE Scientists SET name = (:name), birthDate = (:birthYear), deathDate = (:deaths), gender = (:genders) WHERE id = (:Sid)");
   query.bindValue(":Sid", Sid);
   query.bindValue(":name", names);
   query.bindValue(":birthYear",birthYear);
   query.bindValue(":deaths",deaths);
   query.bindValue(":genders",genders);


    //query.prepare("UPDATE Computers SET name =", [build year] = +buildYears+ ", type =" +types+", builts =" +builts+";");

    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        //query.exec();
        qDebug("Updated!");
    }
}

