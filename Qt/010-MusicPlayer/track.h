#ifndef TRACK_H
#define TRACK_H

#include <QMediaContent>

class Track
{
private:
  QMediaContent track;
  QString title;
  QString album;
  QString artist;

public:
  Track();
  Track(QMediaContent track);

  QMediaContent* getTrack();
  QString getTitle();
  QString getAlbum();
  QString getArtist();
};

QDataStream& operator<<(QDataStream& out, Track& track);
QDataStream& operator>>(QDataStream& in, Track& track);

#endif // TRACK_H
