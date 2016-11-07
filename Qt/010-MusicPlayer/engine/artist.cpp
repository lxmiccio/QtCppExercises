#include "artist.h"

Artist::Artist()
{
  this->albums = new QVector<Album>();
}

Artist::Artist(const QString& name)
{
  this->name = name;

  this->albums = new QVector<Album>();
}

const QString& Artist::getName() const
{
  return this->name;
}

void Artist::setName(const QString &name)
{
  this->name = name;
}

QVector<Album>* Artist::getAlbums() const
{
  return this->albums;
}

void Artist::addAlbum(const Album &album)
{
  this->albums->push_front(album);
}

void Artist::removeAlbum(const Album &album)
{
  this->albums->removeOne(album);
}

QVector<Track>* Artist::getTracks()
{
  QVector<Track>* tracks = new QVector<Track>();

  for(QVector<Album>::iterator album = this->albums->begin(); album != this->albums->end(); ++album) {
    for(QVector<Track>::iterator track = album->getTracks()->begin(); track != album->getTracks()->end(); ++track) {
      tracks->push_back(*track);
    }
  }

  return tracks;
}

bool operator==(const Artist& artist1, const Artist& artist2)
{
  return artist1.getName() == artist2.getName();
}