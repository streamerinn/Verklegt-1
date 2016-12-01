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

    //sækir upplýsingar úr textasrká
    vector<Scientist> readingTxt();
    void returnInfo(Scientist scientist);

private:

    /*ScientistService info;*/
    vector<Scientist> savedData;

};

#endif // DATABASE_H
