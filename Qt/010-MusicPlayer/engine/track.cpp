#include "track.h"

#include <QFileInfo>

Track::Track()
{

}

Track::Track(const QString& title, quint8 track, quint8 year, quint32 duration, quint32 bitrate, const QString& url, quint64 size, Album& album)
{
  this->title = title;
  this->track = track;
  this->year = year;
  this->duration = duration;
  this->bitrate = bitrate;
  this->url = url;
  this->size = size;
  this->album = &album;

  this->mediaContent = QMediaContent(QUrl(QFileInfo(this->url).absoluteFilePath()));
}

Track::Track(const QVariantMap& tags, Album& album)
{
  this->title = QString(tags["title"].toString());
  this->track = (quint8) tags["track"].toUInt();
  this->year = (quint8) tags["year"].toUInt();
  this->duration = (quint32) tags["duration"].toUInt();
  this->bitrate = (quint32) tags["bitrate"].toUInt();
  this->url = QString(tags["url"].toString());
  this->size = (quint64) tags["size"].toULongLong();
  this->album = &album;

  this->mediaContent = QMediaContent(QUrl(QFileInfo(this->url).absoluteFilePath()));
}

const QString& Track::getTitle() const
{
  return this->title;
}

void Track::setTitle(const QString& title)
{
  this->title = title;
}

quint8 Track::getYear() const
{
  return this->year;
}

void Track::setYear(quint8 year)
{
  this->year = year;
}

quint32 Track::getDuration() const
{
  return this->getDuration();
}

void Track::setDuration(quint32 duration)
{
  this->duration = duration;
}

quint32 Track::getBitrate() const
{
  return this->bitrate;
}

void Track::setBitrate(quint32 bitrate)
{
  this->bitrate = bitrate;
}

const QString& Track::getUrl() const
{
  return this->url;
}

void Track::setUrl(const QString &url)
{
  this->url = url;
}

quint64 Track::getSize() const
{
  return this->size;
}

void Track::setSize(quint64 size)
{
  this->size = size;
}

QMediaContent Track::getMediaContent() const
{
  return this->mediaContent;
}

void Track::setMediaContent(const QMediaContent& mediaContent)
{
  this->mediaContent = mediaContent;
}

Album* Track::getAlbum() const
{
  return this->album;
}

void Track::setAlbum(Album& album)
{
  this->album = &album;
}

Artist* Track::getArtist() const
{
  return this->album->getArtist();
}

bool operator==(const Track& track1, const Track& track2)
{
  return track1.getTitle() == track2.getTitle();
}
