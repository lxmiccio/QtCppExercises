#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  button = new QPushButton("Hello World", this);
  button->setGeometry(QRect(QPoint(10, 10), QSize(200, 50)));

  connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void MainWindow::buttonClicked()
{
  button->setText("You Clicked me");
  button->resize(QSize(300, 75));

  disconnect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(button, SIGNAL(clicked()), this, SLOT(buttonClickedAgain()));
}

void MainWindow::buttonClickedAgain()
{
  button->setText("You Clicked me Again");
  button->resize(QSize(300, 75));
}
