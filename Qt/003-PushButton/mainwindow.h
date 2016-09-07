#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
  Q_OBJECT

  private:
    QPushButton *button;

  public:
    explicit MainWindow(QWidget *parent = 0);

  private slots:
    void buttonClicked();
    void buttonClickedAgain();
};

#endif // MAINWINDOW_H
