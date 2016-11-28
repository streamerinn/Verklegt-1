QT += core
QT -= gui

CONFIG += c++11

TARGET = LayeredArchitecture
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    performerservice.cpp \
    performer.cpp \
    dataaccess.cpp \
    database.cpp

HEADERS += \
    consoleui.h \
    performerservice.h \
    performer.h \
    dataaccess.h \
    database.h
