#include "connectiondatabase.h"
#include <iostream> // eða þegar þetta er farið að virka

ConnectionDataBase::ConnectionDataBase()
{
    connectionName = "connectionDB";
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

ConnectionDataBase::~ConnectionDataBase()
{
    QSqlDatabase::removeDatabase(dbName);
    db.close();
}

bool ConnectionDataBase::connectionCheck(QString name)
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

void ConnectionDataBase::insertRow(vector<int> IDs)
{

    QSqlQuery query(db);

    QString scientist = QString::number(IDs[0]);
    QString computers = QString::number(IDs[1]);
    //cout << "INSERT INTO Connections (scientistsID, computersID) VALUES (" << scientist.toStdString()<< ", " << computers.toStdString() << ")" << endl;
    query.prepare("INSERT INTO Connections (scientist, computer) VALUES (:scientist, :computers)");
    query.bindValue(":scientist", scientist);
    query.bindValue(":computers", computers);
    query.exec();
}

int ConnectionDataBase::countConnections()
{
    int counter = 0;

    QSqlQuery query;
    query.exec("SELECT * FROM Connections");

    while (query.next())
    {
        counter++;
    }

    return counter;
}


vector<Scientist> ConnectionDataBase::getidName()
{

    vector<Scientist> temp;
    QSqlQuery query(db);
    query.exec("SELECT * FROM Scientists;");
    //TODO: Laga villu - "unkown field name".
    //      Kemur á fleiri stöðum þar sem ekki er notað SELECT *
    while (query.next())
    {
        int id = query.value("id").toInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int dateOfBirth = query.value("birthDate").toInt();
        int dateOfDeath = query.value("deathDate").toInt();

        Scientist scientist (id, name, gender, dateOfBirth, dateOfDeath);
        temp.push_back(scientist);


    }

    return temp;
}



