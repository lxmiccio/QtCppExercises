#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <QVector>

#include "artist.h"
#include "track.h"

class Artist;
class Track;

class Album
{
  public:
    explicit Album();
    explicit Album(const QString& title, Artist* artist);

    const QString& getTitle() const;
    void setTitle(const QString& title);

    QVector<Track>* getTracks() const;
    Track* getTrack(const QString& title) const;
    void addTrack(const Track& track);
    bool removeTrack(const Track& track);

    Artist* getArtist() const;
    void setArtist(Artist* artist);

  private:
    QString title;
    QVector<Track>* tracks;

    Artist* artist;
};

bool operator==(const Album& album1, const Album& album2);

#endif // ALBUM_H
