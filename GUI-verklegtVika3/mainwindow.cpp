#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======

>>>>>>> e1ccf477d267d3bccd25666b8679585badab07f8

}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD

=======

void MainWindow::on_button_computers_clicked()
{
    //Computer computers;
    //computers->show();
    //this->hide();


}

void MainWindow::on_button_scientist_clicked()
{

    //Scientist scientists;
    //scientists->show();
    //this->hide();

}

void MainWindow::on_button_linked_clicked()
{

}
>>>>>>> e1ccf477d267d3bccd25666b8679585badab07f8
