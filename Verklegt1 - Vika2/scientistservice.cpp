#include "scientistservice.h"
#include <iostream>

//þarf að búa til struct því, hann kann ekki að bera saman tvö tilvik af Scientist.
//struct sér um að raða eftir nöfnum og aldur.

//raðar í stafrófsröð
struct ScientistComparisonAlpha
{
    bool operator() (Scientist i, Scientist j)
    {
        string iName = i.getName();
        string jName = j.getName();
        transform(iName.begin(), iName.end(), iName.begin(), ::tolower);
        transform(jName.begin(), jName.end(), jName.begin(), ::tolower);

        return (iName<jName);
    }
};
//raðar í öfuga stafrófsröð
struct ScientistComparisonReversedAlpha
{
    bool operator() (Scientist i, Scientist j)
    {
        string iName = i.getName();
        string jName = j.getName();
        //trasform breitir bæði leitarstreng og nafni í lágstafi til að hægt sé að bera saman og finna
        transform(iName.begin(), iName.end(), iName.begin(), ::tolower);
        transform(jName.begin(), jName.end(), jName.begin(), ::tolower);

        return (jName<iName);
    }
};

//raðar eftir aldri, yngsti til elsta
struct ScientistComparisonYoung
{
    bool operator() (Scientist i, Scientist j)
    {
        int iAge = i.getDateOfDeath()-i.getDateOfBirth();
        int jAge = j.getDateOfDeath()-j.getDateOfBirth();

        return (iAge<jAge);
    }
};

//raðar eftir aldri, elsta til yngsta
struct ScientistComparisonOld
{
    bool operator() (Scientist i, Scientist j)
    {
        int iAge = i.getDateOfDeath()-i.getDateOfBirth();
        int jAge = j.getDateOfDeath()-j.getDateOfBirth();
        return (jAge<iAge);
    }
};

ScientistService::ScientistService()
{
    scientists = data.scientistDB();
}

vector<Scientist> ScientistService::getScientistsAlpha()
{
    ScientistComparisonAlpha cmp;
    sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::getScientistsReversedAlpha()
{
    ScientistComparisonReversedAlpha cmpRev;
    sort(scientists.begin(), scientists.end(), cmpRev);

    return scientists;
}

vector<Scientist> ScientistService::getScientistsYoung()
{
    ScientistComparisonYoung cmpYoung;
    sort(scientists.begin(), scientists.end(), cmpYoung);

    return scientists;
}

vector<Scientist> ScientistService::getScientists()
{
    return scientists;
}

vector<Scientist> ScientistService::getScientistsOld()
{
    ScientistComparisonOld cmpOld;
    sort(scientists.begin(), scientists.end(), cmpOld);

    return scientists;
}

void ScientistService::create(Scientist scientist)
{
    data.insertRow(scientist);
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

    if(gender == 'F'||gender == 'f')
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
                   // Virkni sem býr til slembitölur með hjálp time.
                   // Ástæðan fyrir að nota %(scientist.size() - 1) er til að ná í allt "range-ið" úr vektornum.
    temp3.push_back(scientists[1+(rand()%(scientists.size() - 1))]);

    return temp3;
}

vector<Scientist> ScientistService::searchDateOfDeath(int deathYear)
{
    vector<Scientist> temp4;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        if(scientists[i].getDateOfDeath() == deathYear)
        {
            temp4.push_back(scientists[i]);
        }
    }
    return temp4;
}

int ScientistService::searchID(string scientistName)
{
    int scientistID = 0;

    for(size_t i = 0; i < scientists.size(); i++)
    {
        if(scientists[i].getName() == scientistName)
        {
            scientistID = scientists[i].getID();
        }
    }
    return scientistID;
}

void ScientistService::deleteScientist(int id)
{
    // kalla bara a database fallið sem sér um að deletea
    data.deleteScientist(id);
}

void ScientistService::editScientist(int id, string gender, string name, int birth, int death)
{
    data.editScientist(id, gender, name, birth, death);
}

vector<Scientist> ScientistService::getComputerID(int CID)
{
    vector<Scientist> scientistsConnected;
    scientistsConnected = data.scientistsConnectedToComputers(CID);

    return scientistsConnected;
}
