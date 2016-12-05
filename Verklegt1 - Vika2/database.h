#ifndef DATABASE_H
#define DATABASE_H

#include "scientist.h"
#include <QtSql>

#include <vector>
#include <fstream>
#include <string>

using namespace std;

class DataBase
{

public:
    DataBase();

    vector<Scientist> readingTxt();

    void returnInfo(Scientist scientist);


private:
    vector<Scientist> savedData;
    QSqlDatabase db;

};

#endif // DATABASE_H
