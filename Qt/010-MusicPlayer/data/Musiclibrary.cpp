#include "Musiclibrary.h"

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
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    if(artist->name() == name) {
      return artist;
    }
  }

  return NULL;
}

bool MusicLibrary::removeArtist(Artist* artist)
{
  return this->artists->removeOne(*artist);
}

bool MusicLibrary::removeArtist(const QString& name)
{
  return this->artists->removeOne(*this->getArtist(name));
}

QVector<Album>* MusicLibrary::getAlbums() const
{
  QVector<Album>* albums = new QVector<Album>();

  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    for(QVector<Album>::iterator album = artist->albums()->begin(); album != artist->albums()->end(); ++album) {
      albums->push_back(*album);
    }
  }

  return albums;
}

QVector<Album>* MusicLibrary::getAlbumsOfArtist(const QString& name) const
{
  if(this->getArtist(name)) {
    return this->getArtist(name)->albums();
  }

  return NULL;
}

Album* MusicLibrary::getAlbum(const QString& title) const
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    for(QVector<Album>::iterator album = artist->albums()->begin(); album != artist->albums()->end(); ++album) {
      if(album->title() == title) {
        return album;
      }
    }
  }

  return NULL;
}

bool MusicLibrary::removeAlbum(Album* album)
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    if(artist->removeAlbum(*album)) {
      return true;
    }
  }

  return false;
}

bool MusicLibrary::removeAlbum(const QString& albumName, const QString& artistName)
{
  if(this->getArtist(artistName)) {
    return this->getArtist(artistName)->removeAlbum(albumName);
  } else {
    return false;
  }
}

QVector<Track>* MusicLibrary::getTracks() const
{
  QVector<Track>* tracks = new QVector<Track>();

  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    for(QVector<Album>::iterator album = artist->albums()->begin(); album != artist->albums()->end(); ++album) {
      for(QVector<Track>::iterator track = album->tracks()->begin(); track != album->tracks()->end(); ++track) {
        tracks->push_back(*track);
      }
    }
  }

  return tracks;
}

QVector<Track>* MusicLibrary::getTracksOfArtist(const QString &name) const
{
  if(this->getArtist(name)) {
    QVector<Track>* tracks = new QVector<Track>();

    for(QVector<Album>::iterator album = this->getArtist(name)->albums()->begin(); album != this->getArtist(name)->albums()->end(); ++album) {
      for(QVector<Track>::iterator track = album->tracks()->begin(); track != album->tracks()->end(); ++track) {
        tracks->push_back(*track);
      }
    }

    return tracks;
  }

  return NULL;
}

QVector<Track>* MusicLibrary::getTracksOfAlbum(const QString& title) const
{
  if(this->getAlbum(title)) {
    QVector<Track>* tracks = new QVector<Track>();

    for(QVector<Track>::iterator track = this->getAlbum(title)->tracks()->begin(); track != this->getAlbum(title)->tracks()->end(); ++track) {
      tracks->push_back(*track);
    }

    return tracks;
  }

  return NULL;
}

bool MusicLibrary::removeTrack(Track* track)
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    for(QVector<Album>::iterator album = artist->albums()->begin(); album != artist->albums()->end(); ++album) {
      if(album->removeTrack(track)) {
        return true;
      }
    }
  }

  return false;
}

bool MusicLibrary::removeTrack(const QString& trackTitle, const QString& albumTitle)
{
  if(this->getAlbum(albumTitle) != NULL) {
    return this->getAlbum(albumTitle)->removeTrack(trackTitle);
  }

  return false;
}

Track* MusicLibrary::addTrack(const QVariantMap& tags)
{
  Artist* artist = NULL;
  Album* album = NULL;
  Track* track = NULL;

  if(tags["artist"].toString().length() > 0 && tags["album"].toString().length() && tags["title"].toString().length() && tags["track"] > 0 && tags["duration"] > 0) {
    for(QVector<Artist>::iterator iter_artist = this->artists->begin(); iter_artist != this->artists->end(); ++iter_artist) {
      if(iter_artist->name() == tags["artist"].toString()) {
        artist = iter_artist;
        break;
      }
    }

    if(artist != NULL) {
      for(QVector<Album>::iterator iter_album = artist->albums()->begin(); iter_album != artist->albums()->end(); ++iter_album) {
        if(iter_album->title() == tags["album"].toString()) {
          album = iter_album;
          break;
        }
      }

      if(album != NULL) {
        track = new Track(tags, album);
        album->addTrack(*track);

        qSort(album->tracks()->begin(), album->tracks()->end(), [](const Track& a, const Track& b) -> bool { return a.track() < b.track(); });

      } else {
        album = new Album(tags["album"].toString(), artist);

        track = new Track(tags, album);
        album->addTrack(*track);

        artist->addAlbum(*album);
      }
    } else {
      artist = new Artist(tags["artist"].toString());

      album = new Album(tags["album"].toString(), artist);

      track = new Track(tags, album);
      album->addTrack(*track);

      artist->addAlbum(*album);

      this->artists->push_back(*artist);
      qDebug()<<album->artist();
    }
  }

  return track;
}

void MusicLibrary::debug()
{
  qDebug() << "*****";

  for(QVector<Artist>::iterator artist = this->getArtists()->begin(); artist != this->getArtists()->end(); ++artist) {
    qDebug() << "****" << artist->name();

    for(QVector<Album>::iterator album = artist->albums()->begin(); album != artist->albums()->end(); ++album) {
      qDebug() << "***" << album->title();

      for(QVector<Track>::iterator track = album->tracks()->begin(); track != album->tracks()->end(); ++track) {
        qDebug() << "**" << track->title();
      }
    }
  }

  qDebug() << '*';
}
