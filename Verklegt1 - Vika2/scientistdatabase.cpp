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



    //query.exec("INSERT INTO Scientists (Name, Gender, Born, Died)" + "VALUES ('" + name + "','" + gender + "','" + birth + "','" + death + "')");
    //query.prepare("INSERT INTO Scientists (Name, Gender, Born, Died) VALUES (:name, :gender, :born, :died)");

    //query.bindValue(":name",QString::fromStdString(scientist.getName()));
    //query.value("name").toString().toStdString() = scientist.getName();
    //query.value("gender").toString().toStdString() = scientist.getGender();
    //query.value("birthDate").toUInt() = scientist.getDateOfBirth();
    //query.value("deathDate").toUInt() = scientist.getDateOfDeath();

    //query.exec();

     //upplýsingar um scientist koma hingað og eru síðan settar inn í gagnasagnið


}



