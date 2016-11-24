#include "Artist.h"

Artist::Artist()
{
  m_albums = new QVector<Album>();
}

Artist::Artist(const QString& name)
{
  m_name = name;

  m_albums = new QVector<Album>();
}

const QString& Artist::name() const
{
  return m_name;
}

void Artist::setName(const QString& name)
{
  m_name = name;
}

QVector<Album>* Artist::albums() const
{
  return m_albums;
}

Album* Artist::album(const QString& title) const
{
  for(QVector<Album>::iterator album = m_albums->begin(); album != m_albums->end(); ++album) {
    if(album->title() == title) {
      return album;
    }
  }

  return NULL;
}

void Artist::addAlbum(const Album &album)
{
  m_albums->push_back(album);
}

bool Artist::removeAlbum(const Album& album)
{
  return m_albums->removeOne(album);
}

bool Artist::removeAlbum(const QString& title)
{
  for(QVector<Album>::iterator album = m_albums->begin(); album != m_albums->end(); ++album) {
    if(album->title() == title) {
      return m_albums->removeOne(*album);
    }
  }

  return false;
}

QVector<Track>* Artist::tracks() const
{
  QVector<Track>* tracks = new QVector<Track>();

  for(QVector<Album>::iterator album = m_albums->begin(); album != m_albums->end(); ++album) {
    for(QVector<Track>::iterator track = album->tracks()->begin(); track != album->tracks()->end(); ++track) {
      tracks->push_back(*track);
    }
  }

  return tracks;
}

bool operator==(const Artist& artist1, const Artist& artist2)
{
  return artist1.name() == artist2.name();
}
