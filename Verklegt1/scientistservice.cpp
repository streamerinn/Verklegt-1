#include "scientistservice.h"
#include <algorithm>

using namespace std;

//miðlagið

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


/*//bjarki her

ifstream fallid;

Scientist temp;

skyra txt file
lalala("dammdum.txt")

if(txt file.open)
{
    while(afram)
    {
        vector.push_back(temp);
    }
}



//haettir her*/

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


    //vil returna þennan scientist sorted
    return scientists;

}

vector<Scientist> ScientistService::getScientists() //AAAAAAAAAAAAAAAAAAAAAAAAAAAH
{
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

vector<Scientist> ScientistService::searchDateOfBirth(int year)
{
    vector<Scientist> temp1;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        if(scientists[i].getDateOfBirth() == year)
        {
            temp1.push_back(scientists[i]);
        }
    }
    return temp1;
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
