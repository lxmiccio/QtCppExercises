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

    const QString& getName() const;
    void setName(const QString &name);

    QVector<Album>* getAlbums() const;
    void addAlbum(const Album& album);
    void removeAlbum(const Album& album);

    QVector<Track>* getTracks();

  private:
    QString name;
    QVector<Album>* albums;
};

bool operator==(const Artist& artist1, const Artist& artist2);

#endif // ARTIST_H
