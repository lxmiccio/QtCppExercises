#include "playlist.h"

#include <QDir>
#include <QFile>
#include <QDebug>

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
  if(not QDir(QDir::currentPath() + "/tracks").exists()) {
    QDir().mkdir(QDir::currentPath() + "/tracks");
  }

  for(QVector<Track>::iterator i {this->tracks.begin()}; i != this->tracks.end(); ++i) {
    qDebug() << i->getPath();
    qDebug() << QDir::currentPath() + "/tracks";
    QFile::copy(i->getPath(), QDir::currentPath() + "/tracks/a.mp3");
  }
}

void Playlist::loadPlaylist()
{
    // TO DO
}
