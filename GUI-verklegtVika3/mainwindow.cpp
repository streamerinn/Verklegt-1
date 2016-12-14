#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    darktheme = false;
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

    ComputerTableDialog computerTableDialog(this);
    computerTableDialog.exec();
}

void MainWindow::on_button_scientist_clicked()
{

    //Scientist scientists;
    //scientists->show();
    //this->hide();

    ScientistTableDialog scientistTableDialog(this);
    scientistTableDialog.exec();

    //scientistTable = new ScientistTableDialog(this);
    //scientistTable->show();
    //this->hide();

}

void MainWindow::on_button_link_clicked()
{
    ConnectionDialog connectionDialog(this);
    connectionDialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}

void MainWindow::on_toggle_theme_clicked()
{
    if(!darktheme)
    {
        this->setStyleSheet("*{background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QHeaderView::section {background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QTableWidget QTableCornerButton::section {background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QMenu {selection-background-color: rgb(51, 153, 255);}");
        darktheme = true;
    }
    else
    {
        this->setStyleSheet("");
        darktheme = false;
    }

}
