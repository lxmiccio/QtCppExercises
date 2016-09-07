#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QCoreApplication::setApplicationName("003-PushButton");

  MainWindow mainWindow;
  mainWindow.showMaximized();

  return app.exec();
}
