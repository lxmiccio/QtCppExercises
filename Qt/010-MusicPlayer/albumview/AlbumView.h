#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QFutureWatcher>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Album.h"
#include "BackgroundWidget.h"
#include "Cover.h"

#include <QDebug>

class AlbumView : public QWidget
{
    Q_OBJECT

    public:
        explicit AlbumView(QWidget* parent = 0);
        ~AlbumView();

        void clearLayout(QLayout* layout);

    public slots:
        void onScrollAreaResized(QResizeEvent* event);
        void onTrackAdded(const Track& track);

    signals:
        void coverClicked(const Album& album);

    private slots:
        void onCoverClicked(const Album& album);

        void showImage(int at)
        {
            //qDebug()<<"ready " << m_covers.at(at)->album().title();

        }

        void finished()
        {
            qDebug()<<"finish all";
        }

    private:
        QFutureWatcher<Cover*>* m_watcher;
        quint8 albumsPerRow(quint16 width);

        QVector<const Album*> m_albums;

        QVector<Cover*> m_covers;
        QVector<QHBoxLayout*> m_layouts;
        QVBoxLayout* m_layout;

        quint8 m_currentColumn;
        quint8 m_currentRow;
        quint8 m_albumsPerRow;
};

#endif // ALBUMVIEW_H
