#include "scientistservice.h"
#include <algorithm>

using namespace std;

//miðlagið

//þarf að búa til struct því, hann kann ekki að bera saman tvö tilvik af Scientist
//struct sér um að raða eftir nöfnum

struct ScientistComparison
{
  bool operator() (Scientist i, Scientist j)
  {
     return (i.getName()<j.getName());
  }
};

struct ScientistComparisonYoung
{
  bool operator() (Scientist i, Scientist j)
  {
     return (i.getDateOfBirth()>j.getDateOfBirth());
  }
};

struct ScientistComparisonOld
{
  bool operator() (Scientist i, Scientist j)
  {
     return (i.getDateOfBirth()<j.getDateOfBirth());
  }
};

ScientistService::ScientistService()
{

    //_scientists = scientists;
    //data = new DataBase();
}

vector<Scientist> ScientistService::getScientists()/* TODO: parameters, hann er public í .h*/
{

    ScientistComparison cmp;

    std::sort(scientists.begin(), scientists.end(), cmp);


    //vil returna þennan scientist sorted
    return scientists;

}

vector<Scientist> ScientistService::getScientistsYoung()/* TODO: parameters, hann er public í .h*/
{

    ScientistComparisonYoung cmpYoung;

    std::sort(scientists.begin(), scientists.end(), cmpYoung);


    //vil returna þennan scientist sorted
    return scientists;

}

vector<Scientist> ScientistService::getScientistsOld()/* TODO: parameters, hann er public í .h*/
{

    ScientistComparisonOld cmpOld;

    std::sort(scientists.begin(), scientists.end(), cmpOld);


    //vil returna þennan scientist sorted
    return scientists;

}

//Skilar einum scientist inn í vectorinn
//Skilar einum scientist í database, þar sem hann verður sendur inn í textaskrá
void ScientistService::create(Scientist scientist)
{
    data.returnInfo(scientist);
    scientists.push_back(scientist);
}
