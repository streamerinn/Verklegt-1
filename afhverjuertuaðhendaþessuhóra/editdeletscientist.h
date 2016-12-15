#ifndef EDITDELETSCIENTIST_H
#define EDITDELETSCIENTIST_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>
#include <QTableWidget>

//#include "scientist.h"
#include "scientistservice.h"
#include "addscientistdialog.h"

namespace Ui {
class EditDeletScientist;
}

class EditDeletScientist : public QDialog
{
    Q_OBJECT

public:
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    explicit EditDeletScientist(QWidget *parent = 0);
    ~EditDeletScientist();

private slots:
    void on_ScientistSearch_textChanged();

    void on_Names_cellClicked(int row, int column);

    void on_pushButton_clicked();

    void on_DeleteScientist_clicked();

private:
    Ui::EditDeletScientist *ui;
    ScientistService scientistService1;
};

#endif // EDITDELETSCIENTIST_H
------------------------------------------------------------
#include "scientisttabledialog.h"
#include "ui_scientisttabledialog.h"

ScientistTableDialog::ScientistTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistTableDialog)
{
    ui->setupUi(this);
    displayAllScientists();
    on_ScientistSearch_textChanged();
}

ScientistTableDialog::~ScientistTableDialog()
{
    delete ui;
}

void ScientistTableDialog::displayAllScientists()
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

void ScientistTableDialog::displayScientists(vector<Scientist> scientists)
{
    ui->ScientistTable->clearContents();

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        ui->ScientistTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(scientists[i].getName())));
        ui->ScientistTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientists[i].getGender())));
        ui->ScientistTable->setItem(i, 2, new QTableWidgetItem(QString::number(scientists[i].getDateOfBirth())));
        ui->ScientistTable->setItem(i, 3, new QTableWidgetItem(QString::number(scientists[i].getDateOfDeath())));
    }

}

void ScientistTableDialog::on_AddANewScientist_clicked()
{
    AddScientistDialog addScientistDialog(this);
    int addScientistReturnValue = addScientistDialog.exec();
}

void ScientistTableDialog::on_ScientistSearch_textChanged()
{
    string input = ui->ScientistSearch->text().toStdString();

    vector<Scientist> scientists = scientistService.searchName(input);
    displayScientists(scientists);
}



void ScientistTableDialog::on_editDelete_clicked()
{
    EditDeletScientist editDeletScientist(this);
    editDeletScientist.exec();
}
----------------------------------------------
#ifndef EDITDELETSCIENTIST_H
#define EDITDELETSCIENTIST_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>
#include <QTableWidget>

#include "scientist.h"
#include "scientistservice.h"
#include "addscientistdialog.h"

namespace Ui {
class EditDeletScientist;
}

class EditDeletScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeletScientist(QWidget *parent = 0);
    ~EditDeletScientist();

private slots:
    void on_ScientistSearch_textChanged();
    void on_Names_cellClicked(int row, int column);
    void on_editScientist_clicked();
    void on_DeleteScientist_clicked();

private:
    Ui::EditDeletScientist *ui;
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    ScientistService scientistService1;
};

#endif // EDITDELETSCIENTIST
------------------------------------------------
#ifndef UI_EDITDELETSCIENTIST_H
#define UI_EDITDELETSCIENTIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDeletScientist
{
public:
    QGridLayout *gridLayout;
    QLineEdit *txtBorn;
    QPushButton *DeleteScientist;
    QLineEdit *txtID;
    QLabel *label_2;
    QLineEdit *txtGender;
    QLabel *label_4;
    QLineEdit *txtDied;
    QLineEdit *txtName;
    QLabel *label_3;
    QPushButton *editScientist;
    QTableWidget *Names;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *ScientistSearch;

    void setupUi(QDialog *EditDeletScientist)
    {
        if (EditDeletScientist->objectName().isEmpty())
            EditDeletScientist->setObjectName(QStringLiteral("EditDeletScientist"));
        EditDeletScientist->resize(441, 352);
        gridLayout = new QGridLayout(EditDeletScientist);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        txtBorn = new QLineEdit(EditDeletScientist);
        txtBorn->setObjectName(QStringLiteral("txtBorn"));

        gridLayout->addWidget(txtBorn, 4, 1, 1, 1);

        DeleteScientist = new QPushButton(EditDeletScientist);
        DeleteScientist->setObjectName(QStringLiteral("DeleteScientist"));

        gridLayout->addWidget(DeleteScientist, 7, 1, 1, 1);

        txtID = new QLineEdit(EditDeletScientist);
        txtID->setObjectName(QStringLiteral("txtID"));

        gridLayout->addWidget(txtID, 1, 1, 1, 1);

        label_2 = new QLabel(EditDeletScientist);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        txtGender = new QLineEdit(EditDeletScientist);
        txtGender->setObjectName(QStringLiteral("txtGender"));

        gridLayout->addWidget(txtGender, 3, 1, 1, 1);

        label_4 = new QLabel(EditDeletScientist);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        txtDied = new QLineEdit(EditDeletScientist);
        txtDied->setObjectName(QStringLiteral("txtDied"));

        gridLayout->addWidget(txtDied, 5, 1, 1, 1);

        txtName = new QLineEdit(EditDeletScientist);
        txtName->setObjectName(QStringLiteral("txtName"));

        gridLayout->addWidget(txtName, 2, 1, 1, 1);

        label_3 = new QLabel(EditDeletScientist);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        editScientist = new QPushButton(EditDeletScientist);
        editScientist->setObjectName(QStringLiteral("editScientist"));

        gridLayout->addWidget(editScientist, 6, 1, 1, 1);

        Names = new QTableWidget(EditDeletScientist);
        if (Names->columnCount() < 1)
            Names->setColumnCount(1);
        Names->setObjectName(QStringLiteral("Names"));
        Names->setColumnCount(1);

        gridLayout->addWidget(Names, 2, 2, 6, 1);

        label_5 = new QLabel(EditDeletScientist);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label = new QLabel(EditDeletScientist);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        ScientistSearch = new QLineEdit(EditDeletScientist);
        ScientistSearch->setObjectName(QStringLiteral("ScientistSearch"));
        ScientistSearch->setCursorPosition(0);

        gridLayout->addWidget(ScientistSearch, 1, 2, 1, 1);


        retranslateUi(EditDeletScientist);

        QMetaObject::connectSlotsByName(EditDeletScientist);
    } // setupUi

    void retranslateUi(QDialog *EditDeletScientist)
    {
        EditDeletScientist->setWindowTitle(QApplication::translate("EditDeletScientist", "Dialog", 0));
        DeleteScientist->setText(QApplication::translate("EditDeletScientist", "Delete scientist", 0));
        label_2->setText(QApplication::translate("EditDeletScientist", "Name", 0));
        label_4->setText(QApplication::translate("EditDeletScientist", "Born", 0));
        label_3->setText(QApplication::translate("EditDeletScientist", "Gender", 0));
        editScientist->setText(QApplication::translate("EditDeletScientist", "Edit Scientist", 0));
        label_5->setText(QApplication::translate("EditDeletScientist", "Died", 0));
        label->setText(QApplication::translate("EditDeletScientist", "ID", 0));
        ScientistSearch->setText(QString());
        ScientistSearch->setPlaceholderText(QApplication::translate("EditDeletScientist", "Serch Scientist", 0));
    } // retranslateUi

};

namespace Ui {
    class EditDeletScientist: public Ui_EditDeletScientist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDELETSCIENTIST_H
