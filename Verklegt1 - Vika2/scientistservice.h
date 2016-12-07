#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>

//include til þess að útfæra randum number generator.
#include <cstdlib>
#include <ctime>

#include "scientist.h"
#include "scientistdatabase.h"
#include "connectiondatabase.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    void create(Scientist scientist);

    vector<Scientist> getScientists();
    vector<Scientist> getScientistsAlpha();
    vector<Scientist> getScientistsReversedAlpha();
    vector<Scientist> getScientistsYoung();
    vector<Scientist> getScientistsOld();

    vector<Scientist> searchName(string name);
    vector<Scientist> searchGender(char gender);
    vector<Scientist> searchDateOfBirth(int birthYear);
    vector<Scientist> searchDateOfDeath(int deathYear);

    vector<Scientist> searchRandom();

    void searchID(string scientistName);

private:
    vector<Scientist> scientists;
    ScientistDatabase data;
    ConnectionDataBase scientistConnection;
};

#endif // SCIENTISTSERVICE_H
