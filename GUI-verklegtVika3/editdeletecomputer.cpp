#include "editdeletecomputer.h"
#include "ui_editdeletecomputer.h"

EditDeleteComputer::EditDeleteComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeleteComputer)
{
    ui->setupUi(this);
    displayAllCpu();
    on_searchComputer_textChanged();

}

EditDeleteComputer::~EditDeleteComputer()
{
    delete ui;
}

void EditDeleteComputer::displayAllCpu()
{
    vector<Computer> computers = computerservice.getComputers();
    ui->Names->setRowCount(computers.size());

    for(unsigned int i = 0; i < computers.size(); i++)
    {
       ui->Names->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(computers[i].getComputerName())));
    }
}

void EditDeleteComputer::displayCpu(vector<Computer> computers)
{
    ui->Names->clear();
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ui->Names->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(computers[i].getComputerName())));
    }

}
void EditDeleteComputer::on_searchComputer_textChanged()
{
    string input = ui->searchComputer->text().toStdString();

    vector<Computer> computers = computerservice.searchComputerName(input);
    displayCpu(computers);
}

void EditDeleteComputer::on_Names_cellClicked(int row, int column)
{
    vector<Computer> computers = computerservice.getComputers();
    QString nafn =ui->Names->item(row,column)->text();
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if(nafn.toStdString()==computers[i].getComputerName())
        {
            QString ID = QString::number(computers[i].getID());
            QString Type = QString::fromStdString(computers[i].getType());
            QString yearbuilt = QString::number(computers[i].getYearBuilt());
            QString built = QString::number(computers[i].getBuilt());

            ui->txtID->setText(ID);
            ui->txtName->setText(nafn);
            ui->txtType->setText(Type);
            ui->txtYearBuilt->setText(yearbuilt);
            ui->txtMade->setText(built);

            break;
        }
    }
}

void EditDeleteComputer::on_Delete_clicked()
{
    int ID = ui->txtID->text().toInt();

    ComputerDatabase test;

    test.deleteComputer(ID);
    ui->txtID->clear();
    ui->txtName->clear();
    ui->txtYearBuilt->clear();
    ui->txtType->clear();
    ui->txtMade->clear();
}

void EditDeleteComputer::on_editComputer_clicked()
{
    string name = ui->txtName->text().toStdString();
    string type = ui->txtType->text().toStdString();
    int yearbuilt = ui->txtYearBuilt->text().toInt();
    int built = ui->txtMade->text().toInt();
    int ID = ui->txtID->text().toInt();

    ComputerDatabase test;

    test.editComputer(name,ID,yearbuilt,built,type);
}
