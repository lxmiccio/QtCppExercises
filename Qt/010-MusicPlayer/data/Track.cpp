#include "Track.h"

#include <QFileInfo>

Track::Track()
{

}

Track::Track(const QString& title, quint8 track, quint8 year, quint32 duration, quint32 bitrate, const QString& url, quint64 size, const Album* album)
{
  m_title = title;
  m_track = track;
  m_year = year;
  m_duration = duration;
  m_bitrate = bitrate;
  m_url = url;
  m_size = size;
  m_album = album;

  m_mediaContent = QMediaContent(QUrl(QFileInfo(m_url).absoluteFilePath()));
}

Track::Track(const QVariantMap& tags, const Album* album)
{
  m_title = QString(tags["title"].toString());
  m_track = (quint8) tags["track"].toUInt();
  m_year = (quint8) tags["year"].toUInt();
  m_duration = (quint32) tags["duration"].toUInt();
  m_bitrate = (quint32) tags["bitrate"].toUInt();
  m_url = QString(tags["url"].toString());
  m_size = (quint64) tags["size"].toULongLong();
  m_album = album;

  m_mediaContent = QMediaContent(QUrl(QFileInfo(m_url).absoluteFilePath()));
}

quint8 Track::track() const
{
  return m_track;
}

void Track::setTrack(quint8 track)
{
  m_track = track;
}

const QString& Track::title() const
{
  return m_title;
}

void Track::setTitle(const QString& title)
{
  m_title = title;
}

quint8 Track::year() const
{
  return m_year;
}

void Track::setYear(quint8 year)
{
  m_year = year;
}

quint32 Track::duration() const
{
  return m_duration;
}

QString Track::durationInMinutes() const
{
  return QString("%1:%2").arg(m_duration / 60, 2, 10, QChar('0')).arg(m_duration % 60, 2, 10, QChar('0'));
}

void Track::setDuration(quint32 duration)
{
  m_duration = duration;
}

quint32 Track::bitrate() const
{
  return m_bitrate;
}

void Track::setBitrate(quint32 bitrate)
{
  m_bitrate = bitrate;
}

const QString& Track::url() const
{
  return m_url;
}

void Track::setUrl(const QString &url)
{
  m_url = url;
}

quint64 Track::size() const
{
  return m_size;
}

void Track::setSize(quint64 size)
{
  m_size = size;
}

const QMediaContent& Track::mediaContent() const
{
  return m_mediaContent;
}

void Track::setMediaContent(const QMediaContent& mediaContent)
{
  m_mediaContent = mediaContent;
}

const Album* Track::album() const
{
  return m_album;
}

void Track::setAlbum(Album& album)
{
  m_album = &album;
}

const Artist* Track::artist() const
{
  return m_album->artist();
}

bool Track::isSupportedSuffix(const QString& suffix)
{
  static QVector<QString> suffixes;

  if(suffixes.isEmpty()) {
    suffixes.append("mp3");
  }

  return suffixes.indexOf(suffix) == -1 ? false : true;
}

bool operator==(const Track& track1, const Track& track2)
{
  return track1.title() == track2.title();
}
