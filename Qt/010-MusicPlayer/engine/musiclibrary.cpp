#include "musiclibrary.h"

#include <QDebug>

MusicLibrary::MusicLibrary()
{
  this->artists = new QVector<Artist>();
}

QVector<Artist>* MusicLibrary::getArtists() const
{
  return this->artists;
}

Artist* MusicLibrary::getArtist(const QString& name) const
{
  Artist* artist;

  for(QVector<Artist>::iterator iter_artist = this->artists->begin(); iter_artist != this->artists->end(); ++iter_artist) {
    if(iter_artist->getName() == name) {
      artist = iter_artist;
      break;
    }
  }

  return artist;
}

void MusicLibrary::removeArtist(const Artist& artist)
{
  this->artists->removeOne(artist);
}

void MusicLibrary::removeArtist(const QString& name)
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    if(artist->getName() == name) {
      this->artists->removeOne(*artist);
      break;
    }
  }
}

QVector<Album>* MusicLibrary::getAlbums() const
{
  QVector<Album>* albums = new QVector<Album>();

  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    for(QVector<Album>::iterator album = artist->getAlbums()->begin(); album != artist->getAlbums()->end(); ++album) {
      albums->push_back(*album);
    }
  }

  return albums;
}

QVector<Album>* MusicLibrary::getAlbumsOfArtist(const QString& name) const
{
  QVector<Album>* albums = new QVector<Album>();

  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    if(artist->getName() == name) {
      for(QVector<Album>::iterator album = artist->getAlbums()->begin(); album != artist->getAlbums()->end(); ++album) {
        albums->push_back(*album);
      }
      break;
    }
  }

  return albums;
}

void MusicLibrary::removeTrackFromAlbum(const Track& track, const Album& album)
{
  //
}

void removeTrackFromAlbum(const QString& track, const QString& album)
{
  //
}

void MusicLibrary::addTrack(const QVariantMap& tags)
{
  Artist* artist = NULL;
  Album* album = NULL;

  for(QVector<Artist>::iterator iter_artist = this->artists->begin(); iter_artist != this->artists->end(); ++iter_artist) {
    if(iter_artist->getName() == tags["artist"].toString()) {
      artist = iter_artist;
      break;
    }
  }

  if(artist != NULL) {
    for(QVector<Album>::iterator iter_album = artist->getAlbums()->begin(); iter_album != artist->getAlbums()->end(); ++iter_album) {
      if(iter_album->getTitle() == tags["album"].toString()) {
        album = iter_album;
        break;
      }
    }

    if(album != NULL) {
      album->addTrack(Track(tags, album));
    } else {
      album = new Album(tags["album"].toString(), artist);
      album->addTrack(Track(tags, album));

      artist->addAlbum(*album);
    }
  } else {
    artist = new Artist(tags["artist"].toString());

    album = new Album(tags["album"].toString(), artist);
    album->addTrack(Track(tags, album));

    artist->addAlbum(*album);

    this->artists->push_back(*artist);
  }
}

void MusicLibrary::debug()
{
  for(QVector<Artist>::iterator artist = this->getArtists()->begin(); artist != this->getArtists()->end(); ++artist) {
    qDebug() << artist->getName();

    for(QVector<Album>::iterator album = artist->getAlbums()->begin(); album != artist->getAlbums()->end(); ++album) {
      qDebug() << album->getTitle();

      for(QVector<Track>::iterator track = album->getTracks()->begin(); track != album->getTracks()->end(); ++track) {
        qDebug() << track->getTitle();
      }
    }
  }
}
