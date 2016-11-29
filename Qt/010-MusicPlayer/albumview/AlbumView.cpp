#include "AlbumView.h"

#include <QResizeEvent>

AlbumView::AlbumView(QWidget* parent) : BackgroundWidget(parent)
{
    m_covers = QVector<Cover*>();
    m_layouts = QVector<QHBoxLayout*>();
    m_layout = new QVBoxLayout();
    setLayout(m_layout);

    m_currentColumn = 0;
    m_currentRow = 0;
    m_albumsPerRow = albumsPerRow(rect().size().width());
}

AlbumView::~AlbumView()
{
    foreach(Cover* i_cover, m_covers)
        delete i_cover;

    m_covers.clear();

    foreach(QHBoxLayout* i_layout, m_layouts)
        delete i_layout;

    m_layouts.clear();

    delete m_layout;
}

void AlbumView::clearLayout(QLayout* layout)
{
    QLayoutItem* i_item;

    while((i_item = layout->takeAt(0)) != NULL)
    {
        if(i_item->layout())
        {
            clearLayout(i_item->layout());
            delete i_item->layout();
        }

        delete i_item;
    }
}

void AlbumView::onScrollAreaResized(QResizeEvent* event)
{
    quint8 currentAlbumsPerRow = albumsPerRow(event->size().width());

    if(m_albumsPerRow != currentAlbumsPerRow)
    {
        m_albumsPerRow = currentAlbumsPerRow;

        foreach(QHBoxLayout* i_layout, m_layouts)
            clearLayout(i_layout);

        m_layouts.clear();

        m_currentColumn = 0;
        m_currentRow = 0;

        foreach(Cover* i_cover, m_covers)
        {
            i_cover->hide();

            if(m_currentColumn == 0)
            {
                QHBoxLayout* layout = new QHBoxLayout();
                m_layouts.push_back(layout);
                m_layout->addLayout(layout);
            }

            m_layouts.at(m_currentRow)->addWidget(i_cover);

            if(++m_currentColumn == m_albumsPerRow)
            {
                m_currentColumn = 0;
                m_currentRow++;
            }

            i_cover->show();
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
        m_covers.push_back(cover);

        QObject::connect(cover, SIGNAL(coverClicked(const Album&)), this, SLOT(onCoverClicked(const Album&)));

        if(m_currentColumn == 0)
        {
            QHBoxLayout* layout = new QHBoxLayout();
            m_layouts.push_back(layout);
            m_layout->addLayout(layout);
        }

        m_layouts.at(m_currentRow)->addWidget(cover);

        if(++m_currentColumn == m_albumsPerRow)
        {
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
