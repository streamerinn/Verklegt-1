#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    displayAllConnections();
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::displayAllConnections()
{
    vector<Scientist> bothIDs = connectionService.getConnectionIDs();

    ui->ConnectionTable->setRowCount(bothIDs.size()/2);
    for(unsigned int i = 0; i < bothIDs.size(); i += 2)
    {
        ui->ConnectionTable->setItem(i/2, 0, new QTableWidgetItem(QString::number(bothIDs[i].getID())));
        ui->ConnectionTable->setItem(i/2, 1, new QTableWidgetItem(QString::fromStdString(bothIDs[i].getName())));
        ui->ConnectionTable->setItem(i/2, 2, new QTableWidgetItem(QString::number(bothIDs[i+1].getID())));
        ui->ConnectionTable->setItem(i/2, 3, new QTableWidgetItem(QString::fromStdString(bothIDs[i+1].getName())));
    }
}

void ConnectionDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ConnectionTable->clearContents();

    ui->ConnectionTable->setRowCount(scientists.size()/2);
    for(unsigned int i = 0; i < scientists.size(); i += 2)
    {
        ui->ConnectionTable->setItem(i/2, 0, new QTableWidgetItem(QString::number(scientists[i].getID())));
        ui->ConnectionTable->setItem(i/2, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
        ui->ConnectionTable->setItem(i/2, 2, new QTableWidgetItem(QString::number(scientists[i+1].getID())));
        ui->ConnectionTable->setItem(i/2, 3, new QTableWidgetItem(QString::fromStdString(scientists[i+1].getName())));
    }
}

void ConnectionDialog::on_SearchScientistName_textChanged()
{
    string input = ui->SearchScientistName->text().toStdString();

    vector<Scientist> scientists = connectionService.searchScientistName(input);
    qDebug() << scientists.size() <<endl;
    qDebug() << QString::fromStdString(input) << endl;

    displayScientists(scientists);

    qDebug() << "wut" << endl;

}

void ConnectionDialog::on_SearchComputerName_textChanged()
{
    string input = ui->SearchComputerName->text().toStdString();

    vector<Scientist> scientists = connectionService.searchComputerName(input);
    qDebug() << scientists.size() <<endl;
    qDebug() << QString::fromStdString(input) << endl;

    displayScientists(scientists);

    qDebug() << "wut" << endl;
}
