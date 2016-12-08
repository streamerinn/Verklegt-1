#ifndef COMPUTERDATABASE_H
#define COMPUTERDATABASE_H

#include "computer.h"
#include <vector>
#include <QtSql>

using namespace std;

class ComputerDatabase
{
public:
    ComputerDatabase();
    ~ComputerDatabase();

    vector<Computer> computerDB();
    bool connectionCheck(QString name);
    void insertRow(Computer computer);


    int countConnections(); // gets number of connections

    void deleteComputer(int id);
    void editComputer(int id);

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // COMPUTERDATABASE_H
