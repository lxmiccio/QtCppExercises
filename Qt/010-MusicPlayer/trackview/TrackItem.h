#ifndef TRACKITEM_H
#define TRACKITEM_H

#include <QList>
#include <QStandardItem>

#include "track.h"

class TrackItem
{
public:
  explicit TrackItem(const Track* track);

  QList<QStandardItem*> items() const;

  const Track* track() const;
  void setTrack(const Track* track) {m_track = track;}

private:
  QList<QStandardItem*> m_items;

  const Track* m_track;
};

#endif // TRACKITEM_H
