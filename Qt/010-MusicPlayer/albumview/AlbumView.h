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
    AlbumView(QWidget* parent = 0);

    void clearLayout(QLayout* layout);

  public slots:
    void onCoverClicked(const Album& album);
    void onScrollAreaPainted(QResizeEvent* event);
    void onTrackAdded(const Track& track);

  signals:
    void coverClicked(const Album& album);

  private:
    QVector<const Album*> m_albums;

    quint8 m_currentColumn;
    quint8 m_currentRow;

    quint8 m_currentAlbumsPerRow;
    quint8 albumsPerRow(quint16 width);

    QVBoxLayout* m_verticalLayout;
    QVector<QHBoxLayout*> m_horizontalLayouts;

    QVector<Cover*> m_widgets;
};

#endif // ALBUMVIEW_H
