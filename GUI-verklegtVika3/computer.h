#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    // constructorar
    Computer();
    Computer(int id, string computerName, string type, int yearBuilt, int built);
    Computer(string computerName, string type, int yearBuilt, int built);


    // get functions
    int getID();
    string getComputerName();
    string getType();
    int getYearBuilt();
    int getBuilt();

    // set functions
    void setID(int id);
    void setName(string computerName);
    void setType(string type);
    void setYearBuilt(int yearbuilt);
    void setBuilt(int built);

 private:
    vector<Computer> _computers;

    int _id;
    string _computerName;
    string _type;
    int _yearBuilt;
    int _built;
    string tempBuilt;
};


#endif // COMPUTER_H
