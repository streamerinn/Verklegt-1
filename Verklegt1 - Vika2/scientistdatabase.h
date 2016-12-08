#ifndef SCIENTISTDATABASE_H
#define SCIENTISTDATABASE_H

#include "scientist.h"
#include <QtSql>

using namespace std;

class ScientistDatabase
{
public:
    ScientistDatabase();
    ~ScientistDatabase();

    vector<Scientist> scientistDB();
    void insertRow(Scientist scientist);
    void deleteScientist(int id);

private:
    QSqlDatabase db;
    QString dbName;

};

#endif // SCIENTISTDATABASE_H
