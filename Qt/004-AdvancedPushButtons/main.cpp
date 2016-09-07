#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QCoreApplication::setApplicationName("004-AdvancedPushButton");

  MainWindow w;
  w.show();

  return a.exec();
}
