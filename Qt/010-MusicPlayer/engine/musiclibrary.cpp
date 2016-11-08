
#include "musiclibrary.h"

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
    if(artist->getName() == name) {
      return artist;
    }
  }

  return NULL;
}

void MusicLibrary::addTrack(const QVariantMap& tags)
{
  Artist* artist = NULL;

  for(QVector<Artist>::iterator iter_artist = this->artists->begin(); iter_artist != this->artists->end(); ++iter_artist) {
    if(iter_artist->getName() == tags["artist"]) {
      artist = iter_artist;
      break;
    }
  }

  if(artist != NULL) {
    Album* album = NULL;

    for(QVector<Album>::iterator iter_album = artist->getAlbums()->begin(); iter_album != artist->getAlbums()->end(); ++iter_album) {
      if(iter_album->getTitle() == tags["album"]) {
        album = iter_album;
        break;
      }
    }

    if(album != NULL) {
      //album->addTrack(Track(tags));
    } else {
      album = new Album(tags["album"].toString());
      album->addTrack(Track(tags, album));

      artist->addAlbum(*album);
    }
  } else {
    Album* album = new Album(tags["album"].toString());
    album->addTrack(Track(tags, album));

    artist = new Artist(tags["artist"].toString());
    artist->addAlbum(*album);
  }
}
