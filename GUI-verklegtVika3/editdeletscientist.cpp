#include "editdeletscientist.h"
#include "ui_editdeletscientist.h"

EditDeletScientist::EditDeletScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDeletScientist)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    displayAllScientists();
}

EditDeletScientist::~EditDeletScientist()
{
    delete ui;
}

void EditDeletScientist::displayAllScientists()
{
    vector<Scientist> scientists = scientistService1.getScientists();
    ui->Names->setRowCount(scientists.size());

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
       ui->Names->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
    }

    QString stylesheet = "::section{"
                             "spacing: 10px;"
                            "background-color: gray;"
                            "color: white;}";
    ui->Names->horizontalHeader()->setStyleSheet(stylesheet);
    ui->Names->verticalHeader()->setStyleSheet(stylesheet);
}

void EditDeletScientist::displayScientists(vector<Scientist> scientists)
{
    ui->Names->clear();
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        ui->Names->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
    }
}

void EditDeletScientist::on_ScientistSearch_textChanged()
{
    string input = ui->ScientistSearch->text().toStdString();

    vector<Scientist> scientists = scientistService1.searchName(input);
    displayScientists(scientists);
}
//function that activates textboxes when a cell in the table name is clicked
void EditDeletScientist::on_Names_cellClicked(int row, int column)
{
    vector<Scientist> scientists = scientistService1.getScientists();
    QString nafn =ui->Names->item(row,column)->text();
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        if(nafn.toStdString()==scientists[i].getName())
        {
            //getting information about chosen scientist
            QString gender = QString::fromStdString(scientists[i].getGender());
            QString born = QString::number(scientists[i].getDateOfBirth());
            QString died = QString::number(scientists[i].getDateOfDeath());
            QString ID = QString::number(scientists[i].getID());
            ui->txtName->setText(nafn);
            ui->txtBorn->setText(born);
            ui->txtDied->setText(died);
            ui->txtID->setText(ID);
            if(scientists[i].getGender()=="Male")
            {
                ui->Male->setChecked(true);
            }
            else if(scientists[i].getGender()=="Female")
            {
                ui->Female->setChecked(true);
            }

            break;
        }
    }
}

void EditDeletScientist::on_editScientist_clicked()
{
  //making appropriate varables from textboxes and buttons
  string name = ui->txtName->text().toStdString();
  int born = ui->txtBorn->text().toInt();
  int died = ui->txtDied->text().toInt();
  int ID = ui->txtID->text().toInt();
  string gender;
  if(ui->Female->isChecked())
  {
      gender = "Female";
  }
  else if(ui->Male->isChecked())
  {
      gender = "Male";
  }

  scientistService1.editScientist(ID,gender,name,born,died);
  displayAllScientists();
}
//Delete scientist
void EditDeletScientist::on_Delete_clicked()
{
    int ID = ui->txtID->text().toInt();

    scientistService1.deleteScientist(ID);
    displayAllScientists();

    //clear all information about deleted scientist
    ui->txtID->clear();
    ui->txtName->clear();
    ui->txtBorn->clear();
    ui->txtDied->clear();
    ui->Male->setAutoExclusive(false);
    ui->Male->setChecked(false);
    ui->Female->setAutoExclusive(false);
    ui->Female->setChecked(false);
}

