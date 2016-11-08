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
  void removeArtist(const Artist& artist);
  void removeArtist(const QString& name);

  QVector<Album>* getAlbums() const;
  QVector<Album>* getAlbumsOfArtist(const QString& name) const;
  void removeAlbumFromArtist(const Album& album, const Artist& artist);
  void removeAlbumFromArtist(const QString& album, const QString& artist);

  QVector<Track>* getTracksOfArtist(const QString& album) const;
  QVector<Track>* getTracksOfAlbum(const QString& album) const;
  void removeTrackFromAlbum(const Track& track, const Album& album);
  void removeTrackFromAlbum(const QString& track, const QString& album);

  void addTrack(const QVariantMap& tags);

  void debug();

private:
  QVector<Artist>* artists;
};

#endif // MUSICLIBRARY_H
