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

//To check if the database is connected.
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

//Adds a connection to the Connections table.
bool ConnectionDataBase::insertRow(vector<int> IDs)
{
    QSqlQuery query(db);

    QString scientists = QString::number(IDs[0]);
    QString computers = QString::number(IDs[1]);

    query.prepare("INSERT INTO Connections (scientistsID, computersID) VALUES (:scientists, :computers)");
    query.bindValue(":scientists", scientists);
    query.bindValue(":computers", computers);
    query.exec();

    return true;
}

//Counts the connections in the Connections table.
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

//Deletes a connection between scientists and computers.
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

vector<Scientist> ConnectionDataBase::getConnectionIDs()
{
    vector<int> connectionIDs;

    //Scientist vector is used so we don't need a new class.
    vector<Scientist> bothScientistsAndComputers;

    QSqlQuery query(db);
    query.exec("Select Scientists.id, Scientists.name, Computers.id, Computers.name FROM Scientists , Computers , Connections WHERE Connections.scientistsID = Scientists.id AND Connections.computersID = Computers.id");

    while (query.next())
    {
        Scientist scientist;
        Scientist computer;

        scientist.setID(query.value(0).toUInt());
        computer.setID(query.value(2).toUInt());

        scientist.setName(query.value(1).toString().toStdString());
        computer.setName(query.value(3).toString().toStdString());

        bothScientistsAndComputers.push_back(scientist);
        bothScientistsAndComputers.push_back(computer);
    }

    return  bothScientistsAndComputers;
}




