#include "connectiondatabase.h"
#include <QtSql>

ConnectionDataBase::ConnectionDataBase()
{
    dbName = "Skil2DB.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    db.open();
}

void ConnectionDataBase::getcomputerID(int computerID)
{
    return computerID;
}

void ConnectionDataBase::getscientistID(int scientistID)
{
    return scientistID;
}

void ConnectionDataBase::insertRow()
{

}
