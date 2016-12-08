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
<<<<<<< HEAD
=======
    int countConnections(); // gets number of connections
<<<<<<< HEAD
>>>>>>> 31e8d7e12cc18684c2e282c66aa521b99a372330
    void deleteComputer(int id);
    void editComputer(int id);
=======
    void deleteComputer(char id);
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // COMPUTERDATABASE_H
