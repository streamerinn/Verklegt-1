QT += core
QT -= gui

CONFIG += c++11

TARGET = LayeredArchitecture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    database.cpp \
    scientist.cpp \
    scientistservice.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    database.h \
    scientistservice.h \
    scientist.h
