#include "scientisttabledialog.h"
#include "ui_scientisttabledialog.h"

ScientistTableDialog::ScientistTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistTableDialog)
{
    // Fjarlægir '?' hjálp takkann
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->setupUi(this);
    displayAllScientists();
}

ScientistTableDialog::~ScientistTableDialog()
{
    delete ui;
}

void ScientistTableDialog::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getScientists();
    ui->ScientistTable->setRowCount(scientists.size());

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        ui->ScientistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
        ui->ScientistTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getGender())));
        ui->ScientistTable->setItem(i, 2, new QTableWidgetItem(QString::number(scientists[i].getDateOfBirth())));
        if(scientists[i].getDateOfDeath() == 0)
            ui->ScientistTable->setItem(i, 3, new QTableWidgetItem("Alive"));
        else
            ui->ScientistTable->setItem(i, 3, new QTableWidgetItem(QString::number(scientists[i].getDateOfDeath())));
    }
    QString stylesheet = "::section{"
                             "spacing: 10px;"
                            "background-color: gray;"
                            "color: white;}";
    ui->ScientistTable->horizontalHeader()->setStyleSheet(stylesheet);
    ui->ScientistTable->verticalHeader()->setStyleSheet(stylesheet);
}

void ScientistTableDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ScientistTable->clearContents();


    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        ui->ScientistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
        ui->ScientistTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getGender())));
        ui->ScientistTable->setItem(i, 2, new QTableWidgetItem(QString::number(scientists[i].getDateOfBirth())));
        if(scientists[i].getDateOfDeath() == 0)
            ui->ScientistTable->setItem(i, 3, new QTableWidgetItem("Alive"));
        else
            ui->ScientistTable->setItem(i, 3, new QTableWidgetItem(QString::number(scientists[i].getDateOfDeath())));
    }

}

void ScientistTableDialog::on_AddANewScientist_clicked()
{
    AddScientistDialog addScientistDialog(this);
    addScientistDialog.exec();
}

void ScientistTableDialog::on_ScientistSearch_textChanged()
{
    string input = ui->ScientistSearch->text().toStdString();

    vector<Scientist> scientists = scientistService.searchName(input);
    displayScientists(scientists);
}

void ScientistTableDialog::on_editDelete_clicked()
{
    EditDeletScientist editDeletScientist(this);
    editDeletScientist.exec();
}
