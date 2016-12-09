#ifndef SCIENTISTDATABASE_H
#define SCIENTISTDATABASE_H

#include "scientist.h"
#include <QtSql>

using namespace std;

class ScientistDatabase
{
public:
    // Constructorar
    ScientistDatabase();
    ~ScientistDatabase();

    // Athugar connection við database
    bool connectionCheck(QString name);

    vector<Scientist> scientistDB();
    vector<Scientist> scientistsConnectedToComputers(int computerID);   

    // Breytir upplýsingum í database
    void deleteScientist(int id);
    void editScientist(int id, string gender, string name, int birth, int death);
    void insertRow(Scientist scientist); // bætir við nýjum scientist

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;

};

#endif // SCIENTISTDATABASE_H
