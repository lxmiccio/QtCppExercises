#include "loadplaylistwindow.h"

#include "QDebug"
#include "QDir"
#include "QListWidgetItem"

#include "playlist.h"

LoadPlaylistWindow::LoadPlaylistWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  this->playlists = new QListWidget();
  this->playlists->addItems(Playlist::getAllPlaylists(QDir::currentPath() + "/tracks/"));

  this->goBack = new QPushButton("Go Back");
  QObject::connect(this->goBack, SIGNAL(clicked()), this->stackedWidget, SLOT(previousView()));

  this->loadPlaylist = new QPushButton("Load");
  QObject::connect(this->loadPlaylist, SIGNAL(clicked()), this, SLOT(loadPlaylistClicked()));

  QGridLayout* gridLayout = new QGridLayout();

  gridLayout->addWidget(this->playlists, 0, 0, 1, 2);
  gridLayout->addWidget(this->goBack, 1, 0, 1, 1);
  gridLayout->addWidget(this->loadPlaylist, 1, 1, 1, 1);

  setLayout(gridLayout);
}

void LoadPlaylistWindow::loadPlaylistClicked()
{
  Playlist p = Playlist();

  if(this->playlists->currentRow() != -1) {
    QString path {QDir::currentPath() + "/tracks/"};

    QDir dir {path + this->playlists->currentItem()->text()};

    QStringList filenames = dir.entryList(QStringList() << "*.mp3", QDir::Files);

    for(QStringList::iterator filename {filenames.begin()}; filename != filenames.end(); ++filename) {
      QFileInfo fileInfo {*filename};
      QStringList data {dir.filePath(*filename).split('/')};

      QString title = QString(data.at(data.length() - Playlist::TITLE_INDEX)).mid(5);
      title = title.left(title.length() - 4);

      Track track = Track(QString(data.at(data.length() - Playlist::ARTIST_INDEX)), QString(data.at(data.length() - Playlist::ALBUM_INDEX)), title, QString(data.at(data.length() - Playlist::TITLE_INDEX)), dir.filePath(*filename), QUrl::fromLocalFile(fileInfo.absoluteFilePath()));

      p.addTrack(track);
    }
  }
}
