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
    int getBuilt();

    void setID(int id);
    void setName(string computerName);
    void setType(char type);
    void setYearBuilt(int yearbuilt);
    void setBuilt(int built);

    Computer(int id, string computerName, string type, int yearBuilt, int built);

 private:

    vector<Computer> _computers;

    int _id;
    string _computerName;
    string _type;
    int _yearBuilt;
    int _built;
};


#endif // COMPUTER_H
