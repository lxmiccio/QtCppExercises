#include "musicplayer.h"

MusicPlayer::MusicPlayer()
{
  this->mediaPlayer = new QMediaPlayer();
  this->mediaPlayer->setVolume(100);
  this->mediaPlaylist = new QMediaPlaylist();
  this->mediaPlayer->setPlaylist(this->mediaPlaylist);
}

QMediaPlayer* MusicPlayer::getMediaPlayer()
{
  return this->mediaPlayer;
}

void MusicPlayer::addTrack(Track &track)
{
  //qDebug() << track.getPath();
  //this->mediaPlaylist->addMedia(track.getMediaContent());
}

void MusicPlayer::addTracks(QVector<Track> &tracks)
{
  for(QVector<Track>::iterator track {tracks.begin()}; track != tracks.end(); ++track) {
    //this->mediaPlaylist->addMedia(track->getMediaContent());
  }
}

void MusicPlayer::removeTrack(Track &track)
{
  for(int i {0}; i < this->mediaPlaylist->mediaCount(); ++i) {
    //if(this->mediaPlaylist->media(i) == track.getMediaContent()) {
      //this->mediaPlaylist->removeMedia(i);
      //break;
    //}
  }
}

void MusicPlayer::removeAllTracks()
{
  this->mediaPlaylist->clear();
}

QMediaPlaylist* MusicPlayer::getMediaPlaylist()
{
  return this->mediaPlaylist;
}
