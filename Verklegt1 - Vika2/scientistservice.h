#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>

//include til þess að útfæra randum number generator.
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

    // Skilar Scientists í ákveðnri röð
    vector<Scientist> getScientists();
    vector<Scientist> getScientistsAlpha();
    vector<Scientist> getScientistsReversedAlpha();
    vector<Scientist> getScientistsYoung();
    vector<Scientist> getScientistsOld();

    // Search föll
    vector<Scientist> searchName(string name);
    vector<Scientist> searchGender(char gender);
    vector<Scientist> searchDateOfBirth(int birthYear);
    vector<Scientist> searchDateOfDeath(int deathYear);
    vector<Scientist> searchRandom();

    // breytir upplýsingum í database
    void deleteScientist(int id);
    void editScientist(int id, string gender,string name, int birth, int death); // sendir nýjar upplýsingar um scientist database
    void create(Scientist scientist);

    // sækir ID á tölvu, sendir það í database og sækir síðan Scientistana sem eru tengdir henni
    vector<Scientist> getComputerID(int CID);

private:
    vector<Scientist> scientists;
    ScientistDatabase data;
};

#endif // SCIENTISTSERVICE_H
