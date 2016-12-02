#include "scientistservice.h"

//þarf að búa til struct því, hann kann ekki að bera saman tvö tilvik af Scientist
//struct sér um að raða eftir nöfnum
struct ScientistComparisonAlpha
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
    DataBase db;
    db.initTxtFile();
    scientists = data.readingTxt();

}

vector<Scientist> ScientistService::getScientistsAlpha()/* TODO: parameters, hann er public í .h*/
{

    ScientistComparisonAlpha cmp;

    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;

}

vector<Scientist> ScientistService::getScientistsYoung()/* TODO: parameters, hann er public í .h*/
{

    ScientistComparisonYoung cmpYoung;

    std::sort(scientists.begin(), scientists.end(), cmpYoung);

    // vil returna þessum scientist sorted
    return scientists;

}

vector<Scientist> ScientistService::getScientists()
{
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOld()
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

vector<Scientist> ScientistService::searchName(string name)
{
    vector<Scientist> temp;
    string scientist;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        scientist = scientists[i].getName();
        transform(scientist.begin(), scientist.end(), scientist.begin(), ::tolower);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(scientist.find(name) !=string::npos)
        {
            temp.push_back(scientists[i]);
        }
    }
    return temp;
}

vector<Scientist> ScientistService::searchGender(char gender)
{
    vector<Scientist> temp2;

    if(gender == 'F'||gender== 'f')
    {
        for(size_t i = 0; i < scientists.size();i++)
        {
            if(scientists[i].getGender()== "Female")
            {
                temp2.push_back(scientists[i]);
            }
        }
    }
    else if(gender == 'M'||gender == 'm')
    {
        for(size_t i = 0; i < scientists.size();i++)
        {
            if(scientists[i].getGender()=="Male")
            {
                temp2.push_back(scientists[i]);
            }
        }
    }
    return temp2;
}

vector<Scientist> ScientistService::searchDateOfBirth(int birthYear)
{
    vector<Scientist> temp1;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        if(scientists[i].getDateOfBirth() == birthYear)
        {
            temp1.push_back(scientists[i]);
        }
    }
    return temp1;
}

vector<Scientist> ScientistService::searchRandom()
{
    vector<Scientist> temp3;
    srand(time(0));
                   // A simple random number generator using time
                   // the reason for using %(scientist.size() - 1) is to be able to get the whole range of the vektor;
    temp3.push_back(scientists[1+(rand()%(scientists.size() - 1))]);

    return temp3;
}

vector<Scientist> ScientistService::searchDateOfDeath(int deathYear)
{
    vector<Scientist> temp4;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        if(scientists[i].getDateOfDeath())
        {
            temp4.push_back(scientists[i]);
        }
    }
    return temp4;
}
