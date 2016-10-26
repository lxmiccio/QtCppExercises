#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QVector>

#include "track.h"

class Playlist
{
private:
  QVector<Track> tracks;

public:
  Playlist();

  void addTrack(Track track);
  void removeTrack(Track &track);
  QVector<Track>* getTracks();

  void savePlaylist();

  void loadPlaylist();
};

#endif // PLAYLIST_H
