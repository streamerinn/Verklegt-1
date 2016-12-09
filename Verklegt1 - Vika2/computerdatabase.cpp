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
//Checkar hvort database-inn er tengdur eða ekki
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
//Tekur upplýsingar úr database og skilar þeim í vector
vector<Computer> ComputerDatabase::computerDB()
{
    vector<Computer> computerVector;

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string computerName = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt;
        int built = query.value("built").toUInt();


        if(!query.value("yearBuilt").isNull())
        {
            yearBuilt = query.value("yearBuilt").toUInt();
        }
        else
        {
            yearBuilt = 0;
        }


        computerVector.push_back(Computer(id, computerName, type, yearBuilt, built));
    }

    return computerVector;

}
//Bætir nýrri tölvu í Computers töfluna
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

vector<Computer> ComputerDatabase::computersConnectedToScientist(int scientistsID)
{
    QSqlQuery query(db);
    vector<Computer> connectedComputer;

    query.prepare("SELECT b.id, b.name, b.yearBuilt, b.type, b.built FROM Connections a, Computers b WHERE a.scientistsID = ? AND b.id = a.computersID");
    query.addBindValue(scientistsID);
    query.exec();

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt;

        if(!query.value("yearBuilt").isNull())
        {
            yearBuilt = query.value("yearBuilt").toUInt();
        }
        else
        {
            yearBuilt = 0;
        }

        int built = query.value("built").toUInt();

        connectedComputer.push_back(Computer(id, name, type, yearBuilt, built));
    }
    return connectedComputer;
}
//Eyðir tölvu úr Computers töflunni
void ComputerDatabase::deleteComputer(int id)

{
    QString Compid;
    Compid = QString::number(id);

        QSqlQuery query(db);
        query.prepare("DELETE FROM Computers where ID = (:Compid)");
        query.bindValue(":Compid", Compid);
        query.exec();



}

//Breytir tölvu í Computers töflunni
void ComputerDatabase::editComputer(string name,int id, int buildYear, int built, string type)
{
    //vector<Computer> temp1;
    QString Compid;
    QString buildYears;
    //QString builts(built);
    QString types;
    QString names;
    QString builts;

    names = QString::fromStdString(name);
    Compid = QString::number(id);
    buildYears = QString::number(buildYear);
    //builts()  //QString::char(built);
    types = QString::fromStdString(type);
    builts = QString::number(built);



    QSqlQuery query(db);
    //query.prepare("UPDATE Computers where ID = (:Compid);");
    query.prepare("UPDATE Computers SET name = (:names), yearBuilt = (:buildYears), type = (:types), built = (:built) WHERE id = (:Compid)");
    query.bindValue(":Compid", Compid);
    query.bindValue(":names", names);
    query.bindValue(":buildYears",buildYears);
    query.bindValue(":types",types);
    query.bindValue(":built",builts);


    //query.prepare("UPDATE Computers SET name =", [build year] = +buildYears+ ", type =" +types+", builts =" +builts+";");
    query.exec();

    //if(!query.exec())
    //{
      //qDebug() << query.lastError();
    //}
    //else
    //{
        //query.exec();
    //qDebug("Updated!");

    //}




        //int id = query.value("id").toInt();
        //string name = query.value("name").toString().toStdString();
        //string type = query.value("type").toString().toStdString();
        //int yearBuilt = query.value("build year").toInt();
        //bool wasBuilt = query.value("built").toBool();

        //Computer computer(id, name, type, yearBuilt, wasBuilt);

        //temp1.push_back(computer);



    //return temp1;

}


vector<Computer> ComputerDatabase::getYearBuilt(int a)
{
    vector<Computer> temp1;

    QString year;
    year = QString::number(a);

    QSqlQuery query(db);
    query.exec("SELECT * FROM Computers WHERE yearBuilt =" +year+";");

    while(query.next())
    {

        int id = query.value("id").toInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt = query.value("yearBuilt").toInt();
        bool built = query.value("built").toBool();

        Computer computer(id, name, type, yearBuilt, built);

          temp1.push_back(computer);
    }
    return temp1;
}


vector<Computer> ComputerDatabase::getType(char type)
{
    QSqlQuery query(db);


   vector<Computer> temp2;

   if(type == 'M'||type == 'm')
    {
       query.exec("SELECT * FROM Computers WHERE type = 'Mechanical';");
       while(query.next())
           {

               int id = query.value("id").toInt();
               string name = query.value("name").toString().toStdString();
               string type = query.value("type").toString().toStdString();
               int yearBuilt = query.value("yearBuilt").toInt();
               int built = query.value("built").toInt();


               Computer computer(id, name, type, yearBuilt, built);
               temp2.push_back(computer);
           }
}

    else if(type == 'E'||type == 'e')
    {
        query.exec("SELECT * FROM Computers WHERE type = 'Electromechanical';");
        while(query.next())
        {
            int id = query.value("id").toInt();
            string name = query.value("name").toString().toStdString();
            string type = query.value("type").toString().toStdString();
            int yearBuilt = query.value("yearBuilt").toInt();
            int built = query.value("built").toInt();

            Computer computer(id, name, type, yearBuilt, built);
            temp2.push_back(computer);
        }
   }

    else if(type == 'T'||type == 't')
   {
       query.exec("SELECT * FROM Computers WHERE type = 'Transistor';");
       while(query.next())
       {
           int id = query.value("id").toInt();
           string name = query.value("name").toString().toStdString();
           string type = query.value("type").toString().toStdString();
           int yearBuilt = query.value("yearBuilt").toInt();
           int built = query.value("built").toInt();

           Computer computer(id, name, type, yearBuilt, built);
           temp2.push_back(computer);
       }
  }
    return temp2;
}

vector<Computer> ComputerDatabase::getBuilt(char built)
{
    vector<Computer> temp4;

    QSqlQuery query(db);

    if((built == 'Y'||built == 'y')/*&& build == 1)*/)
    {
      query.exec("SELECT * FROM Computers WHERE built = '1';");

      while(query.next())
      {
        int id = query.value("id").toInt();
        string name = query.value("name").toString().toStdString();
        string type = query.value("type").toString().toStdString();
        int yearBuilt = query.value("yearBuilt").toInt();
        int built = query.value("built").toUInt();

        Computer computer(id, name, type, yearBuilt, built);

          temp4.push_back(computer);
      }
    }
    else if(built =='N'||built =='n'/*build ==0*/)
    {

        query.exec("SELECT * FROM Computers WHERE built = '0';");

        while(query.next())
        {
          int id = query.value("id").toInt();
          string name = query.value("name").toString().toStdString();
          string type = query.value("type").toString().toStdString();
          int yearBuilt = query.value("yearBuilt").toInt();
          int built = query.value("built").toUInt();

          Computer computer(id, name, type, yearBuilt, built);
           temp4.push_back(computer);
        }
    }
    return temp4;
}


vector<Computer> ComputerDatabase::getName (string name)
{

   vector<Computer> temp;
   QString computerName;
   computerName = QString::fromStdString(name);

   QSqlQuery query(db);
   query.exec("SELECT * FROM Computers WHERE name LIKE '%" + computerName+ "%';");

   while (query.next())
   {
       int id = query.value("id").toInt();
       string name = query.value("name").toString().toStdString();
       string type = query.value("type").toString().toStdString();
       int yearBuilt = query.value("yearBuilt").toInt();
       int built = query.value("built").toInt();

       Computer computer(id, name, type, yearBuilt, built);
       temp.push_back(computer);
   }
 return temp;
}






