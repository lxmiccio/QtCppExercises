#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QGridLayout>
#include <QMediaMetaData>
#include <QString>
#include <QStringList>


#include <QStandardItem>
#include <QHeaderView>
#include <QList>

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include "gui/imageutils.h"

#include "gui/imageloader.h"
#include "loadplaylistwindow.h"
#include "saveplaylistwindow.h"

#include "table/trackitem.h"

MainWindow::MainWindow(StackedWidget *stackedWidget, QWidget *parent) : QWidget(parent)
{
  this->items = QVector<TrackItem*>();

  this->stackedWidget = stackedWidget;

  this->musicPlayer = new MusicPlayer();
  QObject::connect(this->musicPlayer->getMediaPlayer(), SIGNAL(positionChanged(qint64)), this, SLOT(mediaPlayerPositionChanged(qint64)));
  QObject::connect(this->musicPlayer->getMediaPlaylist(), SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(onCurrentMediaChanged(QMediaContent)));

  this->playlist = new Playlist();

  this->audioControls = new AudioControls();
  this->audioControls->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  QObject::connect(this->audioControls, SIGNAL(fastBackwardClicked()), this, SLOT(onFastBackwardClicked()));
  QObject::connect(this->audioControls, SIGNAL(backwardClicked()), this, SLOT(onBackwardClicked()));
  QObject::connect(this->audioControls, SIGNAL(playClicked()), this, SLOT(onPlayClicked()));
  QObject::connect(this->audioControls, SIGNAL(pauseClicked()), this, SLOT(onPauseClicked()));
  QObject::connect(this->audioControls, SIGNAL(forwardClicked()), this, SLOT(onForwardClicked()));
  QObject::connect(this->audioControls, SIGNAL(fastForwardClicked()), this, SLOT(onFastForwardClicked()));
  QObject::connect(this->audioControls, SIGNAL(musicSliderMoved(int, int, int)), this, SLOT(onMusicSliderMoved(int, int, int)));
  QObject::connect(this->audioControls, SIGNAL(shuffleClicked(AC::ShuffleMode_t)), this, SLOT(onShuffleClicked(AC::ShuffleMode_t)));
  QObject::connect(this->audioControls, SIGNAL(repeatClicked(AC::RepeatMode_t)), this, SLOT(onRepeatClicked(AC::RepeatMode_t)));
  QObject::connect(this->audioControls, SIGNAL(volumeClicked(AC::VolumeMode_t)), this, SLOT(onVolumeClicked(AC::VolumeMode_t)));

  QObject::connect(this, SIGNAL(currentMediaChanged(Track&)), this->audioControls, SLOT(onCurrentMediaChanged(Track&)));
  QObject::connect(this, SIGNAL(positionChanged(qint64, qint64)), this->audioControls, SLOT(onPositionChanged(qint64, qint64)));

  //this->trackList = new QListWidget();
  //QObject::connect(this->trackList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(trackListItemDoubleClicked(QListWidgetItem*)));

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

  gridLayout->setSpacing(0);
  gridLayout->setMargin(0);
  //gridLayout->addWidget(this->trackList, 2, 0, 6, 1);


  this->setLayout(gridLayout);


  model = new QStandardItemModel(0,0,this);
  // Generate data

  // Attach (tie) the model to the view
  //ui->tableView->setModel(model);
  //ui->tableView->setShowGrid(false);
  //ui->tableView->horizontalHeader()->setVisible(false);
  //ui->tableView->verticalHeader()->setVisible(false);
  //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableView = new TableView();
  tableView->setStyleSheet("QHeaderView {background-color: transparent;}");
  //tableView->hideColumn(0);
  tableView->horizontalHeader()->hide();
  tableView->verticalHeader()->hide();
  tableView->setModel(model);
  tableView->setShowGrid(false);
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


  this->delegate = new MyDelegate(tableView);
  tableView->setItemDelegate(delegate);
  //ui->tableView->setItemDelegate(myDelegate);

  //connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex &)));
  connect(tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex &)));


  // Tie the View with the new MyDelegate instance
  // If we don not set this, it will use default delegate
  //ui->tableView->resizeColumnsToContents();
  //ui->tableView->setFixedSize(100,100);

  QObject::connect(this->tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(trackListItemDoubleClicked(const QModelIndex&)));

  gridLayout->addWidget(tableView,0,0,1,1);
  gridLayout->addWidget(this->audioControls, 3, 0, 1, 1);
  gridLayout->addWidget(this->addSong,1,0,1,1);
  gridLayout->addWidget(this->remove,2,0,1,1);
  this->setLayout(gridLayout);

  this->musicLibrary = new MusicLibrary();
}

