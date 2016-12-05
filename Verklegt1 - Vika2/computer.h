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
    string getName();
    char getType();
    int getYearBuilt();
    string getBuilt();

    void setID(int ID);
    void setName(string name);
    void setType(char type);
    void setYearBuilt(int yearbuilt);
    void setBuilt(string built);

    Computer(int ID, string name, char type, int yearBuilt, string built);

 private:

    vector<Computer> _computers;

    int _ID;
    string _name;
    char _type;
    int _yearBuilt;
    string _built;
};


#endif // COMPUTER_H
