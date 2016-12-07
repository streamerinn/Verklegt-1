#ifndef CONNECTIONDATABASE_H
#define CONNECTIONDATABASE_H

#include <QtSql>
#include <vector>

using namespace std;

class ConnectionDataBase
{
public:
    ConnectionDataBase();

    int getscientistID(int scientistID);
    int getcomputerID(int computerID);
    void insertRow(vector<int> IDs);

private:
    QSqlDatabase db;
    QString dbName;
};

#endif // CONNECTIONDATABASE_H
