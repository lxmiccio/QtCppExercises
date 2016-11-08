#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

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
  void addArtist(const Artist& artist);
  void removeArtist(const Artist& artist);

  QVector<Album>* getAlbumsOfArtist(const Artist& artist) const;
  void addAlbumToArtist(const Album& album, const Artist& artist);
  void removeAlbumFromArtist(const Album& album, const Artist& artist);

  QVector<Track>* getTracksOfArtist(const Artist& artist) const;
  QVector<Track>* getTracksOfAlbum(const Album& album) const;
  void addTrackToAlbum(const Album& album, const Track& track);
  void removeTrackFromAlbum(const Album& album, const Track& track);

  void addTrack(const QVariantMap& tags);

private:
  QVector<Artist>* artists;
};

#endif // MUSICLIBRARY_H
