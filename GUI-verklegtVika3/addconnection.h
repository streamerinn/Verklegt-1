#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QDialog>
#include "connectionservice.h"

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


private:
    Ui::AddConnection *ui;
    ConnectionService connectionService;
};

#endif // ADDCONNECTION_H
