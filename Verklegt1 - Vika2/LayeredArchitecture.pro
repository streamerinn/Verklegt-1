QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = LayeredArchitecture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    database.cpp \
    scientist.cpp \
    scientistservice.cpp \
    computer.cpp \
    computerservice.cpp

HEADERS += \
    consoleui.h \
    database.h \
    scientistservice.h \
    scientist.h \
    computer.h \
    computerservice.h
