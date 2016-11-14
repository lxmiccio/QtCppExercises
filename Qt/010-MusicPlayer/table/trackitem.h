#ifndef TRACKITEM_H
#define TRACKITEM_H

#include <QList>
#include <QStandardItem>

#include "../engine/track.h"

class TrackItem
{
public:
  TrackItem(Track* track);

  QList<QStandardItem *> getItems();

private:
  QList<QStandardItem*> items;

  Track* track;
};

#endif // TRACKITEM_H
