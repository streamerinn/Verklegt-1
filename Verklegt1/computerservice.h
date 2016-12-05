#ifndef COMPURSERVICE_H
#define COMPURSERVICE_H

using namespace std;

class ComputerService
{
public:
    ComputerService();

    void create(Computer computer);

    vector<Computer> getComputers();
    vector<Computer> getComputersAlpha();
    vector<Computer> getComputersBuild();
    vector<Computer> getComputersBuiltOrNot();

    vector<Computer> searchComputerName(string name);
    vector<Computer> searchDateOfBuild(int buildYear);
    vector<Computer> searchType(char type);
    vector<Computer> searchTypeBuiltOrNot(int deathYear);

    //vector<Computer> searchRandomComputer();


private:
    vector<Computers> computers;
};

#endif // COMPURSERVICE_H
