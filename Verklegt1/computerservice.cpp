#include "computerservice.h"

CompurService::CompurService()
{

}

//þarf að búa til struct því, hann kann ekki að bera saman tvö tilvik af Scientist.
//struct sér um að raða eftir nöfnum og aldur.
struct ComputerComparisonAlpha
{
    bool operator() (Computer i, Computer j)
    {
        string iName = i.getName();
        string jName = j.getName();
        transform(iName.begin(), iName.end(), iName.begin(), ::tolower);
        transform(jName.begin(), jName.end(), jName.begin(), ::tolower);

        return (iName<jName);
    }
};

struct ComputerComparisonYoung
{
    bool operator() (Computer i, Computer j)
    {
        int iBuildYear = i.getDateOfBuild();
        int jBuildYear = j.getDateOfBuild();
        return (iBuildYear<jBuildYear);
    }
};

struct ComputerComparisonOld
{
    bool operator() (Computer i, Computer j)
    {
        int iBuildYear = i.getDateOfBuild();
        int jBuildYear = j.getDateOfBuild();
        return (jBuildYear<iBuildYear);
    }
};

ComputerService::ComputerService()
{
    /*DataBase db;
    db.initTxtFile();
    scientists = data.readingTxt();*/
}

vector<Computer> ComputerService::getComputersAlpha()
{
    computerComparisonAlpha cmp;

    sort(computers.begin(), computers.end(), cmp);

    return computers;
}

vector<Computor> ComputerService::getComputersYoung()
{
    computerComparisonYoung cmpYoung;

    sort(computers.begin(), computers.end(), cmpYoung);

    return computers;
}

vector<Scientist> ComputerService::getScientists()
{
    return computers;
}

vector<Scientist> ComputerService::getScientistsOld()
{
    computerComparisonOld cmpOld;

    std::sort(computers.begin(), computers.end(), cmpOld);

    return computers;
}

//Skilar einum scientist inn í vectorinn.
//Skilar einum scientist í database, þar sem hann verður sendur inn í textaskrá.
void ComputerService::create(Computer computer)
{
    //data.returnInfo(scientist);
    computers.push_back(computer);
}

vector<Scientist> ComputerService::searchComputerName(string computerName)
{
    vector<Computer> temp;
    string computer;

    for(size_t i = 0; i < computers.size(); i++)
    {
        computer = computers[i].getComputerName();
        transform(computer.begin(), computer.end(), computer.begin(), ::tolower);
        transform(computerName.begin(), computerName.end(), computerName.begin(), ::tolower);
        if(scientist.find(computerName) !=string::npos)
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
}*/
