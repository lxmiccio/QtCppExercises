#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T12:08:17
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 010-MusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    track.cpp \
    musicplayer.cpp \
    playlist.cpp \
    stackedwidget.cpp \
    saveplaylistwindow.cpp \
    loadplaylistwindow.cpp

HEADERS  += mainwindow.h \
    track.h \
    musicplayer.h \
    playlist.h \
    stackedwidget.h \
    saveplaylistwindow.h \
    loadplaylistwindow.h

FORMS    +=
