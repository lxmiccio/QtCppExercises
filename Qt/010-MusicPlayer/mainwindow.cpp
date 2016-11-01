#include "mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QGridLayout>
#include <QMediaMetaData>
#include <QString>
#include <QStringList>

#include "imageloader.h"
#include "loadplaylistwindow.h"
#include "saveplaylistwindow.h"

MainWindow::MainWindow(StackedWidget *stackedWidget, QWidget *parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  this->musicPlayer = new MusicPlayer();
  QObject::connect(this->musicPlayer->getMediaPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(mediaPlayerPositionChanged(qint64)));

  this->playlist = new Playlist();

  this->musicSlider = new QSlider();
  this->musicSlider->setOrientation(Qt::Horizontal);
  this->musicSlider->setRange(0, 500);
  QObject::connect(this->musicSlider, SIGNAL(sliderMoved(int)), this, SLOT(musicSliderMoved(int)));
  QObject::connect(this->musicSlider, SIGNAL(sliderPressed()), this, SLOT(musicSliderPressed()));
  QObject::connect(this->musicSlider, SIGNAL(sliderReleased()), this, SLOT(musicSliderReleased()));

  this->volumeSlider = new QSlider();
  this->volumeSlider->setOrientation(Qt::Horizontal);
  this->volumeSlider->setRange(0, 100);
  this->volumeSlider->setValue(100);
  QObject::connect(this->volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(volumeSliderMoved(int)));
  QObject::connect(this->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(volumeValueChanged(int)));

  this->trackList = new QListWidget();
  QObject::connect(this->trackList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(trackListItemDoubleClicked(QListWidgetItem*)));

  this->play = new QPushButton("Play");
  QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(playClicked()));

  this->stop = new QPushButton("Stop");
  this->stop->hide();
  QObject::connect(this->stop, SIGNAL(clicked()), this, SLOT(stopClicked()));

  this->previous = new QPushButton("Previous");
  QObject::connect(this->previous, SIGNAL(clicked()), this, SLOT(previousClicked()));

  this->next = new QPushButton("Next");
  QObject::connect(this->next, SIGNAL(clicked()), this, SLOT(nextClicked()));

  this->addSong = new QPushButton("Add Song");
  QObject::connect(this->addSong, SIGNAL(clicked()), this, SLOT(addSongClicked()));

  this->addDirectory = new QPushButton("Add Directory");
  QObject::connect(this->addDirectory, SIGNAL(clicked()), this, SLOT(addDirectoryClicked()));

  this->remove = new QPushButton("Remove");
  QObject::connect(this->remove, SIGNAL(clicked()), this, SLOT(removeClicked()));

  this->removeAll = new QPushButton("Remove All");
  QObject::connect(this->removeAll, SIGNAL(clicked()), this, SLOT(removeAllClicked()));

  this->savePlaylist = new QPushButton("Save Playlist");
  QObject::connect(this->savePlaylist, SIGNAL(clicked()), this, SLOT(savePlaylistClicked()));

  this->loadPlaylist = new QPushButton("Load Playlist");
  QObject::connect(this->loadPlaylist, SIGNAL(clicked()), this, SLOT(loadPlaylistClicked()));

  QGridLayout* gridLayout = new QGridLayout();

  gridLayout->setSpacing(10);

  gridLayout->addWidget(this->musicSlider, 0, 0, 1, 1);
  gridLayout->addWidget(this->volumeSlider, 1, 0, 1, 1);
  gridLayout->addWidget(this->trackList, 2, 0, 7, 1);
  gridLayout->addWidget(this->play, 0, 1, 1, 1);
  gridLayout->addWidget(this->stop, 0, 1, 1, 1);
  gridLayout->addWidget(this->previous, 1, 1, 1, 1);
  gridLayout->addWidget(this->next, 2, 1, 1, 1);
  gridLayout->addWidget(this->addSong, 3, 1, 1, 1);
  gridLayout->addWidget(this->addDirectory, 4, 1, 1, 1);
  gridLayout->addWidget(this->savePlaylist, 5, 1 ,1, 1);
  gridLayout->addWidget(this->loadPlaylist, 6, 1 ,1, 1);
  gridLayout->addWidget(this->remove, 7, 1, 1, 1);
  gridLayout->addWidget(this->removeAll, 8, 1, 1, 1);

  this->setLayout(gridLayout);
}

void MainWindow::mediaPlayerPositionChanged(qint64 position)
{
  if(position != 0 and this->musicPlayer->getMediaPlayer()->duration() != 0) {
    this->musicSlider->setValue((this->musicSlider->maximum() - this->musicSlider->minimum()) * position / this->musicPlayer->getMediaPlayer()->duration());
  }
}

void MainWindow::musicSliderMoved(int value)
{
  this->musicPlayer->getMediaPlayer()->setPosition((this->musicPlayer->getMediaPlayer()->duration() * value) / (this->musicSlider->maximum() - this->musicSlider->minimum()));
}

void MainWindow::musicSliderPressed()
{
  QObject::disconnect(this->musicPlayer->getMediaPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(mediaPlayerPositionChanged(qint64)));
}

void MainWindow::musicSliderReleased()
{
  QObject::connect(this->musicPlayer->getMediaPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(mediaPlayerPositionChanged(qint64)));
}

void MainWindow::volumeSliderMoved(int value)
{
  this->musicPlayer->getMediaPlayer()->setVolume(value);
}

void MainWindow::volumeValueChanged(int value)
{
  this->musicPlayer->getMediaPlayer()->setVolume(value);
}

