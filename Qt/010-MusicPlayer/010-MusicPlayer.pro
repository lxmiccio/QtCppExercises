#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T12:08:17
#
#-------------------------------------------------

QT       += core gui multimedia svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 010-MusicPlayer
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    engine/track.cpp \
    musicplayer.cpp \
    playlist.cpp \
    stackedwidget.cpp \
    saveplaylistwindow.cpp \
    loadplaylistwindow.cpp \
    gui/imageloader.cpp \
    gui/imagebutton.cpp \
    audiocontrols.cpp \
    gui/seekslider.cpp \
    gui/backgroundwidget.cpp \
    tag/tagmanager.cpp \
    engine/artist.cpp \
    engine/album.cpp \
    gui/imageutils.cpp \
    tag/tagutils.cpp

HEADERS  += mainwindow.h \
    engine/track.h \
    musicplayer.h \
    playlist.h \
    stackedwidget.h \
    saveplaylistwindow.h \
    loadplaylistwindow.h \
    gui/imageloader.h \
    gui/imagebutton.h \
    audiocontrols.h \
    gui/seekslider.h \
    gui/backgroundwidget.h \
    tag/tagmanager.h \
    engine/artist.h \
    engine/album.h \
    gui/imageutils.h \
    tag/tagutils.h

FORMS    +=

INCLUDEPATH += $$PWD/../taglib-1.10
INCLUDEPATH += $$PWD/../taglib-1.10/taglib
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ape
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/asf
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/flac
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/it
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mod
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mp4
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mpc
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mpeg
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mpeg/id3v2
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/mpeg/id3v2/frames
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ogg
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ogg/flac
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ogg/opus
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ogg/speex
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/ogg/vorbis
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/riff
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/riff/aiff
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/s3m
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/toolkit
INCLUDEPATH += $$PWD/../taglib-1.11.1
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/trueaudio
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/wavpack
INCLUDEPATH += $$PWD/../taglib-1.10/taglib/xm

INCLUDEPATH += $$PWD/../taglib-1.10/build/taglib
DEPENDPATH += $$PWD/../taglib-1.10/build/taglib

LIBS += -L$$PWD/taglib -ltaglib

