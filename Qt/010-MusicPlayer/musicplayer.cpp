#include "musicplayer.h"

MusicPlayer::MusicPlayer()
{
  this->mediaPlayer = new QMediaPlayer();
  this->mediaPlaylist = new QMediaPlaylist();
  this->mediaPlayer->setPlaylist(this->mediaPlaylist);
  this->tracks = QVector<Track>();
}

QMediaPlayer* MusicPlayer::getMediaPlayer()
{
  return this->mediaPlayer;
}

QMediaPlaylist* MusicPlayer::getMediaPlaylist()
{
  return this->mediaPlaylist;
}

QVector<Track>* MusicPlayer::getTracks()
{
  return &this->tracks;
}
