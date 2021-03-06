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
            ui->txtYearBuilt->setText(yearbuilt);
            if(computers[i].getBuilt()==1)
                ui->Yes->setChecked(true);
            else
                ui->No->setChecked(true);

            if(computers[i].getType()=="Electronic")
            {
                ui->Electronic->setChecked(true);
            }
            else if(computers[i].getType()=="Mechanical")
            {
                ui->Mechanical->setChecked(true);
            }
            else if(computers[i].getType()=="Digital")
            {
                ui->Digital->setChecked(true);
            }
            else if(computers[i].getType()=="Transistor")
            {
                ui->Transistor->setChecked(true);
            }
            else if(computers[i].getType()=="Electromechanical")
            {
                ui->Electromechanical->setChecked(true);
            }
            else
            {
                ui->Other->setChecked(true);
            }
            break;
        }
    }
}

void EditDeleteComputer::on_Delete_clicked()
{
    int ID = ui->txtID->text().toInt();

    computerservice.deleteComputer(ID);
    displayAllCpu();
    ui->txtID->clear();
    ui->txtName->clear();
    ui->txtYearBuilt->clear();
    ui->Yes->setAutoExclusive(false);
    ui->Yes->setChecked(false);
    ui->No->setAutoExclusive(false);
    ui->No->setChecked(false);
    ui->Electronic->setAutoExclusive(false);
    ui->Electronic->setChecked(false);
    ui->Transistor->setAutoExclusive(false);
    ui->Transistor->setChecked(false);
    ui->Mechanical->setAutoExclusive(false);
    ui->Mechanical->setChecked(false);
    ui->Electromechanical->setAutoExclusive(false);
    ui->Electromechanical->setChecked(false);
    ui->Other->setAutoExclusive(false);
    ui->Other->setChecked(false);

}

void EditDeleteComputer::on_editComputer_clicked()
{
    string name = ui->txtName->text().toStdString();
    string type;
    int yearbuilt = ui->txtYearBuilt->text().toInt();
    int ID = ui->txtID->text().toInt();
    int built;

    if(ui->Yes->isChecked())
        built = 1;
    else
        built = 0;

    if(ui->Electronic->isChecked())
    {
        type = "Electronic";
    }
    else if(ui->Mechanical->isChecked())
    {
        type = "Mechanical";
    }
    else if(ui->Digital->isChecked())
    {
        type = "Digital";
    }
    else if(ui->Transistor->isChecked())
    {
        type = "Transistor";
    }
    else if(ui->Electromechanical->isChecked())
    {
        type = "Electromechanical";
    }
    else
    {
        type = "Other";
    }


    computerservice.editComputer(name,ID,yearbuilt,built,type);
    displayAllCpu();

}
