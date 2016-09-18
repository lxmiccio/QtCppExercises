#include "playlist.h"

Playlist::Playlist()
{
  this->tracks = QVector<Track>();
}

QVector<Track>* Playlist::getTracks()
{
  return &this->tracks;
}

void Playlist::addTrack(Track track)
{
  this->tracks.push_back(track);
}

void Playlist::removeTrack(Track &track)
{
  this->tracks.removeAt(this->tracks.indexOf(track));
}

void Playlist::savePlaylist()
{
  // TO DO
}

void Playlist::loadPlaylist()
{
  // TO DO
}
