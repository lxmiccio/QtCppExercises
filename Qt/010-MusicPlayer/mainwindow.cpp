#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QGridLayout>
#include <QString>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
  this->mediaPlayer = new QMediaPlayer(this);
  this->mediaPlaylist = new QMediaPlaylist(this->mediaPlayer);
  this->mediaPlayer->setPlaylist(this->mediaPlaylist);
  QObject::connect(this->mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(mediaPlayerPositionChanged(qint64)));

  this->musicSlider = new QSlider();
  this->musicSlider->setOrientation(Qt::Horizontal);
  this->musicSlider->setRange(0, 100);
  QObject::connect(this->musicSlider, SIGNAL(sliderMoved(int)), this, SLOT(musicSliderValueChanged(int)));

  this->listWidget = new QListWidget();

  this->play = new QPushButton("Play");
  QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(playClicked()));

  this->stop = new QPushButton("Stop");
  this->stop->hide();
  QObject::connect(this->stop, SIGNAL(clicked()), this, SLOT(stopClicked()));

  this->addSong = new QPushButton("Add Song");
  QObject::connect(this->addSong, SIGNAL(clicked()), this, SLOT(addSongClicked()));

  this->addDirectory = new QPushButton("Add Directory");
  QObject::connect(this->addDirectory, SIGNAL(clicked()), this, SLOT(addDirectoryClicked()));

  QGridLayout* gridLayout = new QGridLayout();
  gridLayout->addWidget(this->musicSlider, 0, 0, 1, 1);
  gridLayout->addWidget(this->listWidget, 1, 0, 3, 1);
  gridLayout->addWidget(this->play, 0, 1, 1, 1);
  gridLayout->addWidget(this->stop, 0, 1, 1, 1);
  gridLayout->addWidget(this->addSong, 1, 1, 1, 1);
  gridLayout->addWidget(this->addDirectory, 2, 1, 1, 1);

  this->setLayout(gridLayout);
}

void MainWindow::mediaPlayerPositionChanged(qint64 position)
{
  qDebug() << position;
  qDebug() << this->mediaPlayer->duration();
  if(position != 0 and this->mediaPlayer->duration() != 0) {
    qDebug() << (100 * position / this->mediaPlayer->duration());
    this->musicSlider->setValue(100 * position / this->mediaPlayer->duration());
    //this->progressBar->setFormat('%.02f%%' % (100 * progress / this->mediaPlayer->duration()));
  }
}

void MainWindow::musicSliderValueChanged(int value)
{
  qDebug() << "toveee";
  this->mediaPlayer->setPosition((this->mediaPlayer->duration() * value) / 100);
}

void MainWindow::playClicked()
{
  this->mediaPlayer->play();

  this->play->hide();
  this->stop->show();
}

void MainWindow::stopClicked()
{
  this->mediaPlayer->pause();

  this->stop->hide();
  this->play->show();
}

void MainWindow::addSongClicked()
{
  // TO DO
}

void MainWindow::addDirectoryClicked()
{
  QString directory = QFileDialog::getExistingDirectory(this, tr("Select Directory for Files to Import"));

  if(not directory.isEmpty()) {
    QDir dir {directory};
    QStringList filenames = dir.entryList(QStringList() << "*.mp3", QDir::Files);
    QList<QMediaContent> files;

    for(QStringList::iterator filename {filenames.begin()}; filename != filenames.end(); filename++) {
      files.push_back(QUrl::fromLocalFile(dir.path() + "/" + *filename));
      QFileInfo fileInfo(*filename);
      this->listWidget->addItem(fileInfo.fileName());
    }
    this->mediaPlaylist->addMedia(files);
    this->listWidget->setCurrentRow(this->mediaPlaylist->currentIndex() != -1 ? this->mediaPlaylist->currentIndex() : 0);
  }
}
