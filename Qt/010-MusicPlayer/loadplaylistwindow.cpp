#include "loadplaylistwindow.h"

#include "QDir"

LoadPlaylistWindow::LoadPlaylistWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  this->playlists = new QListWidget();
  this->playlists->addItems(Playlist::getAllPlaylists(QDir::currentPath() + "/tracks/"));

  this->goBack = new QPushButton("Go Back");
  QObject::connect(this->goBack, SIGNAL(clicked()), this->stackedWidget, SLOT(previousView()));

  this->loadPlaylist = new QPushButton("Load");

  QGridLayout* gridLayout = new QGridLayout();

  gridLayout->addWidget(this->playlists, 0, 0, 1, 2);
  gridLayout->addWidget(this->goBack, 1, 0, 1, 1);
  gridLayout->addWidget(this->loadPlaylist, 1, 1, 1, 1);

  setLayout(gridLayout);
}

void LoadPlaylistWindow::loadPlaylistClicked()
{
}
