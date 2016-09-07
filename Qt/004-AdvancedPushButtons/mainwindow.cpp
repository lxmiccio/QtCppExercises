#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  button1 = new QPushButton("Button1", this);
  button1->setGeometry(QRect(QPoint(10, 10), QSize(100, 30)));

  button2 = new QPushButton("Button2", this);
  button2->setGeometry(QRect(QPoint(120, 10), QSize(100, 30)));

  button3 = new QPushButton("Button3", this);
  button3->setGeometry(QRect(QPoint(10, 50), QSize(210, 30)));

  button1ClickCount = 0;
  button2ClickCount = 0;
  button3ClickCount = 0;

  connect(button1, SIGNAL(clicked()), this, SLOT(button1Clicked()));
  connect(button2, SIGNAL(clicked()), this, SLOT(button2Clicked()));
  connect(button3, SIGNAL(clicked()), this, SLOT(button3Clicked()));
}

void MainWindow::button1Clicked()
{
  button1->setText(QString("Clicked %1 times").arg(button1ClickCount));
  button1ClickCount++;
}

void MainWindow::button2Clicked()
{
  button1ClickCount++;
  button1->setText(QString("Clicked %1 times").arg(button1ClickCount));

  button2ClickCount++;
  button2->setText(QString("Clicked %1 times").arg(button2ClickCount));
}

void MainWindow::button3Clicked()
{
  button1ClickCount++;
  button1->setText(QString("Clicked %1 times").arg(button1ClickCount));

  button2ClickCount++;
  button2->setText(QString("Clicked %1 times").arg(button2ClickCount));

  button3ClickCount++;
  button3->setText(QString("Clicked %1 times").arg(button3ClickCount));
}
