#include "connectiondatabase.h"
#include <iostream> // eða þegar þetta er farið að virka

ConnectionDataBase::ConnectionDataBase()
{
    dbName = "Skil2DB.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.open();
}

void ConnectionDataBase::insertRow(vector<int> IDs)
{
    cout << "database test " << IDs[0] << IDs[1] << endl;

    QSqlQuery query(db);

    QString scientist = QString::number(IDs[0]);
    QString computers = QString::number(IDs[1]);
    //cout << "INSERT INTO Connections (scientistsID, computersID) VALUES (" << scientist.toStdString()<< ", " << computers.toStdString() << ")" << endl;
    query.prepare("INSERT INTO Connections (scientistsID, computersID) VALUES (:scientist, :computers)");
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


