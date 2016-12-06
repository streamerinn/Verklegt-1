#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include "scientistservice.h"
#include "computerservice.h"

#include <string>

class ConnectionService
{
public:
    Connections();

    int sendScientistName(string scientistName);
    int sendComputerName(string computerName);

private:
    vector<Computer> connections;
};

#endif // CONNECTIONS_H
