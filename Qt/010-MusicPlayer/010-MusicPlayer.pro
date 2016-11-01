#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T12:08:17
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 010-MusicPlayer
TEMPLATE = app


SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/track.cpp \
    src/musicplayer.cpp \
    src/playlist.cpp \
    src/stackedwidget.cpp \
    src/saveplaylistwindow.cpp \
    src/loadplaylistwindow.cpp

HEADERS  += inc/mainwindow.h \
    inc/track.h \
    inc/musicplayer.h \
    inc/playlist.h \
    inc/stackedwidget.h \
    inc/saveplaylistwindow.h \
    inc/loadplaylistwindow.h

FORMS    +=
