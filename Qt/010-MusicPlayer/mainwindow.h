#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QVector>
#include <QVBoxLayout>



#include "gui/audiocontrols.h"
#include "musicplayer.h"
#include "playlist.h"
#include "Track.h"
#include "Musiclibrary.h"

#include "TagUtils.h"

#include "TrackDelegate.h"
#include "TrackItem.h"
#include "TrackView.h"

#include "AlbumView.h"
#include "ScrollArea.h"

#include "ImageButton.h"
#include "StackedWidget.h"
#include "BackgroundWidget.h"

#include <QStandardItemModel>

class MainWindow : public BackgroundWidget
{
  Q_OBJECT

private:
  const StackedWidget* c_stackedWidget;

  AlbumView* m_albumView;
  ScrollArea* m_scrollArea;

  TrackView* m_trackView;

  AudioControls* m_audioControls;

  QVBoxLayout* m_layout;

  MusicLibrary* m_musicLibrary;

public:
  MainWindow(const StackedWidget* stackedWidget, QWidget* parent = 0);

public slots:
  void onCoverClicked(const Album& album);

  void onFastBackwardClicked();
  void onBackwardClicked();
  void onPlayClicked();
  void onPauseClicked();
  void onFastForwardClicked();
  void onForwardClicked();
  void onFileDropped(const QFileInfo& fileInfo);
  void onMusicSliderMoved(int position, int minimum, int maximum);
  void onShuffleClicked(AC::ShuffleMode_t shuffleMode);
  void onRepeatClicked(AC::RepeatMode_t repeatMode);
  void onVolumeClicked(AC::VolumeMode_t volumeMode);

  void itemDoubleClicked(const Track&){
    m_scrollArea->show();
    m_trackView->hide();
  }

  void onCurrentMediaChanged(QMediaContent);


  void mediaPlayerPositionChanged(qint64 position);
  void musicSliderMoved(int value);
  void musicSliderPressed();
  void musicSliderReleased();
  void volumeSliderMoved(int value);
  void volumeValueChanged(int value);
  void trackListItemDoubleClicked(const QModelIndex& index);
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
  void trackAdded(const Track& track);
  currentMediaChanged(Track &track);
  positionChanged(qint64 position, qint64 duration);
};

#endif // MAINWINDOW_H
