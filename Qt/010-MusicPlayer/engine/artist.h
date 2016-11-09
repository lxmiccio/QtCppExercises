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
    void setName(const QString& name);

    QVector<Album>* getAlbums() const;
    Album* getAlbum(const QString& title) const;
    void addAlbum(const Album& album);
    bool removeAlbum(Album* album);
    bool removeAlbum(const QString& title);

    QVector<Track>* getTracks();

  private:
    QString name;
    QVector<Album>* albums;
};

bool operator==(const Artist& artist1, const Artist& artist2);

#endif // ARTIST_H
