QT += core
QT -= gui

CONFIG += c++11

TARGET = QtConsole
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    counter.cpp

HEADERS += \
    counter.h
