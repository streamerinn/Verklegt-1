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
<<<<<<< HEAD
    void deleteScientist(int id);
    void editScientist(int id);
=======
    void deleteScientist(char id);
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a

private:
    QSqlDatabase db;
    QString dbName;
    QString connectionName;

};

#endif // SCIENTISTDATABASE_H
