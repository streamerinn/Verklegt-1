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
    void insertRow(Computer computer);
    int countConnections(); // gets number of connections
<<<<<<< HEAD
    void deleteComputer(int id);
    void editComputer(int id);
=======
    void deleteComputer(char id);
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a

private:
    QSqlDatabase db;
    QString dbName;
};

#endif // COMPUTERDATABASE_H
