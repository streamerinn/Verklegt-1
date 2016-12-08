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

=======
<<<<<<< HEAD
>>>>>>> 31e8d7e12cc18684c2e282c66aa521b99a372330
>>>>>>> 98210d66be575f87a67ee17cd6cd7e96bec419ff
    void deleteComputer(int id);
    void editComputer(int id);

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // COMPUTERDATABASE_H
