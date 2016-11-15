#include "trackitem.h"

#include "trackview.h"

TrackItem::TrackItem(Track& track)
{
  this->track = &track;

  this->items = QList<QStandardItem*>();

  QStandardItem* id = new QStandardItem(QString("%1").arg(this->track->getTrack()));
  QStandardItem* title = new QStandardItem(this->track->getTitle());
  QStandardItem* album = new QStandardItem(this->track->getAlbum()->getTitle());
  QStandardItem* artist = new QStandardItem(this->track->getArtist()->getName());
  QStandardItem* durarion = new QStandardItem(this->track->getDurationInMinutes());

  this->items.append(id);
  this->items.append(title);
  this->items.append(album);
  this->items.append(artist);
  this->items.append(durarion);
}

QList<QStandardItem*> TrackItem::getItems() const
{
  return this->items;
}

Track* TrackItem::getTrack() const
{
  return this->track;
}

void TrackItem::setTrack(Track& track)
{
  this->track = &track;

  this->items.at(TrackView::TRACK)->setText(QString("%1").arg(track.getTrack()));
  this->items.at(TrackView::TITLE)->setText(track.getTitle());
  this->items.at(TrackView::ALBUM)->setText(track.getAlbum()->getTitle());
  this->items.at(TrackView::ARTIST)->setText(track.getArtist()->getName());
  this->items.at(TrackView::DURATION)->setText(track.getDurationInMinutes());
}
