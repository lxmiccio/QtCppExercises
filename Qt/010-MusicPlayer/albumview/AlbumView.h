#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QFileInfo>
#include <QMimeData>
#include <QResizeEvent>

#include "Album.h"
#include "BackgroundWidget.h"
#include "Cover.h"

class AlbumView : public BackgroundWidget
{
  Q_OBJECT

  public:
    AlbumView(QWidget* parent = 0);

    void clearLayout(QLayout* layout);

    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

  public slots:
    void onScrollAreaPainted(QResizeEvent* event);
    void onTrackAdded(const Track& track);

  signals:
    void fileDropped(const QFileInfo& fileInfo);

  private:
    QVector<const Album*> m_albums;

    quint8 m_currentRow;
    quint8 m_currentColumn;

    quint8 m_currentAlbumsPerRow;
    quint8 albumsPerRow(quint16 width);

    QVBoxLayout* m_verticalLayout;
    QVector<QHBoxLayout*> m_horizontalLayouts;

    QVector<Cover*> m_widgets;
};

#endif // ALBUMVIEW_H
