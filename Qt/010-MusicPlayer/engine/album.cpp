#include "album.h"

Album::Album()
{
  this->tracks = new QVector<Track>();
}

Album::Album(const QString& title)
{
  this->title = title;

  this->tracks = new QVector<Track>();
}

const QString& Album::getTitle() const
{
  return this->title;
}

void Album::setTitle(const QString& title)
{
  this->title = title;
}

QVector<Track>* Album::getTracks() const
{
  return this->tracks;
}

void Album::addTrack(const Track& track)
{
  this->tracks->push_back(track);
}

void Album::removeTrack(const Track& track)
{
  this->tracks->removeOne(track);
}

Artist* Album::getArtist() const
{
  return this->artist;
}

void Album::setArtist(Artist* artist)
{
  if(artist != NULL) {
    this->artist = artist;
  }
}

bool operator==(const Album& album1, const Album& album2)
{
  return album1.getTitle() == album2.getTitle();
}
