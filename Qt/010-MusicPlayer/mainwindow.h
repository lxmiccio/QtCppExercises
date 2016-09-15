#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>

class MainWindow : public QWidget
{
  Q_OBJECT

private:
  QMediaPlayer* mediaPlayer;
  QMediaPlaylist* mediaPlaylist;
  QSlider* musicSlider;
  QSlider* volumeSlider;
  QListWidget* trackList;
  QPushButton* play;
  QPushButton* stop;
  QPushButton* addSong;
  QPushButton* addDirectory;

public:
  explicit MainWindow(QWidget *parent = 0);

public slots:
  void mediaPlayerPositionChanged(qint64 position);
  void musicSliderMoved(int value);
  void musicSliderPressed();
  void musicSliderReleased();
  void volumeSliderMoved(int value);
  void trackListItemDoubleClicked(QListWidgetItem*);
  void playClicked();
  void stopClicked();
  void addSongClicked();
  void addDirectoryClicked();
};

#endif // MAINWINDOW_H
