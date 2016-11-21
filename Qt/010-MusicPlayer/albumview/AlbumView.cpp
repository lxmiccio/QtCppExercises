#include "AlbumView.h"

AlbumView::AlbumView(QWidget* parent) : BackgroundWidget(parent)
{
  BackgroundWidget::setBackgroundColor(QColor(255, 255, 255, 255));

  m_albums = QVector<const Album*>();

  m_currentRow = 0;
  m_currentColumn = 0;

  m_currentAlbumsPerRow = albumsPerRow(rect().size().width());

  m_verticalLayout = new QVBoxLayout();
  m_horizontalLayouts = QVector<QHBoxLayout*>();

  m_widgets = QVector<Cover*>();

  setAcceptDrops(true);
  setLayout(m_verticalLayout);
}

void AlbumView::clearLayout(QLayout* layout)
{
  QLayoutItem *item;

  while((item = layout->takeAt(0))) {
    if(item->layout()) {
      clearLayout(item->layout());
      delete item->layout();
    }
#if 0
    if(item->widget()) {
      delete item->widget();
    }
#endif
    delete item;
  }
}

void AlbumView::dragEnterEvent(QDragEnterEvent* event)
{
  event->accept();
}

void AlbumView::dropEvent(QDropEvent* event)
{
  QList<QUrl> urls = event->mimeData()->urls();
  QListIterator<QUrl> iterator(urls);

  while(iterator.hasNext()) {
    QFileInfo fileInfo(iterator.next().toLocalFile());

    if(Track::isSupportedSuffix(fileInfo.suffix())) {
      emit fileDropped(fileInfo);
    }
  }
}

void AlbumView::onScrollAreaPainted(QResizeEvent* event)
{
  if(m_currentAlbumsPerRow != albumsPerRow(event->size().width())) {
    m_currentAlbumsPerRow = albumsPerRow(event->size().width());

    foreach(QHBoxLayout* layout, m_horizontalLayouts) {
      clearLayout(layout);
    }

    m_horizontalLayouts.clear();

    m_currentColumn = 0;
    m_currentRow = 0;

    foreach(Cover* cover, m_widgets) {
      cover->hide();

      if(m_currentColumn == 0) {
        QHBoxLayout* layout = new QHBoxLayout();
        m_horizontalLayouts.push_back(layout);

        m_verticalLayout->addLayout(layout);
      }

      m_horizontalLayouts.at(m_currentRow)->addWidget(cover);
      m_currentColumn++;

      if(m_currentColumn == m_currentAlbumsPerRow) {
        m_currentColumn = 0;
        m_currentRow++;
      }

      cover->show();
    }
  }
}
#include <QDebug>
void AlbumView::onTrackAdded(const Track& track)
{
  qDebug()<<track.getAlbum();
  if(m_albums.indexOf(track.getAlbum()) == -1) {
    m_albums.push_back(track.getAlbum());

    Cover* cover = new Cover(track.getAlbum());
    m_widgets.push_back(cover);

    if(m_currentColumn == 0) {
      QHBoxLayout* layout = new QHBoxLayout();
      m_horizontalLayouts.push_back(layout);

      m_verticalLayout->addLayout(layout);
    }

    m_horizontalLayouts.at(m_currentRow)->addWidget(cover);
    m_currentColumn++;

    if(m_currentColumn == m_currentAlbumsPerRow) {
      m_currentColumn = 0;
      m_currentRow++;
    }
  }
}

quint8 AlbumView::albumsPerRow(quint16 width)
{
  return (width-12) / 206;
}
