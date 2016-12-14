#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    displayAllConnections();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::displayAllConnections()
{
    vector<Scientist> scientists = scientistService.getScientists();
    ui->ConnectionTable->setRowCount(scientists.size());

    qDebug() << scientists.size() << endl;

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        vector<Computer> computersConnected = computerService.getScientistID(scientists[i].getID());
        for(unsigned int j = 0; j < computersConnected.size(); j++)
        {
            ui->ConnectionTable->setItem(i, 0, new QTableWidgetItem(QString::number(scientists[i].getID())));
            ui->ConnectionTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));

            ui->ConnectionTable->setItem(j, 2, new QTableWidgetItem(QString::number(computersConnected[j].getID())));
            ui->ConnectionTable->setItem(j, 3, new QTableWidgetItem(QString::fromStdString(computersConnected[j].getComputerName())));
        }
    }
}

void ConnectionDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ConnectionTable->clear();

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        vector<Computer> computersConnected = computerService.getScientistID(scientists[i].getID());
        for(unsigned int j = 0; j < computersConnected.size(); j++)
        {
            ui->ConnectionTable->setItem(i, 0, new QTableWidgetItem(QString::number(scientists[i].getID())));
            ui->ConnectionTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));

            ui->ConnectionTable->setItem(i, 2, new QTableWidgetItem(QString::number(computersConnected[j].getID())));
            ui->ConnectionTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(computersConnected[j].getComputerName())));
        }
    }
}

void ConnectionDialog::displayComputers(vector<Computer> computers)
{
    // eitthvað rugl í gangi, search virkar ekki
    ui->ConnectionTable->clear();

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        vector<Scientist> scientistsConnected = scientistService.getComputerID(computers[i].getID());
        for(unsigned int j = 0; j < scientistsConnected.size(); j++)
        {
            ui->ConnectionTable->setItem(j, 0, new QTableWidgetItem(QString::number(scientistsConnected[i].getID())));
            ui->ConnectionTable->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(scientistsConnected[i].getName())));

            ui->ConnectionTable->setItem(i, 2, new QTableWidgetItem(QString::number(computers[j].getID())));
            ui->ConnectionTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(computers[j].getComputerName())));
        }
    }
}

void ConnectionDialog::on_SearchScientistName_textChanged(const QString &arg1)
{
    string input = ui->SearchScientistName->text().toStdString();

    vector<Scientist> scientists = scientistService.searchName(input);
    displayScientists(scientists);
}

void ConnectionDialog::on_SearchScientistName_2_textChanged(const QString &arg1)
{
    string input = ui->SearchComputerName->text().toStdString();

    vector<Computer> computers = computerService.searchComputerName(input);
    displayComputers(computers);
}
