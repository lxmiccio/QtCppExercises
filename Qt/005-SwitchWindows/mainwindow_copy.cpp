#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  button1 = new QPushButton("Button1", this);
  button1->setGeometry(QRect(QPoint(10, 10), QSize(100, 30)));

  connect(button1, SIGNAL(clicked()), this, SLOT(button1Clicked()));
}

MainWindow::button1Clicked()
{
//???
}
