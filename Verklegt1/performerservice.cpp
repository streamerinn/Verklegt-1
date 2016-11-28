#include "performerservice.h"

//miðlagið

PerformerService::PerformerService()
{

}

vector<Performer> PerformerService::getPerformers(/* TODO: parameters */)
{
    vector<Performer> performers;


    //harðkóðaðar upplýsingar til að prufa virkni clasans
    Performer p("Charles Babbage", "male", 1791, 1871);
    Performer p2("Ada Locelace", "female", 1815, 1852);

    performers.push_back(p);
    performers.push_back(p2);

    //TODO: business logic


    return performers;

}
