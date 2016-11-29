#include "Artist.h"

Artist::Artist()
{
  m_albums = QVector<Album*>();
}

Artist::Artist(const QString& name)
{
  m_name = name;

  m_albums = QVector<Album*>();
}

const QString& Artist::name() const
{
  return m_name;
}

void Artist::setName(const QString& name)
{
  m_name = name;
}

QVector<Album*> Artist::albums() const
{
  return m_albums;
}

Album* Artist::album(const QString& title)
{
  foreach(Album* i_album, m_albums) {
    if(i_album->title() == title) {
      return i_album;
    }
  }

  return NULL;
}

void Artist::addAlbum(Album &album)
{
  m_albums.push_back(&album);
}

bool Artist::removeAlbum(Album& album)
{
  return m_albums.removeOne(&album);
}

bool Artist::removeAlbum(const QString& title)
{
  foreach(Album* i_album, m_albums) {
    if(i_album->title() == title) {
      return m_albums.removeOne(i_album);
    }
  }

  return false;
}

QVector<Track>* Artist::tracks() const
{
  QVector<Track>* tracks = new QVector<Track>();

  foreach(Album* i_album, m_albums) {
    foreach(Track* i_track, i_album->tracks()) {
      tracks->push_back(*i_track);
    }
  }

  return tracks;
}

bool operator==(const Artist& artist1, const Artist& artist2)
{
  return artist1.name() == artist2.name();
}
