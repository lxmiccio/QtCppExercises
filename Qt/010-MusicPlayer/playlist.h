#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <QVector>

#include "track.h"

class Playlist
{
  static const int16_t ARTIST_INDEX = 3;
  static const int16_t ALBUM_INDEX = 2;
  static const int16_t TITLE_INDEX = 1;

private:
  QString name;
  QVector<Track> tracks;

public:
  Playlist();

  void setName(QString name);
  QString getName();

  void addTrack(Track track);
  void removeTrack(Track &track);
  QVector<Track>* getTracks();

  void savePlaylist(QString path);

  Playlist loadPlaylist(QString path);

  static QStringList getAllPlaylists(QString path);
};

#endif // PLAYLIST_H
