#include "album.h"

Album::Album()
{
  this->tracks = new QVector<Track>();
}

Album::Album(const QString& title, Artist *artist)
{
  this->title = title;

  if(artist != NULL) {
    this->artist = artist;
  } else {
    // TO DO
  }

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

Track* Album::getTrack(const QString& title) const
{
  for(QVector<Track>::iterator track = this->tracks->begin(); track != this->tracks->end(); ++track) {
    if(track->getTitle() == title) {
      return track;
    }
  }

  return NULL;
}

void Album::addTrack(const Track& track)
{
  this->tracks->push_back(track);
}

bool Album::removeTrack(const Track& track)
{
  return this->tracks->removeOne(track);
}

Artist* Album::getArtist() const
{
  return this->artist;
}

void Album::setArtist(Artist* artist)
{
  if(artist != NULL) {
    this->artist = artist;
  } else {
    // TO DO
  }
}

bool operator==(const Album& album1, const Album& album2)
{
  return album1.getTitle() == album2.getTitle();
}
