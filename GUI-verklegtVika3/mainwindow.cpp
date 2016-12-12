#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayAllScientists();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
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

void MainWindow::displayScientists(vector<Scientist> scientists)
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


void MainWindow::on_ScientistSearch_textChanged()
{
    string userInput = ui->ScientistSearch->text().toStdString();

    vector<Scientist> scientists = scientistService.searchName(userInput);
    displayScientists(scientists);

}
