#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QDialog>
#include "connectionservice.h"
#include "scientistservice.h"
#include "computerservice.h"

namespace Ui {
class AddConnection;
}

class AddConnection : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnection(QWidget *parent = 0);
    ~AddConnection();

private slots:
    void on_addButton_clicked();

    void on_idTable_activated();

private:
    Ui::AddConnection *ui;
    ConnectionService connectionService;
    ScientistService scientistServie;
    ComputerService computerService;
};

#endif // ADDCONNECTION_H
