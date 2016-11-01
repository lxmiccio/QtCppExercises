#include "track.h"

#include <QMediaMetaData>
#include <QMediaPlayerControl>

Track::Track()
{

}

Track::Track(QString artist, QString album, QString title, QString filename, QString path, QMediaContent mediaContent)
{
  this->artist = artist;
  this->album = album;
  this->title = title;
  this->filename = filename;
  this->path = path;
  this->mediaContent = mediaContent;
}

void Track::setArtist(QString artist)
{
  this->artist = artist;
}

QString Track::getArtist()
{
  return this->artist;
}

void Track::setAlbum(QString album)
{
  this->album = album;
}

QString Track::getAlbum()
{
  return this->album;
}

void Track::setTitle(QString title)
{
  this->title = title;
}

QString Track::getTitle()
{
  return this->title;
}

void Track::setFilename(QString filename)
{
  this->filename = filename;
}

QString Track::getFilename()
{
  return this->filename;
}

void Track::setPath(QString path)
{
  this->path = path;
}

QString Track::getPath()
{
  return this->path;
}

void Track::setMediaContent(QMediaContent mediaContent)
{
  this->mediaContent = mediaContent;
}

QMediaContent Track::getMediaContent() const
{
  return this->mediaContent;
}

bool operator==(const Track &track1, const Track &track2)
{
  return track1.getMediaContent() == track2.getMediaContent();
}
