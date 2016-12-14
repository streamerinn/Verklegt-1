#include "computertabledialog.h"
#include "ui_computertabledialog.h"

ComputerTableDialog::ComputerTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerTableDialog)
{
    ui->setupUi(this);
    displayAllComputers();
    on_ComputerSearch_textChanged();
}

ComputerTableDialog::~ComputerTableDialog()
{
    delete ui;
}

void ComputerTableDialog::displayAllComputers()
{
    vector<Computer> computers = computerService.getComputers();
    ui->ComputerTable->setRowCount(computers.size());

    qDebug() << computers.size() << endl;

    for(unsigned int i = 0; i < computers.size(); i++)
    {
       ui->ComputerTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(computers[i].getComputerName())));
       ui->ComputerTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(computers[i].getType())));
       ui->ComputerTable->setItem(i, 2, new QTableWidgetItem(QString::number(computers[i].getYearBuilt())));
       ui->ComputerTable->setItem(i, 3, new QTableWidgetItem(QString::number(computers[i].getBuilt())));
    }
}

void ComputerTableDialog::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->clear();

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ui->ComputerTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(computers[i].getComputerName())));
        ui->ComputerTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(computers[i].getType())));
        ui->ComputerTable->setItem(i, 2, new QTableWidgetItem(QString::number(computers[i].getYearBuilt())));
        ui->ComputerTable->setItem(i, 3, new QTableWidgetItem(QString::number(computers[i].getBuilt())));
    }


}

void ComputerTableDialog::on_ComputerSearch_textChanged()
{
    string input = ui->ComputerSearch->text().toStdString();

    vector<Computer> computers = computerService.searchComputerName(input);
    displayComputers(computers);

}

void ComputerTableDialog::on_AddANewComputer_clicked()
{

    AddANewComputerDialog addANewComputer;

    int addComputerReturnValue = addANewComputer.exec();
}

void ComputerTableDialog::on_button_remove_computer_clicked()
{

}
