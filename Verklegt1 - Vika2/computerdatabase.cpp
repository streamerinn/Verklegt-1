#include "computerdatabase.h"

//Constructor
ComputerDatabase::ComputerDatabase()
{
    connectionName = "computerDB";
    dbName = "Skil2DB.sqlite";
    if(!connectionCheck(connectionName))
    {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName(dbName);
        db.open();
    }
    else
    {
        db = QSqlDatabase::database(connectionName);
    }
}
//Destructor
ComputerDatabase::~ComputerDatabase()
{
    QSqlDatabase::removeDatabase(dbName);
    db.close();
}

bool ComputerDatabase::connectionCheck(QString name)
{
    bool connected;
    if(QSqlDatabase::contains(name))
    {
        connected = true;
    }
    else
    {
        connected = false;
    }
    return connected;
}

vector<Computer> ComputerDatabase::computerDB()
{
    vector<Computer> computerVector;

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string computerName = query.value("name").toString().toStdString();
        // string type = query.value("type").toString().toStdString();
        int yearBuilt;


        if(!query.value("yearBuilt").isNull())
        {
            yearBuilt = query.value("yearBuilt").toUInt();
        }
        else
        {
            yearBuilt = 0;
        }
        string type = query.value("type").toString().toStdString();
        int built = query.value("built").toUInt();

        computerVector.push_back(Computer(id, computerName, type, yearBuilt, built));
    }

    return computerVector;

}

void ComputerDatabase::insertRow(Computer computer)
{
    QSqlQuery query(db);

    QString name = QString::fromStdString(computer.getComputerName());
    QString type = QString::fromStdString(computer.getType());
    QString yearBuilt = QString::number(computer.getYearBuilt());
    QString built = QString::number(computer.getBuilt());

    query.prepare("INSERT INTO Computers (name, yearBuilt, type, built) VALUES (:name, :yearBuilt, :type, :built)");
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":yearBuilt", yearBuilt);
    query.bindValue(":built", built);
    query.exec();
}

<<<<<<< HEAD
void ComputerDatabase::deleteComputer(int id)
=======
int ComputerDatabase::countConnections()
{
    int counter = 0;

    QSqlQuery query;
    query.exec("SELECT * FROM Connections");

    while (query.next())
    {
        counter++;
    }

    return counter;
}

void ComputerDatabase::deleteComputer(char id)
>>>>>>> 31e8d7e12cc18684c2e282c66aa521b99a372330
{
        QSqlQuery query;
        query.prepare("DELETE FROM Computers where ID = ?");

        // herna er verið ad replacea "?" med ID breytunni
        query.addBindValue(id);

        // execute query
        query.exec();
}

<<<<<<< HEAD
void ComputerDatabase::editComputer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Computers where ID = ?");

    // herna er verið ad replacea "?" med ID breytunni
    query.addBindValue(id);

    // execute query
    query.exec();
}

=======
>>>>>>> f14cac9a03602b904aa2b58670376bc7f3e6894a
