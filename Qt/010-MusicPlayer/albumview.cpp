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

  this->covers = QVector<Cover*>();

  this->mainLayout = new QGridLayout();
  this->mainLayout->setMargin(0);
  this->mainLayout->setSpacing(0);

  this->setLayout(this->mainLayout);

  this->currCol = 0;

  this->currRow = 0;

  this->setAcceptDrops(true);
}

void AlbumView::addCover(Album* album)
{
  Cover* cover = new Cover(album);
  this->covers.push_back(cover);

  if(currCol!= 0 && currCol % 4 == 0) {
    currRow++;
    currCol = 0;
  }

  this->mainLayout->addWidget(cover, currRow, currCol, 1, 1, Qt::AlignLeft);

  this->currCol++;
}

void AlbumView::resizeEvent(QResizeEvent *event)
{
}

void AlbumView::dropEvent(QDropEvent* event)
{
  MusicLibrary* ml = new MusicLibrary();
  qDebug()<<"drymytears";
  QList<QUrl> urls = event->mimeData()->urls();
  foreach(QUrl u, urls) {
    qDebug()<<"yougotaperfectone"<<u.toLocalFile();

    QFileInfo fileInfo {u.toLocalFile()};


    QVariantMap tags = TagManager::readTags(fileInfo).toMap();
    Track* t = ml->addTrack(tags);
    if(t) {
      qDebug()<<"letsusethemuptilleverylittlefieceisgone";
      //TrackItem* ti = new TrackItem(*t);
      //this->model->appendRow(ti->getItems());

      ml->debug();

      this->addCover(t->getAlbum());
    }
  }
}

void AlbumView::dragEnterEvent(QDragEnterEvent* event)
{
  event->accept();
}
