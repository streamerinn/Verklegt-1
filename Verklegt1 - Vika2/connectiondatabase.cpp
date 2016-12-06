#include "connectiondatabase.h"
#include <iostream>

ConnectionDataBase::ConnectionDataBase()
{
    dbName = "Skil2DB.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.open();
}

int ConnectionDataBase::getcomputerID(int computerID)
{
    cout << "db test: " << computerID << endl;
    return computerID;
}

int ConnectionDataBase::getscientistID(int scientistID)
{
     cout << "db test: " << scientistID << endl;
    return scientistID;
}

void ConnectionDataBase::insertRow()
{
    int scientistID = 0;
    int computerID = 0;


    QSqlQuery query(db);

    QString scientist = QString::number(getscientistID(scientistID));
    QString computers = QString::number(getcomputerID(computerID));


    query.prepare("INSERT INTO Connections (scientists, computers) VALUES (:scientists, :computers)");
    query.bindValue(":scientist", scientist);
    query.bindValue(":computers", computers);
    query.exec();
}
