#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    Computer();
    int getID();
    string getComputerName();
    string getType();
    int getYearBuilt();
    string getBuilt();

    void setID(int ID);
    void setName(string computerName);
    void setType(char type);
    void setYearBuilt(int yearbuilt);
    void setBuilt(char built);

    Computer(int ID, string computerName, string type, int yearBuilt, string built);

 private:

    vector<Computer> _computers;

    int _ID;
    string _computerName;
    string _type;
    int _yearBuilt;
    string _built;
};


#endif // COMPUTER_H
