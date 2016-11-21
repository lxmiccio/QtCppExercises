#include "AlbumView.h"

#include <QResizeEvent>

AlbumView::AlbumView(QWidget* parent) : BackgroundWidget(parent)
{
  BackgroundWidget::setBackgroundColor(QColor(255, 255, 255, 255));

  m_albums = QVector<const Album*>();

  m_currentColumn = 0;
  m_currentRow = 0;

  m_albumsPerRow = albumsPerRow(rect().size().width());

  m_layout = new QVBoxLayout();
  m_layouts = QVector<QHBoxLayout*>();

  m_widgets = QVector<Cover*>();

  setLayout(m_layout);
}

AlbumView::~AlbumView()
{
  foreach(Cover* widget, m_widgets) {
    delete widget;
  }

  foreach(QHBoxLayout* layout, m_layouts) {
    delete layout;
  }

  delete m_layout;
}

void AlbumView::clearLayout(QLayout* layout)
{
  QLayoutItem* item;

  while((item = layout->takeAt(0))) {
    if(item->layout()) {
      clearLayout(item->layout());
      delete item->layout();
    }
    delete item;
  }
}

void AlbumView::onScrollAreaPainted(QResizeEvent* event)
{
  if(m_albumsPerRow != albumsPerRow(event->size().width())) {
    m_albumsPerRow = albumsPerRow(event->size().width());

    foreach(QHBoxLayout* layout, m_layouts) {
      clearLayout(layout);
    }

    m_layouts.clear();

    m_currentColumn = 0;
    m_currentRow = 0;

    foreach(Cover* cover, m_widgets) {
      cover->hide();

      if(m_currentColumn == 0) {
        QHBoxLayout* layout = new QHBoxLayout();
        m_layouts.push_back(layout);

        m_layout->addLayout(layout);
      }

      m_layouts.at(m_currentRow)->addWidget(cover);
      m_currentColumn++;

      if(m_currentColumn == m_albumsPerRow) {
        m_currentColumn = 0;
        m_currentRow++;
      }

      cover->show();
    }
  }
}

void AlbumView::onTrackAdded(const Track& track)
{
  Album* album = track.getAlbum();

  if(m_albums.indexOf(album) == -1) {
    m_albums.push_back(album);

    Cover* cover = new Cover(album);
    QObject::connect(cover, SIGNAL(clicked(const Album&)), this, SLOT(onCoverClicked(const Album&)));

    m_widgets.push_back(cover);

    QHBoxLayout* layout;

    if(m_currentColumn == 0) {
      layout = new QHBoxLayout();
      m_layouts.push_back(layout);

      m_layout->addLayout(layout);
    } else {
      layout = m_layouts.at(m_currentRow);
    }

    layout->addWidget(cover);

    if(++m_currentColumn == m_albumsPerRow) {
      m_currentColumn = 0;
      m_currentRow++;
    }
  }
}

void AlbumView::onCoverClicked(const Album& album)
{
  emit coverClicked(album);
}

quint8 AlbumView::albumsPerRow(quint16 width)
{
  return (width - 12) / (Cover::COVER_WIDTH + 6);
}
