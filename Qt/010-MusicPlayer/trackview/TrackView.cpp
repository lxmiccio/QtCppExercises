#include "TrackView.h"

#include <QResizeEvent>
#include <QScrollBar>

TrackView::TrackView(QWidget* parent) : QTableView(parent)
{
  m_trackItems = QVector<TrackItem*>();

  m_model = new QStandardItemModel();
  setModel(m_model);

  QObject::connect(this, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClicked(const QModelIndex&)));

  verticalScrollBar()->setStyleSheet(QString("QScrollBar:vertical {"
                                                     "background: %1;"
                                                     "border: 0;"
                                                     "margin: 0 0 0 0;"
                                                     "width: 10px;"
                                                   "}"
                                                   "QScrollBar::handle:vertical {"
                                                     "margin: 2px 2px 2px 0px;"
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
                                                   "}")
                                           .arg(QColor(255, 255, 255, 255).name()));
}

TrackView::~TrackView()
{
  delete m_model;
}

void TrackView::onAlbumSelected(const Album& album)
{
  for(QVector<Track>::iterator track = album.tracks()->begin(); track != album.tracks()->end(); ++track) {
    TrackItem* trackItem = new TrackItem(track);
    m_trackItems.push_back(trackItem);

    m_model->appendRow(trackItem->items());
  }
}

void TrackView::onDoubleClicked(const QModelIndex& index)
{
  const Track* track = m_trackItems.at(index.row())->track();
  emit doubleClicked(*track);
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
