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
  bool removeArtist(const Artist& artist);
  bool removeArtist(const QString& name);

  QVector<Album>* getAlbums() const;
  QVector<Album>* getAlbumsOfArtist(const QString& artistName) const;
  bool removeAlbum(const Album& album);
  bool removeAlbum(const QString& albumName, const QString &artistName);

  QVector<Track>* getTracksOfArtist(const QString& album) const;
  QVector<Track>* getTracksOfAlbum(const QString& album) const;
  bool removeTrack(const Track& name);
  bool removeTrack(const QString& trackName, const QString& albumName);

  void addTrack(const QVariantMap& tags);

  void debug();

private:
  QVector<Artist>* artists;
};

#endif // MUSICLIBRARY_H
