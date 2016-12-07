#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>

#include <vector>

using namespace std;

class ConnectionService
{
public:
    ConnectionService();

    void getIDs(vector<int> IDs);

private:
    ConnectionDataBase connections;
};

#endif // CONNECTIONSERVICE_H