void MainWindow::trackListItemDoubleClicked(QListWidgetItem* item)
{
  for(int i {0}; i < this->trackList->count(); i++) {
    if(item->text() == this->trackList->item(i)->text()) {
      this->musicPlayer->getMediaPlaylist()->setCurrentIndex(i);
      this->musicPlayer->getMediaPlayer()->play();

      this->play->hide();
      this->stop->show();

      break;
    }
  }
}

void MainWindow::playClicked()
{
  this->musicPlayer->getMediaPlayer()->play();

  this->play->hide();
  this->stop->show();
}

void MainWindow::stopClicked()
{
  this->musicPlayer->getMediaPlayer()->pause();

  this->stop->hide();
  this->play->show();
}

void MainWindow::previousClicked()
{
  this->musicPlayer->getMediaPlaylist()->previous();

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    this->play->show();
    this->stop->hide();
    this->musicSlider->setValue(0);
  } else if(this->musicPlayer->getMediaPlaylist()->currentIndex() == 0 || this->musicPlayer->getMediaPlaylist()->currentIndex() == this->trackList->count() - 1) {
    this->musicPlayer->getMediaPlayer()->play();
    this->play->hide();
    this->stop->show();
  } else {
    this->musicPlayer->getMediaPlayer()->play();
  }

  this->trackList->setCurrentRow(this->musicPlayer->getMediaPlaylist()->currentIndex());
}

void MainWindow::nextClicked()
{
  this->musicPlayer->getMediaPlaylist()->next();

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    this->play->show();
    this->stop->hide();
    this->musicSlider->setValue(0);
  } else if(this->musicPlayer->getMediaPlaylist()->currentIndex() == 0 || this->musicPlayer->getMediaPlaylist()->currentIndex() == this->trackList->count() - 1) {
    this->musicPlayer->getMediaPlayer()->play();
    this->play->hide();
    this->stop->show();
  } else {
    this->musicPlayer->getMediaPlayer()->play();
  }

  this->trackList->setCurrentRow(this->musicPlayer->getMediaPlaylist()->currentIndex());
}

void MainWindow::addSongClicked()
{
  QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Select Track to Import"));

  for(QStringList::iterator filename {filenames.begin()}; filename != filenames.end(); filename++) {
    QFileInfo fileInfo {*filename};

    QDir dir {fileInfo.absoluteDir()};
    QStringList data {dir.filePath(*filename).split('/')};

    QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
    title = title.left(title.length() - 4);
    Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

    this->playlist->addTrack(track);

    this->musicPlayer->addTrack(track);

    this->trackList->addItem(track.getTitle());
  }

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    this->musicPlayer->getMediaPlaylist()->setCurrentIndex(0);
  }
}

void MainWindow::addDirectoryClicked()
{
  QString directory = QFileDialog::getExistingDirectory(this, tr("Select Directory for Tracks to Import"));

  if(not directory.isEmpty()) {
    QDir dir {directory};

    QStringList filenames = dir.entryList(QStringList() << "*.mp3", QDir::Files);

    for(QStringList::iterator filename {filenames.begin()}; filename != filenames.end(); ++filename) {
      QFileInfo fileInfo {*filename};
      QStringList data {dir.filePath(*filename).split('/')};

      QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
      title = title.left(title.length() - 4);

      Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

      this->playlist->addTrack(track);

      this->musicPlayer->addTrack(track);

      this->trackList->addItem(track.getTitle());
    }

    if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
      this->musicPlayer->getMediaPlaylist()->setCurrentIndex(0);
    }
  }
}

void MainWindow::removeClicked()
{
  if(this->trackList->currentRow() != -1) {
    this->trackList->takeItem(this->trackList->currentRow());
    this->trackList->update();

    for(QVector<Track>::iterator track {this->playlist->getTracks()->begin()}; track != this->playlist->getTracks()->end(); ++track) {
      if(track->getTitle() == this->trackList->currentItem()->text()) {
        this->musicPlayer->removeTrack(*track);
        this->playlist->removeTrack(*track);

        break;
      }
    }
  }
}

void MainWindow::removeAllClicked()
{
  this->trackList->clear();
  this->musicPlayer->removeAllTracks();
  this->playlist->removeAllTracks();
}

void MainWindow::savePlaylistClicked()
{
  SavePlaylistWindow* savePlaylist = new SavePlaylistWindow(this->stackedWidget, this->playlist);

  this->stackedWidget->getQStackedWidget()->addWidget(savePlaylist);
  this->stackedWidget->getQStackedWidget()->setCurrentWidget(savePlaylist);
}

void MainWindow::loadPlaylistClicked()
{
  LoadPlaylistWindow* loadPlaylist = new LoadPlaylistWindow(this->stackedWidget);

  QObject::connect(loadPlaylist, SIGNAL(playlistLoaded(QString)), this, SLOT(playlistLoaded(QString)));

  this->stackedWidget->getQStackedWidget()->addWidget(loadPlaylist);
  this->stackedWidget->getQStackedWidget()->setCurrentWidget(loadPlaylist);
}

void MainWindow::playlistLoaded(QString playlistName)
{
  QString path {QDir::currentPath() + "/tracks/"};

  QDir dir {path + playlistName};

  QStringList filenames = dir.entryList(QStringList() << "*.mp3", QDir::Files);
  this->trackList->addItems(filenames);

  for(QStringList::iterator filename {filenames.begin()}; filename != filenames.end(); ++filename) {
    QFileInfo fileInfo {*filename};
    QStringList data {dir.filePath(*filename).split('/')};

    QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
    title = title.left(title.length() - 4);

    Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

    this->playlist->addTrack(track);
    this->musicPlayer->addTrack(track);
  }
}
