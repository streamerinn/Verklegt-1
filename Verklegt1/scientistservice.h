#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"
#include "database.h"

using namespace std;

class ScientistService
{
private:
    vector<Scientist> scientists;
    DataBase data;

public:
    ScientistService();
    vector<Scientist> getScientists();
    vector<Scientist> getScientistsYoung();
    vector<Scientist> getScientistsOld();
    //void create(vector<Scientist> info);
    void create(Scientist scientist);
};

#endif // SCIENTISTSERVICE_H
