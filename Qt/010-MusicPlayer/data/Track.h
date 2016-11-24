#ifndef TRACK_H
#define TRACK_H

#include <QMediaContent>
#include <QString>

#include "artist.h"
#include "album.h"

class Album;
class Artist;

class Track
{
  public:
    explicit Track();
    Track(const QString& title, quint8 track, quint8 year, quint32 duration, quint32 bitrate, const QString& url, quint64 size, const Album* album);
    Track(const QVariantMap& tags, const Album* album);

    const QString& title() const;
    void setTitle(const QString& title);

    quint8 track() const;
    void setTrack(quint8 track);

    quint8 year() const;
    void setYear(quint8 year);

    quint32 duration() const;
    QString durationInMinutes() const;
    void setDuration(quint32 duration);

    quint32 bitrate() const;
    void setBitrate(quint32 bitrate);

    const QString& url() const;
    void setUrl(const QString& url);

    quint64 size() const;
    void setSize(quint64 size);

    const QMediaContent& mediaContent() const;
    void setMediaContent(const QMediaContent& mediaContent);

    const Album* album() const;
    void setAlbum(Album& album);

    const Artist *artist() const;

    static bool isSupportedSuffix(const QString& suffix);

  private:
    QString m_title;
    quint8 m_track;
    quint8 m_year;
    quint32 m_duration;
    quint32 m_bitrate;

    QString m_url;
    quint64 m_size;

    QMediaContent m_mediaContent;

    const Album* m_album;
};

bool operator==(const Track& track1, const Track& track2);

#endif // TRACK_H
