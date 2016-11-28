#include "scientistservice.h"

//miðlagið

ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getScientists()/* TODO: parameters */
{
    vector<Scientist> scientists;


    //harðkóðaðar upplýsingar til að prufa virkni clasans
    Scientist p("Charles Babbage", "male", 1791, 1871);
    Scientist p2("Ada Locelace", "female", 1815, 1852);

    scientists.push_back(p);
    scientists.push_back(p2);

    //TODO: business logic


    return scientists;

}
