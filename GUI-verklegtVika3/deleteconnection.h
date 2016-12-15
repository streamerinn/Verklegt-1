#ifndef DELETECONNECTION_H
#define DELETECONNECTION_H

#include <QDialog>
#include "connectionservice.h"

namespace Ui {
class DeleteConnection;
}

class DeleteConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConnection(QWidget *parent = 0);
    ~DeleteConnection();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::DeleteConnection *ui;
    ConnectionService connectionService;
};

#endif // DELETECONNECTION_H
