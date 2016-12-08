QT += core sql
QT -= gui
QT += sql

CONFIG += c++11

TARGET = LayeredArchitecture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    scientist.cpp \
    scientistservice.cpp \
    computer.cpp \
    computerservice.cpp \
    scientistdatabase.cpp \
    computerdatabase.cpp \
    connectiondatabase.cpp \
    connectionservice.cpp

HEADERS += \
    consoleui.h \
    scientistservice.h \
    scientist.h \
    computer.h \
    computerservice.h \
    scientistdatabase.h \
    computerdatabase.h \
    connectiondatabase.h \
    connectionservice.h
