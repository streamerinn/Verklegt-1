#include "computerservice.h"

//Constructor
ComputerService::ComputerService()
{
   // computers = data.computerDB();
    setComputerVector();
}

void ComputerService::setComputerVector()
{
    computers = data.computerDB();
}

//Sér um að raða eftir nöfnum og aldri
struct ComputerComparisonAlpha
{
    bool operator() (Computer i, Computer j)
    {
        string iName = i.getComputerName();
        string jName = j.getComputerName();
        transform(iName.begin(), iName.end(), iName.begin(), ::tolower);
        transform(jName.begin(), jName.end(), jName.begin(), ::tolower);

        return (iName<jName);
    }
};
//Raðar nöfnum í öfuga stafrófsröð
struct ComputerComparisonReversedAlpha
{
    bool operator() (Computer i, Computer j)
    {
        string iName = i.getComputerName();
        string jName = j.getComputerName();
        transform(iName.begin(), iName.end(), iName.begin(), ::tolower);
        transform(jName.begin(), jName.end(), jName.begin(), ::tolower);

        return (jName<iName);
    }
};
//Raðar eftir byggingarári, nýlegast fyrst
struct ComputerComparisonYoung
{
    bool operator() (Computer i, Computer j)
    {
        int iYearBuilt = i.getYearBuilt();
        int jYearBuilt = j.getYearBuilt();
        return (iYearBuilt<jYearBuilt);
    }
};
//Raðar eftir byggingarári, elst fyrst
struct ComputerComparisonOld
{
    bool operator() (Computer i, Computer j)
    {
        int iYearBuilt = i.getYearBuilt();
        int jYearBuilt = j.getYearBuilt();
        return (jYearBuilt<iYearBuilt);
    }
};

struct ComputerComparisonID
{
    bool operator() (Computer i, Computer j)
    {
        int iID = i.getID();
        int jID = j.getID();
        return (iID<jID);
    }
};

vector<Computer> ComputerService::getComputersID()
{
    ComputerComparisonID cmp;

    sort(computers.begin(), computers.end(), cmp);

    return computers;
}

vector<Computer> ComputerService::getComputersAlpha()
{
    ComputerComparisonAlpha cmp;

    sort(computers.begin(), computers.end(), cmp);

    return computers;
}

vector<Computer> ComputerService::getComputersReversedAlpha()
{
    ComputerComparisonReversedAlpha cmpRev;

    sort(computers.begin(), computers.end(), cmpRev);

    return computers;
}

vector<Computer> ComputerService::getComputersYoung()
{
    ComputerComparisonYoung cmpYoung;

    sort(computers.begin(), computers.end(), cmpYoung);

    return computers;
}

vector<Computer> ComputerService::getComputers()
{
    return computers;
}

vector<Computer> ComputerService::getComputersOld()
{
    ComputerComparisonOld cmpOld;

    std::sort(computers.begin(), computers.end(), cmpOld);

    return computers;
}

//Skilar einni computer inn í vectorinn.
//Skilar einni computer í database, þar sem hann verður sendur inn í textaskrá.
void ComputerService::create(Computer computer)
{
    data.insertRow(computer);
    computers.push_back(computer);
}

vector<Computer> ComputerService::searchComputerName(string computerName)
{
    return data.getName(computerName);
}

vector<Computer> ComputerService::searchType(const char type)
{

    return data.getType(type);
}

vector<Computer> ComputerService::searchYearOfBuild(int buildYear)
{
    return data.getYearBuilt(buildYear);
}

vector<Computer> ComputerService::searchRandomComputer()
{
    vector<Computer> temp3;
    srand(time(0));
                   // Virkni sem býr til slembitölur með hjálp time.
                   // Ástæðan fyrir að nota %(scientist.size() - 1) er til að ná í allt "range-ið" úr vektornum.
    temp3.push_back(computers[1+(rand()%(computers.size() - 1))]);

    return temp3;
}

vector<Computer> ComputerService::searchBuilt(char built)
{
    return data.getBuilt(built);
}

void ComputerService::deleteComputer(int id)
{
    data.deleteComputer(id);
    setComputerVector();
}

void ComputerService::editComputer(string name,int id, int buildYear, int built, string type)
{
    data.editComputer(name, id, buildYear ,built, type);
    setComputerVector();
}

vector<Computer> ComputerService::getScientistID(int SID)
{
    vector<Computer> computersConnected;
    computersConnected = data.computersConnectedToScientist(SID);
    return computersConnected;
}
