#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QWidget>
#include <QPushButton>
#include <QSlider>

#include "gui/imagebutton.h"

#include "tag/tagmanager.h"

#include "gui/audiocontrols.h"
#include "musicplayer.h"
#include "playlist.h"
#include "gui/stackedwidget.h"
#include "engine/track.h"

class MainWindow : public QWidget
{
  Q_OBJECT

private:
  StackedWidget* stackedWidget;
  MusicPlayer* musicPlayer;
  Playlist* playlist;
  QListWidget* trackList;
  AudioControls* audioControls;
  QPushButton* addSong;
  QPushButton* addDirectory;
  QPushButton* remove;
  QPushButton* removeAll;
  QPushButton* savePlaylist;
  QPushButton* loadPlaylist;

  QLabel *l;

public:
  MainWindow(StackedWidget *stackedWidget, QWidget *parent = 0);

public slots:
  void onFastBackwardClicked();
  void onBackwardClicked();
  void onPlayClicked();
  void onPauseClicked();
  void onFastForwardClicked();
  void onForwardClicked();
  void onMusicSliderMoved(int position, int minimum, int maximum);
  void onShuffleClicked(AC::ShuffleMode_t shuffleMode);
  void onRepeatClicked(AC::RepeatMode_t repeatMode);
  void onVolumeClicked(AC::VolumeMode_t volumeMode);


  void onCurrentMediaChanged(QMediaContent);


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
  void removeClicked();
  void removeAllClicked();
  void savePlaylistClicked();
  void loadPlaylistClicked();
  void playlistLoaded(QString playlistName);

signals:
  currentMediaChanged(Track &track);
  positionChanged(qint64 position, qint64 duration);
};

#endif // MAINWINDOW_H
