#include "TrackView.h"

#include <QScrollBar>

TrackView::TrackView(QWidget* parent) : QTableView(parent)
{
  this->verticalScrollBar()->setStyleSheet(QString("QScrollBar:vertical {"
                                                     "background: %1;"
                                                     "border: 0;"
                                                     "margin: 0 0 0 0;"
                                                     "width: 10px;"
                                                   "}"
                                                   "QScrollBar::handle:vertical {"
                                                     "margin: 2px 2px 2px 0px;"
                                                     "border-image: url(images/scrollbar.jpg);"
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
                                                   "}")
                                           .arg(QColor(255, 255, 255, 255).name()));
}

void TrackView::resizeEvent(QResizeEvent* event)
{
  int width = event->size().width() - TrackView::TRACK_WIDTH - TrackView::DURATION_WIDTH;

  this->setColumnWidth(TrackView::TRACK, TrackView::TRACK_WIDTH);
  this->setColumnWidth(TrackView::TITLE, TrackView::TITLE_WIDTH_PERCENTAGE * width);
  this->setColumnWidth(TrackView::ALBUM, TrackView::ALBUM_WIDTH_PERCENTAGE * width);
  this->setColumnWidth(TrackView::ARTIST, TrackView::ARTIST_WIDTH_PERCENTAGE * width);
  this->setColumnWidth(TrackView::DURATION, TrackView::DURATION_WIDTH);

  QTableView::resizeEvent(event);
}
