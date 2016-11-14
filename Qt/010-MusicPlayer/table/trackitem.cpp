#include "trackitem.h"

TrackItem::TrackItem(Track *track)
{
  this->track = track;

  QStandardItem* id = new QStandardItem(QString("%1").arg(this->track->getTrack()));
  QStandardItem* title = new QStandardItem(this->track->getTitle());
  QStandardItem* album = new QStandardItem(this->track->getAlbum()->getTitle());
  QStandardItem* artist = new QStandardItem(this->track->getArtist()->getName());
  QStandardItem* durarion = new QStandardItem(this->track->getDurationInMinutes());

  this->items = QList<QStandardItem*>();

  this->items.append(id);
  this->items.append(title);
  this->items.append(album);
  this->items.append(artist);
  this->items.append(durarion);
}

QList<QStandardItem*> TrackItem::getItems()
{
  return this->items;
}
