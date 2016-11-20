#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QScrollArea>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#include <QResizeEvent>
#include <QFileInfo>
#include <QDropEvent>
#include <QUrl>
 #include <QDebug>
#include <QThread>

#include "engine/album.h"
#include "gui/cover.h"
#include "gui/backgroundwidget.h"
#include "scrollarea.h"
#include "worker.h"

class AlbumView : public BackgroundWidget
{
  Q_OBJECT
  QThread workerThread;

public:
  AlbumView(QWidget* parent = 0);

  void dragEnterEvent(QDragEnterEvent* event);
  void dropEvent(QDropEvent* event);

  void clearLayout(QLayout *layout) {
      QLayoutItem *item;
      while((item = layout->takeAt(0))) {
          if (item->layout()) {
              clearLayout(item->layout());
              delete item->layout();
          }
          if (item->widget()) {
              //delete item->widget();
          }
          delete item;
      }
  }

public slots:
  void onTrackAdded(const Track* track);
  void onAlbumAdded(const Album* album);
  void onScrollAreaPainted(QResizeEvent* event);
  void handleResults(QVector<Cover*>&) {
    qDebug()<<"thread finish";
  }



signals:
  void fileDropped(const QFileInfo& fileInfo);
  void repaint(QVector<const Album*>&);

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
