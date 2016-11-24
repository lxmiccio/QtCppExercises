#include "AlbumView.h"

#include <QResizeEvent>

AlbumView::AlbumView(QWidget* parent) : BackgroundWidget(parent)
{
    m_albums = QVector<const Album*>();

    m_currentColumn = 0;
    m_currentRow = 0;

    m_albumsPerRow = albumsPerRow(rect().size().width());

    m_widgets = QVector<Cover*>();
    m_layouts = QVector<QHBoxLayout*>();
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
}

AlbumView::~AlbumView()
{
    foreach(Cover* widget, m_widgets)
        delete widget;

    foreach(QHBoxLayout* layout, m_layouts)
        delete layout;

    delete m_layout;
}

void AlbumView::clearLayout(QLayout* layout)
{
    QLayoutItem* item;

    while((item = layout->takeAt(0)))
    {
        if(item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }

        delete item;
    }
}

void AlbumView::onScrollAreaPainted(QResizeEvent* event)
{
    quint8 currentAlbumsPerRow = albumsPerRow(event->size().width());

    if(m_albumsPerRow != currentAlbumsPerRow)
    {
        m_albumsPerRow = currentAlbumsPerRow;

        foreach(QHBoxLayout* layout, m_layouts) {
            clearLayout(layout);
        }

        m_layouts.clear();

        m_currentColumn = 0;
        m_currentRow = 0;

        foreach(Cover* cover, m_widgets)
        {
            cover->hide();

            if(m_currentColumn == 0) {
                QHBoxLayout* layout = new QHBoxLayout();
                m_layouts.push_back(layout);
                m_layout->addLayout(layout);
            }

            m_layouts.at(m_currentRow)->addWidget(cover);

            if(++m_currentColumn == m_albumsPerRow) {
                m_currentColumn = 0;
                m_currentRow++;
            }

            cover->show();
        }
    }
}

void AlbumView::onTrackAdded(const Track& track)
{
    const Album* album = track.album();

    if(m_albums.indexOf(album) == -1)
    {
        m_albums.push_back(album);

        Cover* cover = new Cover(album);
        m_widgets.push_back(cover);
        QObject::connect(cover, SIGNAL(coverClicked(const Album&)), this, SLOT(onCoverClicked(const Album&)));

        if(m_currentColumn == 0) {
            QHBoxLayout* layout = new QHBoxLayout();
            m_layouts.push_back(layout);
            m_layout->addLayout(layout);
        }

        m_layouts.at(m_currentRow)->addWidget(cover);

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
