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
    foreach(Album* i_album, artist->albums()) {
      albums->push_back(*i_album);
    }
  }

  return albums;
}

QVector<Album*>* MusicLibrary::getAlbumsOfArtist(const QString& name) const
{
  if(this->getArtist(name)) {
      /*
    return &this->getArtist(name)->albums();
    */
      //TO DO
      //FOR NEED
  }

  return NULL;
}

Album* MusicLibrary::getAlbum(const QString& title) const
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    foreach(Album* i_album, artist->albums()) {
      if(i_album->title() == title) {
        return i_album;
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
    foreach(Album* i_album, artist->albums()) {
      foreach(Track *i_track, i_album->tracks()) {
        tracks->push_back(*i_track);
      }
    }
  }

  return tracks;
}

QVector<Track>* MusicLibrary::getTracksOfArtist(const QString &name) const
{
  if(this->getArtist(name)) {
    QVector<Track>* tracks = new QVector<Track>();

    foreach(Album* i_album, this->getArtist(name)->albums()) {
      foreach(Track *i_track, i_album->tracks()) {
        tracks->push_back(*i_track);
      }
    }

    return tracks;
  }

  return NULL;
}

QVector<Track*>* MusicLibrary::getTracksOfAlbum(const QString& title) const
{
  if(this->getAlbum(title)) {
    QVector<Track*> tracks = QVector<Track*>();

    //foreach(Track *i_track, album->tracks()) {
      //tracks.push_back(i_track);
    //}

    return &tracks;
  }

  return NULL;
}

bool MusicLibrary::removeTrack(Track* track)
{
  for(QVector<Artist>::iterator artist = this->artists->begin(); artist != this->artists->end(); ++artist) {
    foreach(Album* i_album, artist->albums()) {
      if(i_album->removeTrack(track)) {
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
      foreach(Album* i_album, artist->albums()) {
        if(i_album->title() == tags["album"].toString()) {
          album = i_album;
          break;
        }
      }

      if(album != NULL) {
        track = new Track(tags, album);
        album->addTrack(*track);

        QVector<Track> tracks = QVector<Track>();

        foreach (Track* i_item, album->tracks()) {
            tracks.append(*i_item);
        }

        qSort(tracks.begin(), tracks.end(), [](const Track& a, const Track& b) -> bool { return a.track() < b.track(); });

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

    foreach(Album* i_album, artist->albums()) {
      qDebug() << "***" << i_album->title();

      foreach(Track *i_track, i_album->tracks()) {
        qDebug() << "**" << i_track->title();
      }
    }
  }

  qDebug() << '*';
}
