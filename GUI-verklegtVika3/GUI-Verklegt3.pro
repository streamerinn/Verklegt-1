#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T09:42:12
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI-Verklegt3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    computerdatabase.cpp \
    computerservice.cpp \
    connectiondatabase.cpp \
    connectionservice.cpp \
    scientist.cpp \
    scientistdatabase.cpp \
    scientistservice.cpp \
    addscientistdialog.cpp \
    scientisttabledialog.cpp \
    connectiondialog.cpp \
    computertabledialog.cpp \
    aboutdialog.cpp \
    addanewcomputerdialog.cpp \
    editdeletscientist.cpp \
    addconnection.cpp \
    deleteconnection.cpp

HEADERS  += mainwindow.h \
    computer.h \
    computerdatabase.h \
    computerservice.h \
    connectiondatabase.h \
    connectionservice.h \
    scientist.h \
    scientistdatabase.h \
    scientistservice.h \
    addscientistdialog.h \
    scientisttabledialog.h \
    connectiondialog.h \
    computertabledialog.h \
    aboutdialog.h \
    addanewcomputerdialog.h \
    editdeletscientist.h \
    addconnection.h \
    deleteconnection.h



FORMS    += mainwindow.ui \
    addscientistdialog.ui \
    scientisttabledialog.ui \
    connectiondialog.ui \
    computertabledialog.ui \
    aboutdialog.ui \
    addanewcomputerdialog.ui \
    editdeletscientist.ui \
    addconnection.ui \
    deleteconnection.ui


RESOURCES += aukaefni.qrc



