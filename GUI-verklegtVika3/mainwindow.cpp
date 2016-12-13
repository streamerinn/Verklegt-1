#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_computers_clicked()
{
    //Computer computers;
    //computers->show();
    //this->hide();

    ComputerTableDialog computerTableDialog;
    computerTableDialog.exec();
}

void MainWindow::on_button_scientist_clicked()
{

    //Scientist scientists;
    //scientists->show();
    //this->hide();

    ScientistTableDialog scientistTableDialog;
    scientistTableDialog.exec();

    //scientistTable = new ScientistTableDialog(this);
    //scientistTable->show();
    //this->hide();

}

void MainWindow::on_button_linked_clicked()
{

}

