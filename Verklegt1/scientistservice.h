#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"

using namespace std;

class ScientistService
{
private:
    vector<Scientist> scientists;
public:
    ScientistService();

    vector<Scientist> getScientists(/*TODO: paramleters */);
    void init();
};

#endif // SCIENTISTSERVICE_H
