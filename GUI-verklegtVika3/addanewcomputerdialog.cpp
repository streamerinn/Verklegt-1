#include "addanewcomputerdialog.h"
#include "ui_addanewcomputerdialog.h"

AddANewComputerDialog::AddANewComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddANewComputerDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    ui->input_computer_type->addItem("Mechanical");
    ui->input_computer_type->addItem("Electronical");
    ui->input_computer_type->addItem("Transistor");

    ui->input_if_built->addItem("Yes");
    ui->input_if_built->addItem("No");
}

AddANewComputerDialog::~AddANewComputerDialog()
{
    delete ui;
}

void AddANewComputerDialog::on_pushButton_clicked()
{

    QString name = ui->input_computer_name->text();
    QString type = ui->input_computer_type->currentText();
    QString buildYear = ui->input_computer_build_year->text();
    QString built = ui->input_if_built->currentText();
    QRegExp validInput("\\d*");

    ui->label_error_computer_name_2->setText("");
    ui->label_error_build_year_2->setText("");
    ui->label_error_computerType->setText("");
    ui->label_error_if_built->setText("");

    bool emptyError = false;
    bool invalidInput = false;

    qDebug() << "-" << name <<"--" << name.length();

    if(name.isEmpty())
    {
        ui->label_error_computer_name_2->setText("<span style='color: red'>Name cannot be empty!</span>");
        emptyError = true;

    }

    if (buildYear.isEmpty())
    {
        ui->label_error_build_year_2->setText("<span style='color: red'>Build Year cannot be empty!</span>");
        emptyError = true;
    }

    if(!validInput.exactMatch(buildYear))
    {
        ui->label_error_build_year_2->setText("<span style='color: red'>Invalid Buildyear</span>");
        invalidInput = true;
    }

    string computerName = name.toStdString();

    string Ctype = type.toStdString();
    int CbuildYear = buildYear.toInt();
    string Cbuilt = built.toStdString();

    int tempBuilt;

    if (Cbuilt == "Yes")
    {
        tempBuilt = 1;
    }
    else if (Cbuilt =="No")
    {
        tempBuilt = 0;
    }

    if(emptyError)
    {
        return;
    }

    if (invalidInput)
    {
        return;
    }


    Computer computer(computerName, Ctype, CbuildYear, tempBuilt);
    computerservice.create(computer);
    close();



    //if (type.isEmpty())
    //{
      //  ui->label_error_computer_type->setText("<span style='color: red'>Name cannot be empty!</span>");

    //}








}
