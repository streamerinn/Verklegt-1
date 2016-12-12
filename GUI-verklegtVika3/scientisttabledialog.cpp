#include "scientisttabledialog.h"
#include "ui_scientisttabledialog.h"

ScientistTableDialog::ScientistTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistTableDialog)
{
    ui->setupUi(this);
}

ScientistTableDialog::~ScientistTableDialog()
{
    delete ui;
}

void ScientistTableDialog::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getScientists();
    ui->ScientistTable->setRowCount(scientists.size());

    qDebug() << scientists.size() << endl;

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
       ui->ScientistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
       ui->ScientistTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getGender())));
       ui->ScientistTable->setItem(i, 2, new QTableWidgetItem(QString::number(scientists[i].getDateOfBirth())));
       ui->ScientistTable->setItem(i, 3, new QTableWidgetItem(QString::number(scientists[i].getDateOfDeath())));
    }
}

void ScientistTableDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ScientistTable->clear();

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        ui->ScientistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
        ui->ScientistTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getGender())));
        ui->ScientistTable->setItem(i, 2, new QTableWidgetItem(QString::number(scientists[i].getDateOfBirth())));
        ui->ScientistTable->setItem(i, 3, new QTableWidgetItem(QString::number(scientists[i].getDateOfDeath())));
    }

}


void ScientistTableDialog::on_ScientistSearch_textChanged()
{
    string userInput = ui->ScientistSearch->text().toStdString();

    vector<Scientist> scientists = scientistService.searchName(userInput);
    displayScientists(scientists);

}

void ScientistTableDialog::on_AddANewScientist_clicked()
{
    AddScientistDialog addScientistDialog;
    int addScientistReturnValue = addScientistDialog.exec();
}
