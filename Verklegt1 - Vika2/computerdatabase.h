#ifndef COMPUTERDATABASE_H
#define COMPUTERDATABASE_H

#include "computer.h"
#include <QtSql>
#include <vector>

using namespace std;

class ComputerDatabase
{
public:
    ComputerDatabase();
    ~ComputerDatabase();

    vector<Computer> computerDB();
    void insertRow(Computer computer);
private:
    QSqlDatabase db;
    QString dbName;
};

#endif // COMPUTERDATABASE_H