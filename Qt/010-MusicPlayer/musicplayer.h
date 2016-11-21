#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVector>

#include "Track.h"

class MusicPlayer
{
private:
  QMediaPlayer* mediaPlayer;
  QMediaPlaylist* mediaPlaylist;

public:
  MusicPlayer();

  QMediaPlayer* getMediaPlayer();

  void addTrack(Track& track);
  void addTracks(QVector<Track> &tracks);
  void removeTrack(Track& track);
  void removeAllTracks();
  QMediaPlaylist* getMediaPlaylist();
};

#endif // MUSICPLAYER_H
