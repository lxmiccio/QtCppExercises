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
    Track(const QString& title, quint8 track, quint8 year, quint32 duration, quint32 bitrate, const QString& url, quint64 size, Album& album);
    Track(const QVariantMap& tags, Album& album);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    quint8 getTrack();
    void setTrack(quint8 track);

    quint8 getYear() const;
    void setYear(quint8 year);

    quint32 getDuration() const;
    QString getDurationInMinutes() const;
    void setDuration(quint32 duration);

    quint32 getBitrate() const;
    void setBitrate(quint32 bitrate);

    const QString& getUrl() const;
    void setUrl(const QString& url);

    quint64 getSize() const;
    void setSize(quint64 size);

    QMediaContent getMediaContent() const;
    void setMediaContent(const QMediaContent& mediaContent);

    Album* getAlbum() const;
    void setAlbum(Album& album);

    Artist* getArtist() const;

  private:
    QString title;
    quint8 track;
    quint8 year;
    quint32 duration;
    quint32 bitrate;

    QString url;
    quint64 size;

    QMediaContent mediaContent;

    Album* album;
};

bool operator==(const Track& track1, const Track& track2);

#endif // TRACK_H
