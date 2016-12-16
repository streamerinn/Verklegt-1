#include "computertabledialog.h"
#include "ui_computertabledialog.h"

ComputerTableDialog::ComputerTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerTableDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    displayAllComputers();
    //on_ComputerSearch_textChanged(); <- þarf ekki
}
//*******DESTRUCTOR*********************
ComputerTableDialog::~ComputerTableDialog()
{
    delete ui;
}

void ComputerTableDialog::displayAllComputers()
{
    vector<Computer> computers = computerService.getComputers();
    ui->ComputerTable->setRowCount(computers.size());

    displayComputers(computers);
}

void ComputerTableDialog::displayComputers(vector<Computer> computers)
{
    ui->ComputerTable->clearContents();

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        ui->ComputerTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(computers[i].getComputerName())));
        ui->ComputerTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(computers[i].getType())));
        if(computers[i].getBuilt() == 1)
        {
            ui->ComputerTable->setItem(i, 2, new QTableWidgetItem(QString::number(computers[i].getYearBuilt())));
            ui->ComputerTable->setItem(i, 3, new QTableWidgetItem("Yes"));
        }
        else
        {
            ui->ComputerTable->setItem(i, 2, new QTableWidgetItem("N/A"));
            ui->ComputerTable->setItem(i, 3, new QTableWidgetItem("No"));
        }

        // Used to color the horizontal header and vertical header in the Computertable
        QString stylesheet = "::section{"
                                 "spacing: 10px;"
                                "background-color: gray;"
                                "color: white;}";
        ui->ComputerTable->horizontalHeader()->setStyleSheet(stylesheet);
        ui->ComputerTable->verticalHeader()->setStyleSheet(stylesheet);

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

    AddANewComputerDialog addANewComputer(this);
    addANewComputer.exec();


}

void ComputerTableDialog::on_editDelete_clicked()
{
    EditDeleteComputer editDeleteComputer(this);
    editDeleteComputer.exec();
}
