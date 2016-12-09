#include "connectiondatabase.h"
//#include <iostream>

//Constructor
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

//Destructor
ConnectionDataBase::~ConnectionDataBase()
{
    QSqlDatabase::removeDatabase(dbName);
    db.close();
}

//Notað til að checka hvort database-inn sé tengdur
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

//Bætir við connection í Connections töfluna
void ConnectionDataBase::insertRow(vector<int> IDs)
{
    QSqlQuery query(db);

    QString scientists = QString::number(IDs[0]);
    QString computers = QString::number(IDs[1]);

    query.prepare("INSERT INTO Connections (scientistsID, computersID) VALUES (:scientists, :computers)");
    query.bindValue(":scientists", scientists);
    query.bindValue(":computers", computers);
    query.exec();
}

//Telur connections í Connections töflunni
int ConnectionDataBase::countConnections()
{
    int counter = 0;

    QSqlQuery query(db);
    query.exec("SELECT * FROM Connections");

    while (query.next())
    {
        counter++;
    }
    return counter;
}


void ConnectionDataBase::deleteLink(int compID, int sciID)
{

    QString ComputerID;
    QString ScientistID;
    ComputerID = QString::number(compID);
    ScientistID = QString::number(sciID);

    QSqlQuery query(db);
    query.prepare("DELETE FROM Connections WHERE scientistsID = (:ScientistID) AND computersID = (:ComputerID) ");
    query.bindValue(":ComputerID", ComputerID);
    query.bindValue(":ScientistID", ScientistID);
    query.exec();


}




