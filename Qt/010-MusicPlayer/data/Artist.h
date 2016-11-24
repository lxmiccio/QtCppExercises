#ifndef ARTIST_H
#define ARTIST_H

#include <QString>
#include <QVector>

#include "album.h"
#include "track.h"

class Album;

class Artist
{
  public:
    explicit Artist();
    explicit Artist(const QString &title);

    const QString& name() const;
    void setName(const QString& name);

    QVector<Album>* albums() const;
    Album* album(const QString& title) const;
    void addAlbum(const Album& album);
    bool removeAlbum(const Album& album);
    bool removeAlbum(const QString& title);

    QVector<Track>* tracks() const;

  private:
    QString m_name;
    QVector<Album>* m_albums;
};

bool operator==(const Artist& artist1, const Artist& artist2);

#endif // ARTIST_H
