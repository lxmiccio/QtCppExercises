#ifndef LOADPLAYLISTWINDOW_H
#define LOADPLAYLISTWINDOW_H

#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

#include "playlist.h"
#include "stackedwidget.h"

class LoadPlaylistWindow : public QWidget
{
  Q_OBJECT

protected:
  StackedWidget* stackedWidget;
  QListWidget* playlists;
  QPushButton* goBack;
  QPushButton* loadPlaylist;

public:
  LoadPlaylistWindow(StackedWidget* stackedWidget, QWidget* parent = 0);

public slots:
  void loadPlaylistClicked();
};

#endif // LOADPLAYLISTWINDOW_H
