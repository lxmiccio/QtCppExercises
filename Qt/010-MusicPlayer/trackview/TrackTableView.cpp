#include "TrackTableView.h"

#include <QCommonStyle>
#include <QResizeEvent>
#include <QScrollBar>

TrackTableView::TrackTableView(QWidget* parent) : QTableView(parent)
{
    setStyleSheet(QString("QTableView {"
                          "background: transparent;"
                          "border: 0px;"
                          "}"
                          "QTableView > QWidget > QWidget {"
                          "background: transparent;"
                          "}"));

    /* Workaround */
    verticalScrollBar()->setStyle(new QCommonStyle);

    verticalScrollBar()->setStyleSheet(QString("QScrollBar:vertical {"
                                               "background: transparent;"
                                               "border: 0;"
                                               "margin: 0 0 0 0;"
                                               "width: 10px;"
                                               "}"
                                               "QScrollBar::handle:vertical {"
                                               "margin: 2px 2px 2px 2px;"
                                               "border-image: url(:/images/scroll-bar.jpg);"
                                               "border-radius: 2px;"
                                               "}"
                                               "QScrollBar::add-line:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                               "}"
                                               "QScrollBar::sub-line:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                               "}"
                                               "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                               "width: 0;"
                                               "}"));
}

void TrackTableView::resizeEvent(QResizeEvent* event)
{
    int width = event->size().width() - TrackTableView::TRACK_WIDTH - TrackTableView::DURATION_WIDTH;

#ifndef SHOW_FULL_TRACK
    this->setColumnWidth(TrackTableView::TRACK, TrackTableView::TRACK_WIDTH);
    this->setColumnWidth(TrackTableView::TITLE, width);
    this->setColumnWidth(TrackTableView::DURATION, TrackTableView::DURATION_WIDTH);
#else
    this->setColumnWidth(TrackTableView::TRACK, TrackTableView::TRACK_WIDTH);
    this->setColumnWidth(TrackTableView::TITLE, TrackTableView::TITLE_WIDTH_PERCENTAGE * width);
    this->setColumnWidth(TrackTableView::ALBUM, TrackTableView::ALBUM_WIDTH_PERCENTAGE * width);
    this->setColumnWidth(TrackTableView::ARTIST, TrackTableView::ARTIST_WIDTH_PERCENTAGE * width);
    this->setColumnWidth(TrackTableView::DURATION, TrackTableView::DURATION_WIDTH);
#endif

    QTableView::resizeEvent(event);
}
