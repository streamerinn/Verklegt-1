#ifndef DATABASE_H
#define DATABASE_H

#include "scientist.h"

#include <vector>
#include <fstream>
#include <string>

using namespace std;

class DataBase
{

public:
    DataBase();

    //sækir upplýsingar úr textaskrá.
    void initTxtFile();

    void returnInfo(Scientist scientist);
    vector<Scientist> readingTxt();

private:
    vector<Scientist> savedData;

};

#endif // DATABASE_H
