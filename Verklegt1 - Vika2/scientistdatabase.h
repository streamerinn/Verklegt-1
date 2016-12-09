#ifndef SCIENTISTDATABASE_H
#define SCIENTISTDATABASE_H

#include "scientist.h"
#include <QtSql>

using namespace std;

class ScientistDatabase
{
public:
    // Constructors
    ScientistDatabase();
    ~ScientistDatabase();

    // Checks the connection to database.
    bool connectionCheck(QString name);

    vector<Scientist> scientistDB();
    vector<Scientist> scientistsConnectedToComputers(int computerID);   

    // Changes information in database
    void deleteScientist(int id);
    void editScientist(int id, string gender, string name, int birth, int death);
    void insertRow(Scientist scientist); // bætir við nýjum scientist

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;

};

#endif // SCIENTISTDATABASE_H
