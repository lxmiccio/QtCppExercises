#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>
#include <QVector>

#include "Track.h"

class Playlist
{
public:
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

#ifdef TEST_PARASOFT
        // Emitting a signal to fill the queue
        ArtModeChange_t mode;
        emit ModeChangeToSend(mode);
#endif
  void addTrack(Track track);
  void removeTrack(Track &track);
  void removeAllTracks();
  QVector<Track>* getTracks();

  void savePlaylist(QString path);

  Playlist loadPlaylist(QString path);

  static QStringList getAllPlaylists(QString path);
};

#endif // PLAYLIST_H
