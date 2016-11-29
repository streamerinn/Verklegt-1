#include "scientistservice.h"

//miðlagið

ScientistService::ScientistService()
{

}

void ScientistService::init()
{
    Scientist p("Charles Babbage", "male", 1791, 1871);
    Scientist p2("Ada Locelace", "female", 1815, 1852);
    Scientist p3("yiis yis", "female", 2015, 2052);

    scientists.push_back(p);
    scientists.push_back(p2);
    scientists.push_back(p3);
}

vector<Scientist> ScientistService::getScientists()/* TODO: parameters */
{
    //harðkóðaðar upplýsingar til að prufa virkni clasans
    /*Scientist p("Charles Babbage", "male", 1791, 1871);
    Scientist p2("Ada Locelace", "female", 1815, 1852);
    Scientist p3("yiis yis", "female", 2015, 2052);

    scientists.push_back(p);
    scientists.push_back(p2);
    scientists.push_back(p3);
*/
    //TODO: business logic


    return scientists;

}
