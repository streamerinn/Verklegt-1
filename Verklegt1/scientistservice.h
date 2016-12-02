#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>

//include til þess að gera randum number generator
#include <cstdlib>
#include <ctime>

#include "scientist.h"
#include "database.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    void create(Scientist scientist);

    vector<Scientist> getScientists();
    vector<Scientist> getScientistsAlpha();
    vector<Scientist> getScientistsYoung();
    vector<Scientist> getScientistsOld();

    vector<Scientist> searchName(string name);
    vector<Scientist> searchGender(char gender);
    vector<Scientist> searchDateOfBirth(int birthYear);
    vector<Scientist> searchDateOfDeath(int deathYear);

    vector<Scientist> searchRandom();

private:
    vector<Scientist> scientists;
    DataBase data;
};

#endif // SCIENTISTSERVICE_H
