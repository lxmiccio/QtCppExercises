#include "track.h"

#include <QMediaMetaData>
#include <QMediaPlayerControl>

Track::Track()
{

}

Track::Track(QMediaContent track)
{
  this->track = track;

  QMediaPlayer* mediaPlayer = new QMediaPlayer();
  mediaPlayer->setMedia(this->track);

  this->title = mediaPlayer->metaData(QMediaMetaData::Title).toString();
  this->album = mediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString();
  this->artist = mediaPlayer->metaData(QMediaMetaData::AlbumArtist).toString();

  delete mediaPlayer;
}

QMediaContent* Track::getTrack()
{
  return &this->track;
}

QString Track::getTitle()
{
  return this->title;
}

QString Track::getAlbum()
{
  return this->album;
}

QString Track::getArtist()
{
  return this->artist;
}
