#ifndef COMPUTERDATABASE_H
#define COMPUTERDATABASE_H

#include "computer.h"
#include <vector>
#include <QtSql>

using namespace std;

class ComputerDatabase
{
public:
    // Constructor functions
    ComputerDatabase();
    ~ComputerDatabase();

    // Connection
    bool connectionCheck(QString name); 

    // Changes information in database.
    void deleteComputer(int id);
    void editComputer(string name,int id, int buildYear ,int built, string type); // setur upplýsingar upp á nýtt í database
    void insertRow(Computer computer); // bætir nýrri tölvu við

    // Retrieves information from database.
    vector<Computer> computersConnectedToScientist(int scientistsID); // sækir tengingar
    vector<Computer> getYearBuilt(int a);
    vector<Computer> getType(char a);
    vector<Computer> getBuilt(char built);
    vector<Computer> getName (string name);
    vector<Computer> computerDB(); // setur allar upplýsingar inn í vector

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;
};

#endif // COMPUTERDATABASE_H
