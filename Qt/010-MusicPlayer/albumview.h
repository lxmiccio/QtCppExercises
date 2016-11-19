#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#include <QResizeEvent>

#include <QDropEvent>
#include <QUrl>

#include "engine/album.h"
#include "gui/cover.h"
#include "gui/backgroundwidget.h"

class AlbumView : public BackgroundWidget
{
public:
  AlbumView(QWidget* parent = 0);

  void addCover(Album* album);
  void resizeEvent(QResizeEvent *event);

protected:
  void dropEvent(QDropEvent* event);
  void dragEnterEvent(QDragEnterEvent* event);

private:
  QVector<Cover*> covers;

  QGridLayout* mainLayout;

  quint8 currRow;
  quint8 currCol;
};

#endif // ALBUMVIEW_H