void MainWindow::onFastBackwardClicked()
{
  this->musicPlayer->getMediaPlaylist()->previous();

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    this->audioControls->showPause(false);
    this->audioControls->showPlay(true);
  }
}

void MainWindow::onBackwardClicked()
{
  this->musicPlayer->getMediaPlayer()->setPosition(0);
}

void MainWindow::onPlayClicked()
{
  this->musicPlayer->getMediaPlayer()->play();
}

void MainWindow::onPauseClicked()
{
  this->musicPlayer->getMediaPlayer()->pause();
}

void MainWindow::onForwardClicked()
{
  this->musicPlayer->getMediaPlaylist()->next();
}

void MainWindow::onFastForwardClicked()
{
  this->musicPlayer->getMediaPlaylist()->setCurrentIndex(this->musicPlayer->getMediaPlaylist()->currentIndex() + 2);
}

void MainWindow::onMusicSliderMoved(int position, int minimum, int maximum)
{
  if(maximum - minimum != 0) {
    this->musicPlayer->getMediaPlayer()->setPosition((this->musicPlayer->getMediaPlayer()->duration() * position) / (maximum - minimum));
  }
}

void MainWindow::onShuffleClicked(AC::ShuffleMode_t shuffleMode)
{
  switch (shuffleMode)
  {
  case AC::SHUFFLE_OFF: {
    this->musicPlayer->getMediaPlaylist()->setPlaybackMode(QMediaPlaylist::Sequential);
    break;
  }

  case AC::SHUFFLE_ON: {
    this->musicPlayer->getMediaPlaylist()->setPlaybackMode(QMediaPlaylist::Random);
    break;
  }

  default: {
    break;
  }
  }
}

void MainWindow::onRepeatClicked(AC::RepeatMode_t repeatMode)
{
  switch (repeatMode)
  {
  case AC::REPEAT_NONE: {
    this->musicPlayer->getMediaPlaylist()->setPlaybackMode(QMediaPlaylist::Sequential);
    break;
  }

  case AC::REPEAT_ONE: {
    this->musicPlayer->getMediaPlaylist()->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    break;
  }

  case AC::REPEAT_ALL: {
    this->musicPlayer->getMediaPlaylist()->setPlaybackMode(QMediaPlaylist::Loop);
    break;
  }

  default: {
    break;
  }
  }
}

void MainWindow::onVolumeClicked(AC::VolumeMode_t volumeMode)
{
  switch (volumeMode)
  {
  case AC::VOLUME_MUTED: {
    this->musicPlayer->getMediaPlayer()->setMuted(true);
    break;
  }

  case AC::VOLUME_NOT_MUTED: {
    this->musicPlayer->getMediaPlayer()->setMuted(false);
    break;
  }

  default: {
    break;
  }
  }
}

void MainWindow::onCurrentMediaChanged(QMediaContent mediaContent)
{
  QString filename {mediaContent.canonicalUrl().toString().split('/').last()};

  for(QVector<Track>::iterator track {this->playlist->getTracks()->begin()}; track != this->playlist->getTracks()->end(); ++track) {
    /*if(track->getFilename() == filename) {
      emit this->currentMediaChanged(*track);
    }*/
  }
}




void MainWindow::mediaPlayerPositionChanged(qint64 position)
{
  emit this->positionChanged(position, this->musicPlayer->getMediaPlayer()->duration());
}

