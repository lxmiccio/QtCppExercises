#include "track.h"

#include <QMediaMetaData>
#include <QMediaPlayerControl>

Track::Track()
{

}

Track::Track(QString artist, QString album, QString title, QString path, QMediaContent mediaContent)
{
  this->artist = artist;
  this->album = album;
  this->title = title;
  this->path = path;
  this->mediaContent = mediaContent;
}

void Track::setTitle(QString title)
{
  this->title = title;
}

QString Track::getTitle()
{
  return this->title;
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

QDataStream &operator<<(QDataStream &out, Track &track)
{
  out << track.getPath();

  return out;
}

QDataStream &operator>>(QDataStream &in, Track &track)
{
  QString path;

  in >> path;

  track.setPath(path);
  track.setMediaContent(QUrl::fromLocalFile(path));

  return in;
}
