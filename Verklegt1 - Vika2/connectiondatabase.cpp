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


