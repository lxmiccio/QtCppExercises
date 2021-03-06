#ifndef CARTWINDOW_H
#define CARTWINDOW_H

#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QWidget>

#include "game.h"
#include "stackedwidget.h"

class CartWindow : public QWidget
{
  Q_OBJECT

protected:
  StackedWidget* stackedWidget;
  QVector<Game>* selectedGames;
  QVector<QLabel*>* games;
  QPushButton* goBack;

public:
  CartWindow(StackedWidget* stackedWidget, QVector<Game>* selectedGames, QWidget* parent = 0);
};

#endif // CARTWINDOW_H
