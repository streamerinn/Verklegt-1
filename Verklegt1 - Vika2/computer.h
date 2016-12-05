#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>

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
    void setType(string type);
    void setYearBuilt(int yearbuilt);
    void setBuilt(string built);

    Computer(int ID, string computerName, char type, int yearBuilt, string built);

 private:
    int _ID;
    string _computerName;
    string _type;
    int _yearBuilt;
    string _built;
};


#endif // COMPUTER_H
