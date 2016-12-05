#ifndef DATABASE_H
#define DATABASE_H

#include "scientist.h"
#include <QtSql>

#include <vector>
#include <fstream>
#include <string>

#include <sstream>
#include <iostream>

using namespace std;

class DataBase
{

public:
    DataBase();

    vector<Scientist> readingTxt();

    void returnInfo(Scientist scientist);

    void insertTable(Scientist scientist);


private:
    vector<Scientist> savedData;
    QSqlDatabase db;
    QString dbName;

};

#endif // DATABASE_H
