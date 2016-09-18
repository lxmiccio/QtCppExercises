#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVector>

#include "track.h"

class MusicPlayer
{
private:
  QMediaPlayer* mediaPlayer;
  QMediaPlaylist* mediaPlaylist;
  QVector<Track> tracks;

public:
  MusicPlayer();

  QMediaPlayer* getMediaPlayer();
  QMediaPlaylist* getMediaPlaylist();
  QVector<Track>* getTracks();
};

#endif // MUSICPLAYER_H
