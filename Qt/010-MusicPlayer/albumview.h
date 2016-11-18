#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>
#include <QResizeEvent>
#include <QVector>

#include "engine/album.h"
#include "gui/cover.h"

class AlbumView : public QWidget
{
public:
  AlbumView(QWidget* parent = 0);

  void addCover(Album* album);

  void resizeEvent(QResizeEvent * event);
private:
  QVector<Cover*> covers;

  QGridLayout* mainLayout;

  quint8 currRow;
  quint8 currCol;
};

#endif // ALBUMVIEW_H
