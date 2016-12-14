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

            ui->ConnectionTable->setItem(i, 2, new QTableWidgetItem(QString::number(computersConnected[j].getID())));
            ui->ConnectionTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(computersConnected[j].getComputerName())));
        }
    }
}

void ConnectionDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ConnectionTable->clearContents();

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

void ConnectionDialog::on_SearchScientistName_textChanged(const QString &arg1)
{

}
