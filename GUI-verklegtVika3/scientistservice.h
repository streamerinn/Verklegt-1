#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>
#include <string>

//include to implement random number generator.
#include <cstdlib>
#include <ctime>

#include "scientist.h"
#include "scientistdatabase.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    void setScientistVector();

    // Returns Scientists in a specific order.
    vector<Scientist> getScientists();
    vector<Scientist> getScientistsAlpha();
    vector<Scientist> getScientistsReversedAlpha();
    vector<Scientist> getScientistsYoung();
    vector<Scientist> getScientistsOld();

    // Search functions
    vector<Scientist> searchName(string name);
    vector<Scientist> searchGender(char gender);
    vector<Scientist> searchDateOfBirth(int birthYear);
    vector<Scientist> searchDateOfDeath(int deathYear);

    // Changes information in the database.
    void deleteScientist(int id);
    void editScientist(int id, string gender,string name, int birth, int death); // sendir nýjar upplýsingar um scientist database
    void create(Scientist scientist);

    // Retrieves ID of a computer, sends it to the database and then retrieves the scientists that are connected to the ID.
    vector<Scientist> getComputerID(int CID);

private:
    vector<Scientist> scientists;
    ScientistDatabase data;
};

#endif // SCIENTISTSERVICE_H
