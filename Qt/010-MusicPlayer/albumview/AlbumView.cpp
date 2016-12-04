#include "AlbumView.h"

#include <QApplication>
#include <QResizeEvent>
#include <QtConcurrent/QtConcurrent>

AlbumView::AlbumView(QWidget* parent) : QWidget(parent)
{
    m_watcher = new QFutureWatcher<Cover*>(this);
    connect(m_watcher, SIGNAL(resultReadyAt(int)), SLOT(showImage(int)));
    connect(m_watcher, SIGNAL(finished()), SLOT(finished()));

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
    /*
    foreach(Cover* i_cover, m_covers)
        delete i_cover;

    m_covers.clear();

    foreach(QHBoxLayout* i_layout, m_layouts)
        delete i_layout;

    m_layouts.clear();

    delete m_layout;
    */
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
        if(i_item->widget()) {
            delete i_item->widget();
        }
        delete i_item;
    }
}

Cover* scale(const Album imageFileName)
{
    //Cover* c = new Cover(&imageFileName);
    //QImage image(imageFileName);
    //return c;
}

void AlbumView::onScrollAreaResized(QResizeEvent* event)
{
    if (m_watcher->isRunning()) {
            m_watcher->cancel();
            m_watcher->waitForFinished();
        }

    /*QList<const Album*>aa =QList<const Album*>::fromVector(m_albums);

        QVector<const Album>bb = QVector<const Album>();
        Album a = Album();
        bb.push_back(a);
*/

    //m_watcher->setFuture(QtConcurrent::mapped(bb.begin(), bb.end(), scale));


    quint8 currentAlbumsPerRow = albumsPerRow(event->size().width());

    if(m_albumsPerRow != currentAlbumsPerRow)
    {
        m_albumsPerRow = currentAlbumsPerRow;

        foreach(QHBoxLayout* i_layout, m_layouts)
            clearLayout(i_layout);

        m_layouts.clear();

        m_currentColumn = 0;
        m_currentRow = 0;


        m_covers.clear();
        foreach(const Album* i_album, m_albums)
        {
            Cover* cover = new Cover(i_album);
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

            //QApplication::processEvents();
        }
#if 0
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


            //QApplication::processEvents();
        }
#endif
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
