#include "Album.h"

Album::Album()
{
  m_tracks = QVector<Track*>();
}

Album::Album(const QString& title, const Artist* artist)
{
  m_title = title;
  m_artist = artist;
  m_image = QImage(":/images/queen-of-the-clouds.jpg");

  m_tracks = QVector<Track*>();
}

const QString& Album::title() const
{
  return m_title;
}

void Album::setTitle(const QString& title)
{
  m_title = title;
}

QVector<Track*> Album::tracks() const
{
  return m_tracks;
}

Track* Album::track(const QString& title)
{
  foreach(Track* i_track, m_tracks) {
    if(i_track->title() == title) {
      //return track;
    }
  }

  return NULL;
}

void Album::addTrack(Track& track)
{
  m_tracks.push_back(&track);
}

bool Album::removeTrack(Track* track)
{
  return m_tracks.removeOne(track);
}

bool Album::removeTrack(const QString& title)
{
  foreach(Track* i_track, m_tracks) {
    if(i_track->title() == title) {
      return m_tracks.removeOne(i_track);
    }
  }

  return false;
}

const Artist* Album::artist() const
{
  return m_artist;
}

void Album::setArtist(Artist& artist)
{
  m_artist = &artist;
}

const QImage& Album::image() const
{
    return m_image;
}

bool operator==(const Album& album1, const Album& album2)
{
  return album1.title() == album2.title();
}
