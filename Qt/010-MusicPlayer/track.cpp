#include "track.h"

#include <QMediaMetaData>
#include <QMediaPlayerControl>

Track::Track()
{

}

Track::Track(QString path, QMediaContent mediaContent)
{
  this->path = path;
  this->mediaContent = mediaContent;
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
