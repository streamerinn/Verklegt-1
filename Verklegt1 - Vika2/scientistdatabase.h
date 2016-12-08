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
    bool connectionCheck(QString name);
    void insertRow(Scientist scientist);
    void deleteScientist(int id);
    void editScientist(int id);

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;

};

#endif // SCIENTISTDATABASE_H
