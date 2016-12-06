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
private:
    QSqlDatabase db;
    QString dbName;

};

#endif // SCIENTISTDATABASE_H
