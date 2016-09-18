#ifndef TRACK_H
#define TRACK_H

#include <QMediaContent>
#include <QString>

class Track
{
private:
  QString path;
  QMediaContent mediaContent;

public:
  Track();
  Track(QString path, QMediaContent mediaContent);

  void setPath(QString path);
  QString getPath();

  void setMediaContent(QMediaContent mediaContent);
  QMediaContent getMediaContent() const;
};

bool operator==(const Track &track1, const Track &track2);

QDataStream &operator<<(QDataStream &out, Track &track);
QDataStream &operator>>(QDataStream &in, Track &track);

#endif // TRACK_H
