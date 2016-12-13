#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

#include <string>
#include <QString>

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
    ui->PickGender->addItem("Male");
    ui->PickGender->addItem("Female");

}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_AddScientist_clicked()
{




    QString name = ui->InputScientistName->text();
    //QString gender = "Male";
    //QString gender = ui->PickGender->c
    QString gender = ui->PickGender->currentText();
    QString yearOfBirth = ui->InputScientistYearOfBirth->text();
    QString yearOfDeath = ui->InputScientistYearOfDeath->text();





    bool emptyError = false;

    bool birthError = false;
    bool future = false;

    ui->label_name_error->setText("");
    ui->label_birth_error->setText("");
    ui->label_Death_error->setText("");
    ui->label_gender_error->setText("");


// Ef ekkert er skrifað inn virka villuskilaboðin,
    // ef eitthvað er síðan skrifað í year of birth, hverfa villuskilaboð fyrir birth OG death einhverra hluta vegna
        // villuskilaboð fyrir allt sem viðkemur int virkar ekki þó kóðinn sé réttur


    if(name.isEmpty())
    {
        //cout << "Pleas enter a name" << endl;

        ui->label_name_error->setText("<span style='color: red'>Name cannot be empty!</span>");
        emptyError = true;


    }

    if(yearOfBirth.isEmpty())
    {
        //cout << "Please enter a year of birth" << endl;

        ui->label_birth_error->setText("<span style='color: red'>Birth Date cannot be empty!</span>");
        emptyError = true;

    if(yearOfDeath.isEmpty())
    {
        //cout << "Pleas enter a year of death" << endl;
        ui->label_Death_error->setText("<span style='color: red'>Year of death cannot be empty!</span>");
        emptyError = true;
    }



    if(yearOfBirth.toInt())
    {
        if(yearOfBirth.toInt() < 0)
        {
            //cout << "Year of birth cannot be a negative number" << endl;
            ui->label_birth_error->setText("<span style='color: red'>Year of birth cannot be a negative number</span>");
            //return;
        }

    if(yearOfBirth.toInt() > 2016)
    {
        ui->label_birth_error->setText("<span style='color: red'>A person cannot be born in the future</span>");
        //thereWasAnError = true;
        //cout << "A person cannot be born in the future" << endl;
        //birthError = true;
        //return;
    }
}


    if(yearOfDeath.toInt() < 0)
    {
        //cout << "Year of death cannot be a negative number" << endl;
        ui->label_Death_error->setText("<span style='color: red'>Year of Death cannot be a negative number!</span>");
        //negativeError = true;
        //return;
    }


    if(yearOfDeath.toInt() > 2016)
    {
        //cout << "Invalid Date" << endl;
        ui->label_Death_error->setText("<span style='color: red'>Invalid date!</span>");
        //thereWasAnError = true;
        //return;
    }

    if(yearOfDeath < yearOfBirth)
    {
        //cout << "A person cannot die before its born" << endl;
        ui->label_Death_error->setText("<span style='color: red'>A person cannot die before its born!</span>");
        //thereWasAnError = true;
        //return;
    }

    if (emptyError)
    {
        return;
    }

   // if(birthError)
   // {
     //   return;
    //}

    //else if (future)
    //{
      //  return;

    //}

    //bool success = scientistService.create(Scientist(name.toStdString(), gender.toStdString(), yearOfBirth.toInt(), yearOfDeath.toInt()));

    /*if(success)
    {

    }
    else
    {
        cout << "failed to create scientist";
    }*/




}
    }




