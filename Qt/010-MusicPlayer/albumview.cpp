#include "albumview.h"

#include <QMimeData>
#include <QDebug>
#include <QLabel>
#include <QFileInfo>
#include "engine/musiclibrary.h"

#include "engine/track.h"
#include "tag/tagmanager.h"

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

void AlbumView::onTrackAdded(const Track* track)
{
  m_albums.push_back(track->getAlbum());

  Cover* cover = new Cover(track->getAlbum());
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

void AlbumView::onAlbumAdded(const Album* album)
{
  m_albums.push_back(album);
}
/*
void AlbumView::onDropEvent(QDropEvent *event)
{
  MusicLibrary* ml = new MusicLibrary();
  // qDebug()<<"drymytears";
  QList<QUrl> urls = event->mimeData()->urls();
  foreach(QUrl u, urls) {
    //qDebug()<<"yougotaperfectone"<<u.toLocalFile();

    QFileInfo fileInfo {u.toLocalFile()};


    QVariantMap tags = TagManager::readTags(fileInfo).toMap();
    Track* t = ml->addTrack(tags);
    if(t) {
      qDebug()<<"letsusethemuptilleverylittlefieceisgone";
      //TrackItem* ti = new TrackItem(*t);
      //this->model->appendRow(ti->getItems());

      // ml->debug();

      //this->addCover(t->getAlbum());
    }
  }
}
*/
void AlbumView::onScrollAreaPainted(QResizeEvent* event)
{
  if(m_currentAlbumsPerRow != albumsPerRow(event->size().width())) {
    m_currentAlbumsPerRow = albumsPerRow(event->size().width());

    for(QVector<QHBoxLayout*>::iterator horizontalLayout = m_horizontalLayouts.begin(); horizontalLayout != m_horizontalLayouts.end(); ++horizontalLayout) {
     clearLayout(*horizontalLayout);
    }

    m_horizontalLayouts.clear();

    m_currentColumn = 0;
    m_currentRow = 0;

    for(QVector<const Album*>::iterator album = m_albums.begin(); album != m_albums.end(); ++album) {
      Cover* cover = new Cover(*album);
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
  }/*
  qDebug()<<event->size().width();
  qDebug()<<m_currentAlbumsPerRow;
  qDebug()<<albumsPerRow(event->size().width());*/
  // TO DO


}

quint8 AlbumView::albumsPerRow(quint16 width)
{
  width -= 12;

  return width / 206;
}
/*
void AlbumView::addCover(Album* album)
{
  Cover* cover = new Cover(album);
  this->covers.push_back(cover);

  if(currCol == 0)  {
    qDebug()<< currCol << "wecanrunonlovetillitdies";
    QHBoxLayout* hb = new QHBoxLayout();
    this->mainLayout->addLayout(hb);
    this->trackLayout.push_back(hb);
  }


  this->trackLayout.at(currRow)->addWidget(cover);


  currCol++;

  if(currCol == 10){

    currCol = 0;
    currRow++;
  }
}*/
/*
void AlbumView::resizeEvent(QResizeEvent *event)
{
  qDebug() << m_scrollArea->viewport()->size().width();
  qDebug() << event->size().width();
  qDebug() << this->albumPerRow( m_scrollArea->viewport()->size().width());
}

void AlbumView::dropEvent(QDropEvent* event)
{
  MusicLibrary* ml = new MusicLibrary();
  // qDebug()<<"drymytears";
  QList<QUrl> urls = event->mimeData()->urls();
  foreach(QUrl u, urls) {
    //qDebug()<<"yougotaperfectone"<<u.toLocalFile();

    QFileInfo fileInfo {u.toLocalFile()};


    QVariantMap tags = TagManager::readTags(fileInfo).toMap();
    Track* t = ml->addTrack(tags);
    if(t) {
      qDebug()<<"letsusethemuptilleverylittlefieceisgone";
      //TrackItem* ti = new TrackItem(*t);
      //this->model->appendRow(ti->getItems());

      // ml->debug();

      this->addCover(t->getAlbum());
    }
  }
}

void AlbumView::dragEnterEvent(QDragEnterEvent* event)
{
  event->accept();
}
*/
