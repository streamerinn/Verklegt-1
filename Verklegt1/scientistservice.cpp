#include "scientistservice.h"

//miðlagið

ScientistService::ScientistService()
{
    //_scientists = scientists;
    //data = new DataBase();
}

vector<Scientist> ScientistService::getScientists() /* TODO: parameters*/
{

    //harðkóðaðar upplýsingar til að prufa virkni clasans
    /*Scientist p("Charles Babbage", "male", 1791, 1871);
    Scientist p2("Ada Locelace", "female", 1815, 1852);

    scientists.push_back(p);
    scientists.push_back(p2);*/

    //TODO: business logic

    return scientists;

}

//Skilar einum scientist inn í vectorinn
//Skilar einum scientist í database, þar sem hann verður sendur inn í textaskrá
void ScientistService::create(Scientist scientist)
{
    data.returnInfo(scientist);
    scientists.push_back(scientist);
}
