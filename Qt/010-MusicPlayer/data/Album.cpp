#include "Album.h"

Album::Album()
{
  this->tracks = new QVector<Track>();
}

Album::Album(const QString& title, Artist& artist)
{
  this->title = title;
  this->artist = &artist;

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

bool Album::removeTrack(Track* track)
{
  return this->tracks->removeOne(*track);
}

bool Album::removeTrack(const QString& title)
{
  for(QVector<Track>::iterator track = this->tracks->begin(); track != this->tracks->end(); ++track) {
    if(track->getTitle() == title) {
      return this->tracks->removeOne(*track);
    }
  }

  return false;
}

Artist* Album::getArtist() const
{
  return this->artist;
}

void Album::setArtist(Artist& artist)
{
  this->artist = &artist;
}

bool operator==(const Album& album1, const Album& album2)
{
  return album1.getTitle() == album2.getTitle();
}
