#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

#include <string>

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_AddScientist_clicked()
{
    QString name = ui->InputScientistName->text();
    QString gender = "Male";
    QString yearOfBirth = ui->InputScientistYearOfBirth->text();
    QString yearOfDeath = ui->InputScientistYearOfDeath->text();

    if(name.isEmpty())
    {
        cout << "Pleas enter a name" << endl;
    }

    if(yearOfBirth.isEmpty())
    {
        cout << "Please enter a year of birth" << endl;
    }

    if(yearOfDeath.isEmpty())
    {
        cout << "Pleas enter a year of death" << endl;
    }

    else if(yearOfBirth.toInt() < 0)
    {
        cout << "Year of birth cannot be a negative number" << endl;
    }

    else if(yearOfBirth.toInt() > 2016)
    {
        cout << "A person cannot be born in the future" << endl;
    }

    if(yearOfDeath.toInt() < 0)
    {
        cout << "Year of death cannot be a negative number" << endl;
    }

    else if(yearOfDeath.toInt() > 2016)
    {
        cout << "Invalid Date" << endl;
    }

    if(yearOfDeath < yearOfBirth)
    {
        cout << "A person cannot die before its born" << endl;
    }

    //bool success = scientistService.create(Scientist(name.toStdString(), gender.toStdString(), yearOfBirth.toInt(), yearOfDeath.toInt()));

    /*if(success)
    {

    }
    else
    {
        cout << "failed to create scientist";
    }*/


}


