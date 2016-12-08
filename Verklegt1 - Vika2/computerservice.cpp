#include "computerservice.h"

ComputerService::ComputerService()
{
    computers = data.computerDB();
}

//þarf að búa til struct því, hann kann ekki að bera saman tvö tilvik af Scientist.
//struct sér um að raða eftir nöfnum og aldur.
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

struct ComputerComparisonYoung
{
    bool operator() (Computer i, Computer j)
    {
        int iYearBuilt = i.getYearBuilt();
        int jYearBuilt = j.getYearBuilt();
        return (iYearBuilt<jYearBuilt);
    }
};

struct ComputerComparisonOld
{
    bool operator() (Computer i, Computer j)
    {
        int iYearBuilt = i.getYearBuilt();
        int jYearBuilt = j.getYearBuilt();
        return (jYearBuilt<iYearBuilt);
    }
};

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

//Skilar einum scientist inn í vectorinn.
//Skilar einum scientist í database, þar sem hann verður sendur inn í textaskrá.
void ComputerService::create(Computer computer)
{
    data.insertRow(computer);
    computers.push_back(computer);
}

vector<Computer> ComputerService::searchComputerName(string computerName)
{
    vector<Computer> temp;
    string computer;

    for(size_t i = 0; i < computers.size(); i++)
    {
        computer = computers[i].getComputerName();
        transform(computer.begin(), computer.end(), computer.begin(), ::tolower);
        transform(computerName.begin(), computerName.end(), computerName.begin(), ::tolower);
        if(computer.find(computerName) !=string::npos)
        {
            temp.push_back(computers[i]);
        }
    }
    return temp;
}

vector<Computer> ComputerService::searchType(const string type)
{

    vector<Computer> temp2;

   if(type == "M"||type == "m")
    {
      for(size_t i = 0; i < computers.size();i++)
       {
          if(computers[i].getType()== "Mechanical")
            {
              temp2.push_back(computers[i]);
            }
        }
    }
    else if(type == "E"||type == "e")
    {
    for(size_t i = 0; i < computers.size();i++)
      {
        if(computers[i].getType()== "Electronical")
          {
            temp2.push_back(computers[i]);
            }
        }
    }
    else if(type == "T"||type == "t")
    {
      for(size_t i = 0; i < computers.size();i++)
       {
         if(computers[i].getType()== "Transitional")
           {
               temp2.push_back(computers[i]);
            }
        }
    }
    return temp2;
}

vector<Computer> ComputerService::searchYearOfBuild(int buildYear)
{
    vector<Computer> temp1;

    for(size_t i = 0; i < computers.size(); i++)
    {
        if(computers[i].getYearBuilt() == buildYear)
        {
            temp1.push_back(computers[i]);
        }
    }
    return temp1;
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

vector<Computer> ComputerService::searchBuilt(const char built)
{
    vector<Computer> temp4;
    int build;


    QSqlQuery query;




    if (built == 'Y'|| built == 'y')
    {

        build = 1;

    }
    else if (built == 'N'|| built =='n')
    {

        build = 0;
    }


    if((built == 'Y'||built == 'y')&&(build == 1))
    {
      query.exec("SELECT * FROM Computers WHERE built = 'true';");
      while(query.next())
      {
        int id = query.value("id").toInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt = query.value("build year").toInt();
        bool wasBuilt = query.value("built").toBool();

        Computer computer(id, name, type, yearBuilt, wasBuilt);

          temp4.push_back(computer);
      }

        //for(size_t i = 0; i < computers.size(); i++)
        //{

        //}
    }

    else if(built =='N'||built =='n'||build ==0)
    {

        query.exec("SELECT * FROM Computers WHERE built = 'false';");
        while(query.next())
        {
          int id = query.value("id").toInt();
          string name = query.value("name").toString().toStdString();
          string type = query.value("type").toString().toStdString();
          int yearBuilt = query.value("build year").toInt();
          bool wasBuilt = query.value("built").toBool();

          Computer computer(id, name, type, yearBuilt, wasBuilt);
           temp4.push_back(computer);
        }



        //for(size_t i = 0; i < computers.size(); i++)
        //{

        //}

    }
    return temp4;
}

int ComputerService::searchID(string computerName)
{
    int computerID = 0;

    for(size_t i = 0; i < computers.size(); i++)
    {
        if(computers[i].getComputerName() == computerName)
        {
            computerID = computers[i].getID();
        }
    }
    return computerID;
}

int ComputerService::getConnections()
{
    return data.countConnections();
}

void ComputerService::deleteComputer(char id)
{
    data.deleteComputer(id);
}

<<<<<<< HEAD
void ComputerService::editComputer(int id)
{
    data.editComputer(id);
}
=======
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a
