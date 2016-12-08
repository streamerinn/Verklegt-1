#ifndef COMPURSERVICE_H
#define COMPURSERVICE_H

#include "computer.h"
#include "computerdatabase.h"

#include <vector>
#include <algorithm>
#include <QString>

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
    vector<Computer> getComputersReversedAlpha();
    vector<Computer> getComputersYoung();
    vector<Computer> getComputersOld();
    vector<Computer> getComputersBuiltOrNot();

    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const string type);
    vector<Computer> searchBuilt(const char built);

    vector<Computer> searchRandomComputer();


    int searchID(string computerName);

    int getConnections(); // returns how many connections there are

<<<<<<< HEAD
    void deleteComputer(int id);
    void editComputer(int id);
=======
    void deleteComputer(char id);
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a


private:
    vector<Computer> computers;
    ComputerDatabase data;
};

#endif // COMPURSERVICE_H
