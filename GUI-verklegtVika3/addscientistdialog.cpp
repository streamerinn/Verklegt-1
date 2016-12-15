#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

#include <string>
#include <QString>

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_AddScientist_clicked()
{
    QString name = ui->InputScientistName->text();
    QString gender = ui->PickGender->currentText();
    QString yearOfBirth = ui->InputScientistYearOfBirth->text();
    QString yearOfDeath = ui->InputScientistYearOfDeath->text();
    QString image = ui->insert_image->text();



    QRegExp validName("\\d*");
    QRegExp validInput("\\d*");

    bool emptyError = false;
    bool invalidInput = false;
    bool birthError = false;

    ui->label_name_error->setText("");
    ui->label_birth_error->setText("");
    ui->label_Death_error->setText("");
    ui->label_gender_error->setText("");


    if(name.isEmpty())
    {
        ui->label_name_error->setText("<span style='color: red'>Name cannot be empty!</span>");
        emptyError = true;
    }

    else if(validName.exactMatch(name))
    {
        ui->label_name_error->setText("<span style='color: red'>Invalid name!</span>");
    }

    if(yearOfBirth.isEmpty())
    {
        ui->label_birth_error->setText("<span style='color: red'>Birth Date cannot be empty!</span>");
        emptyError = true;
    }

    if(yearOfDeath.isEmpty())
    {
        ui->label_Death_error->setText("<span style='color: red'>Year of death cannot be empty!</span>");
        emptyError = true;
    }

    else if(yearOfDeath.toInt() < yearOfBirth.toInt())
    {
        ui->label_Death_error->setText("<span style='color: red'>A person cannot die before its born!</span>");
        birthError = true;
    }

    if(!validInput.exactMatch(yearOfBirth))
    {
        ui->label_birth_error->setText("<span style='color: red'>Invalid Birthyear</span>");
        invalidInput = true;
    }

    if(!validInput.exactMatch(yearOfDeath))
    {
        ui->label_Death_error->setText("<span style='color: red'>Invalid Deathyear</span>");
        invalidInput = true;
    }

    if(yearOfBirth.toInt() < 0)
    {
        ui->label_birth_error->setText("<span style='color: red'>Year of birth cannot be a negative number</span>");
        birthError = true;
    }

    if(yearOfBirth.toInt() > 2016)
    {
        ui->label_birth_error->setText("<span style='color: red'>A person cannot be born in the future</span>");
        birthError = true;
    }

    if(yearOfDeath.toInt() < 0)
    {
        ui->label_Death_error->setText("<span style='color: red'>Year of Death cannot be a negative number!</span>");
    }


    if(yearOfDeath.toInt() > 2016)
    {
        ui->label_Death_error->setText("<span style='color: red'>Invalid date!</span>");
    }

   if (emptyError)
   {
        return;
   }

    if (birthError)
    {
        return;
    }

    if (invalidInput)
    {
        return;
    }

    string scientistName = name.toStdString();

    string scientistGender = gender.toStdString();
    int SyearOfBirth = yearOfBirth.toInt();
    int SyearOfDeath = yearOfDeath.toInt();
    Scientist scientist(scientistName, scientistGender, SyearOfBirth, SyearOfDeath);

    scientistService.create(scientist);
    close();
}

void AddScientistDialog::on_browse_button_clicked()
{

   QString filename = QFileDialog::getOpenFileName(
                       this,
                        "Open Document",
                        QDir::currentPath(),
                        "Images (*.png *.jpg");

   if(!filename.isNull())
   {
       QPixmap pixmap(filename);
       ui->insert_image->setText(filename.toUtf8());
        QByteArray inByteArray;
       QBuffer inbuffer( &inByteArray);
       inbuffer.open(QIODevice::WriteOnly);
       pixmap.save( &inbuffer, "JPG");
   }
   else
   {
       ui->insert_image->setText("/images/build-GUI-Verklegt3-Desktop_Qt_5_7_0_MinGW_32bit-Debug/images/default.jpg");
   }
}
