#ifndef DATABASE_H
#define DATABASE_H

#include "scientist.h"


#include <fstream>
#include <string>

using namespace std;

class DataBase
{

public:
    DataBase();

    //sækir upplýsingar úr textasrká
    void getInfo();
    void returnInfo(Scientist scientist);

private:

    /*ScientistService info;*/

};

#endif // DATABASE_H