void MainWindow::musicSliderMoved(int value)
{
  value++;
  //this->musicPlayer->getMediaPlayer()->setPosition((this->musicPlayer->getMediaPlayer()->duration() * value) / (this->musicSlider->maximum() - this->musicSlider->minimum()));
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

void MainWindow::trackListItemDoubleClicked(const QModelIndex& index)
{
  qDebug() << index.row();
  qDebug() << this->items.at(index.row())->getTrack()->getTitle();
  /*for(int i {0}; i < this->trackList->count(); i++) {
    if(item->text() == this->trackList->item(i)->text()) {
      this->musicPlayer->getMediaPlaylist()->setCurrentIndex(i);
      this->musicPlayer->getMediaPlayer()->play();

      //this->play->hide();
      //this->stop->show();

      break;
    }
  }*/
}

void MainWindow::playClicked()
{
  this->musicPlayer->getMediaPlayer()->play();

  //this->play->hide();
  //this->stop->show();
}

void MainWindow::stopClicked()
{
  this->musicPlayer->getMediaPlayer()->pause();

  //this->stop->hide();
  //this->play->show();
}

void MainWindow::previousClicked()
{
  this->musicPlayer->getMediaPlaylist()->previous();

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    //this->play->show();
    //this->stop->hide();
    //this->musicSlider->setValue(0);
  } else if(this->musicPlayer->getMediaPlaylist()->currentIndex() == 0 || this->musicPlayer->getMediaPlaylist()->currentIndex() == this->trackList->count() - 1) {
    this->musicPlayer->getMediaPlayer()->play();
    //this->play->hide();
    //this->stop->show();
  } else {
    this->musicPlayer->getMediaPlayer()->play();
  }

  this->trackList->setCurrentRow(this->musicPlayer->getMediaPlaylist()->currentIndex());
}

void MainWindow::nextClicked()
{
  this->musicPlayer->getMediaPlaylist()->next();

  if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
    //this->play->show();
    //this->stop->hide();
    //this->musicSlider->setValue(0);
  } else if(this->musicPlayer->getMediaPlaylist()->currentIndex() == 0 || this->musicPlayer->getMediaPlaylist()->currentIndex() == this->trackList->count() - 1) {
    this->musicPlayer->getMediaPlayer()->play();
    //this->play->hide();
    //this->stop->show();
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

    QVariantMap tags = TagManager::readTags(fileInfo).toMap();
    Track* t = this->musicLibrary->addTrack(tags);
    if(t) {
      TrackItem* ti = new TrackItem(t);
      this->model->appendRow(ti->getItems());

      this->musicLibrary->debug();
      this->items.push_back(ti);
    }
    //Track track = Track(tags);

    //l->setPixmap(ImageUtils::stringToImage(QImage("images/white.png"), track.getTitle()));




    //qDebug() << track.getTitle();
    //qDebug() << track.getAlbum()->getTitle();

    QDir dir {fileInfo.absoluteDir()};
    QStringList data {dir.filePath(*filename).split('/')};

    QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
    title = title.left(title.length() - 4);
    //Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl(fileInfo.absoluteFilePath()));

    //this->playlist->addTrack(track);

    //this->musicPlayer->addTrack(track);

    //this->trackList->addItem(track.getTitle());
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

      QDir dir {fileInfo.absoluteDir()};
      QStringList data {dir.filePath(*filename).split('/')};

      QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
      title = title.left(title.length() - 4);
      //Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl(fileInfo.absoluteFilePath()));

      //this->playlist->addTrack(track);

      //this->musicPlayer->addTrack(track);

      //this->trackList->addItem(track.getTitle());
    }

    if(this->musicPlayer->getMediaPlaylist()->currentIndex() == -1) {
      this->musicPlayer->getMediaPlaylist()->setCurrentIndex(0);
    }
  }
}

void MainWindow::removeClicked()
{
  QModelIndexList list = this->tableView->selectionModel()->selectedRows();

  for(qint16 i = list.size() - 1; i >= 0; --i) {
    this->items.removeAt(list.at(i).row());
    this->model->removeRow(list.at(i).row());
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

    //Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl(fileInfo.absoluteFilePath()));

    //this->playlist->addTrack(track);
    //this->musicPlayer->addTrack(track);
  }
}
