#ifndef TRACK_H
#define TRACK_H

#include <QMediaContent>
#include <QString>

class Track
{
private:
  QString artist;
  QString album;
  QString title;
  QString filename;
  QString path;
  QMediaContent mediaContent;

public:
  Track();
  Track(QString artist, QString album, QString title, QString filename, QString path, QMediaContent mediaContent);

  void setArtist(QString artist);
  QString getArtist();

  void setAlbum(QString album);
  QString getAlbum();

  void setTitle(QString title);
  QString getTitle();

  void setFilename(QString filename);
  QString getFilename();

  void setPath(QString path);
  QString getPath();

  void setMediaContent(QMediaContent mediaContent);
  QMediaContent getMediaContent() const;
};

bool operator==(const Track &track1, const Track &track2);

#endif // TRACK_H
