#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <QString>
#include <QVector>

#include "artist.h"
#include "album.h"
#include "track.h"

class MusicLibrary
{
public:
  explicit MusicLibrary();

  QVector<Artist>* getArtists() const;
  Artist* getArtist(const QString& name) const;
  bool removeArtist(Artist* artist);
  bool removeArtist(const QString& name);

  QVector<Album>* getAlbums() const;
  QVector<Album>* getAlbumsOfArtist(const QString& name) const;
  Album* getAlbum(const QString& title) const;
  bool removeAlbum(Album* album);
  bool removeAlbum(const QString& albumName, const QString &artistName);

  QVector<Track>* getTracks() const;
  QVector<Track>* getTracksOfArtist(const QString& name) const;
  QVector<Track>* getTracksOfAlbum(const QString& title) const;
  bool removeTrack(Track* track);
  bool removeTrack(const QString& trackTitle, const QString& albumTitle);

  Track *addTrack(const QVariantMap& tags);

  void debug();

private:
  QVector<Artist>* artists;
};

#endif // MUSICLIBRARY_H
