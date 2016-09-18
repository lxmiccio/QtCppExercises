#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>

#include "musicplayer.h"
#include "playlist.h"
#include "track.h"

class MainWindow : public QWidget
{
  Q_OBJECT

private:
  MusicPlayer* musicPlayer;
  Playlist* playlist;
  QSlider* musicSlider;
  QSlider* volumeSlider;
  QListWidget* trackList;
  QPushButton* play;
  QPushButton* stop;
  QPushButton* previous;
  QPushButton* next;
  QPushButton* addSong;
  QPushButton* addDirectory;
  QPushButton* savePlaylist;
  QPushButton* loadPlaylist;

public:
  explicit MainWindow(QWidget *parent = 0);

public slots:
  void mediaPlayerPositionChanged(qint64 position);
  void musicSliderMoved(int value);
  void musicSliderPressed();
  void musicSliderReleased();
  void volumeSliderMoved(int value);
  void volumeValueChanged(int value);
  void trackListItemDoubleClicked(QListWidgetItem*);
  void playClicked();
  void stopClicked();
  void previousClicked();
  void nextClicked();
  void addSongClicked();
  void addDirectoryClicked();
  void savePlaylistClicked();
  void loadPlaylistClicked();
};

#endif // MAINWINDOW_H
