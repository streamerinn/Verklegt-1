#ifndef CONNECTIONDATABASE_H
#define CONNECTIONDATABASE_H

#include <QtSql>
#include <vector>
#include"scientist.h"
#include <QDebug>

using namespace std;

class ConnectionDataBase
{
public:
    // Constructor functions
    ConnectionDataBase();
    ~ConnectionDataBase();

    bool connectionCheck(QString name);

    // Retrieves informations from database.
    int getscientistID(int scientistID);
    int getcomputerID(int computerID);
    vector<Scientist> getConnectionIDs();

    // Adds informations to the database.
    bool insertRow(vector<int> IDs);

    int countConnections();
    void deleteLink(int compID, int sciID);



private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // CONNECTIONDATABASE_H
