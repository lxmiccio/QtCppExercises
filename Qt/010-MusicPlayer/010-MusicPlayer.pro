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
    musicplayer.cpp \
    playlist.cpp \
    saveplaylistwindow.cpp \
    loadplaylistwindow.cpp \
    gui/AudioControls.cpp \
    albumview/AlbumView.cpp \
    albumview/Cover.cpp \
    data/Album.cpp \
    data/Artist.cpp \
    data/Musiclibrary.cpp \
    data/Track.cpp \
    trackview/TrackDelegate.cpp \
    trackview/TrackItem.cpp \
    trackview/TrackView.cpp \
    utils/ImageUtils.cpp \
    utils/TagUtils.cpp \
    widgets/BackgroundWidget.cpp \
    widgets/ElidedLabel.cpp \
    widgets/ImageButton.cpp \
    widgets/SeekSlider.cpp \
    widgets/ScrollArea.cpp \
    widgets/StackedWidget.cpp \
    widgets/ClickableLabel.cpp \
    trackview/AlbumWidget.cpp \
    trackview/TrackList.cpp \
    trackview/TrackModel.cpp

HEADERS  += mainwindow.h \
    musicplayer.h \
    playlist.h \
    saveplaylistwindow.h \
    loadplaylistwindow.h \
    gui/AudioControls.h \
    albumview/AlbumView.h \
    albumview/Cover.h \
    data/Album.h \
    data/Artist.h \
    data/Musiclibrary.h\
    data/Track.h \
    trackview/TrackDelegate.h \
    trackview/TrackItem.h \
    trackview/TrackView.h \
    utils/ImageUtils.h \
    utils/TagUtils.h \
    widgets/BackgroundWidget.h \
    widgets/ElidedLabel.h \
    widgets/ImageButton.h \
    widgets/SeekSlider.h \
    widgets/ScrollArea.h \
    widgets/StackedWidget.h \
    widgets/ClickableLabel.h \
    trackview/AlbumWidget.h \
    trackview/TrackList.h \
    trackview/TrackModel.h

FORMS    +=

INCLUDEPATH += $$PWD/albumview
INCLUDEPATH += $$PWD/data
INCLUDEPATH += $$PWD/trackview
INCLUDEPATH += $$PWD/utils
INCLUDEPATH += $$PWD/widgets


INCLUDEPATH += $$PWD/tag
INCLUDEPATH += $$PWD/table
INCLUDEPATH += $$PWD/gui
INCLUDEPATH += $$PWD/engine

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

RESOURCES += \
    resources.qrc

