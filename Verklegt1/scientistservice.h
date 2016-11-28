#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    vector<Scientist> getScientists(/*TODO: paramleters */);
};

#endif // SCIENTISTSERVICE_H
