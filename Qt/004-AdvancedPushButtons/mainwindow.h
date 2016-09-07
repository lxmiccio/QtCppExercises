#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  QPushButton* button1;
  QPushButton* button2;
  QPushButton* button3;
  int button1ClickCount;
  int button2ClickCount;
  int button3ClickCount;

public:
  explicit MainWindow(QWidget *parent = 0);

private slots:
  void button1Clicked();
  void button2Clicked();
  void button3Clicked();
};

#endif // MAINWINDOW_H
