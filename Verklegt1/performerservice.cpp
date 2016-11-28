#include "performerservice.h"

//miðlagið

PerformerService::PerformerService()
{

}

vector<Performer> PerformerService::getPerformers(/* TODO: parameters */)
{
    vector<Performer> performers;

    Performer p("Charles Babbage", 1791);
    Performer p2("Madonna", 55);

    performers.push_back(p);
    performers.push_back(p2);

    //TODO: business logic


    return performers;

}
