#include "editdeletecomputer.h"
#include "ui_editdeletecomputer.h"

EditDeleteComputer::EditDeleteComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeleteComputer)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    displayAllCpu();
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

    // Used to color the horizontal header and vertical header in the edit delete computer
    //from the default white color
    QString stylesheet = "::section{"
                             "spacing: 10px;"
                            "background-color: gray;"
                            "color: white;}";
    ui->Names->horizontalHeader()->setStyleSheet(stylesheet);
    ui->Names->verticalHeader()->setStyleSheet(stylesheet);
}

void EditDeleteComputer::on_searchComputer_textChanged()
{
    string input = ui->searchComputer->text().toStdString();

    vector<Computer> computers = computerservice.searchComputerName(input);
    displayCpu(computers);
}

//shows information about computer when computer name is clicked
void EditDeleteComputer::on_Names_cellClicked(int row, int column)
{
    vector<Computer> computers = computerservice.getComputers();
    QString nafn = ui->Names->item(row,column)->text();
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if(nafn.toStdString()==computers[i].getComputerName())
        {
            QString ID = QString::number(computers[i].getID());
            QString yearbuilt = QString::number(computers[i].getYearBuilt());

            ui->txtID->setText(ID);
            ui->txtName->setText(nafn);
            ui->txtYearBuilt->setText(yearbuilt);
            //setting values to radio buttons
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
    //clear all information
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
