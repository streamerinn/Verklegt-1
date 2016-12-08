#ifndef CONNECTIONDATABASE_H
#define CONNECTIONDATABASE_H

#include <QtSql>
#include <vector>
#include"scientist.h"

using namespace std;

class ConnectionDataBase
{
public:
    ConnectionDataBase();
    ~ConnectionDataBase();

    bool connectionCheck(QString name);
    int getscientistID(int scientistID);
    int getcomputerID(int computerID);
    void insertRow(vector<int> IDs);
    int countConnections();

    vector<Scientist> getidName();

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // CONNECTIONDATABASE_H
