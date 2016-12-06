#ifndef COMPURSERVICE_H
#define COMPURSERVICE_H

#include "computer.h"
//#include "database.h"
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <ctime>


using namespace std;

class ComputerService
{
public:
    ComputerService();

    void create(Computer computer);

    vector<Computer> getComputers();
    vector<Computer> getComputersAlpha();
    vector<Computer> getComputersYoung();
    vector<Computer> getComputersOld();
    vector<Computer> getComputersBuiltOrNot();

    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const char type);
    vector<Computer> searchBuilt(const char built);

    vector<Computer> searchRandomComputer();


private:
    vector<Computer> computers;
    //DataBase data;
};

#endif // COMPURSERVICE_H
