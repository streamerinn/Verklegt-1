#include "scientistdatabase.h"
#include <sstream>


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

//Used to check if the database is connected or not.
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

// Takes information from Scientists tablet and returns them to a vector.
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

// Adds a scientist to the Scientists table.
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

// Delets a scientist from the Scientists table.
void ScientistDatabase::deleteScientist(int id)
{
    QString Sid;
    Sid = QString::number(id);
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists where ID = (:Sid)");
    query.bindValue(":Sid", Sid);
    query.exec();
}

// Used to edit a scientist.
void ScientistDatabase::editScientist(int id, string gender, string name, int birth, int death)
{
    QString Sid;
    QString birthYear;
    QString deaths;
    QString names;
    QString genders;
    QSqlQuery query(db);

    names = QString::fromStdString(name);
    Sid = QString::number(id);
    birthYear = QString::number(birth);
    genders = QString::fromStdString(gender);
    deaths = QString::number(death);

    query.prepare("UPDATE Scientists SET name = (:name), birthDate = (:birthYear), deathDate = (:deaths), gender = (:genders) WHERE id = (:Sid)");
    query.bindValue(":Sid", Sid);
    query.bindValue(":name", names);
    query.bindValue(":birthYear",birthYear);
    query.bindValue(":deaths",deaths);
    query.bindValue(":genders",genders);
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
