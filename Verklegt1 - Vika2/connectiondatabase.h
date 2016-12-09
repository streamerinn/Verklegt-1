#ifndef CONNECTIONDATABASE_H
#define CONNECTIONDATABASE_H

#include <QtSql>
#include <vector>
#include"scientist.h"

using namespace std;

class ConnectionDataBase
{
public:
    // Constructor föll
    ConnectionDataBase();
    ~ConnectionDataBase();

    bool connectionCheck(QString name);

    // Sækir upplýsingar úr database
    int getscientistID(int scientistID);
    int getcomputerID(int computerID);

    // bætir upplýsingum á database
    void insertRow(vector<int> IDs);

    int countConnections();
    void deleteLink(int compID, int sciID);



private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // CONNECTIONDATABASE_H
