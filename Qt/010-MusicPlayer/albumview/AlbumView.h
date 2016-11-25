#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Album.h"
#include "BackgroundWidget.h"
#include "Cover.h"

class AlbumView : public BackgroundWidget
{
    Q_OBJECT

    public:
        explicit AlbumView(QWidget* parent = 0);
        ~AlbumView();

        void clearLayout(QLayout* layout);

    public slots:
        void onScrollAreaPainted(QResizeEvent* event);
        void onTrackAdded(const Track& track);

    signals:
        void coverClicked(const Album& album);

    private slots:
        void onCoverClicked(const Album& album);

    private:
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
