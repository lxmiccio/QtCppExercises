#ifndef ALBUM_H
#define ALBUM_H

#include <QImage>
#include <QString>
#include <QVector>

#include "Artist.h"
#include "Track.h"

class Artist;
class Track;

class Album
{
public:
    explicit Album();
    explicit Album(const QString& title, const Artist* artist);

    const QString& title() const;
    void setTitle(const QString& title);

    const QImage& image() const;
    void setImage(const QString& image);

    const QVector<Track*>& tracks() const;
    Track* track(const QString& title) const;
    void addTrack(Track& track);
    bool removeTrack(Track* track);
    bool removeTrack(const QString& title);

    const Artist* artist() const;
    void setArtist(Artist& artist);

private:
    QString m_title;
    QImage m_image;

    QVector<Track*> m_tracks;
    const Artist* m_artist;
};

bool operator==(const Album& album1, const Album& album2);

#endif // ALBUM_H
