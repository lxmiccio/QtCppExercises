#ifndef CARTWINDOW_H
#define CARTWINDOW_H

#include <QLabel>
#include <QVector>
#include <QWidget>

#include "game.h"
#include "stackedwidget.h"

class CartWindow : public QWidget
{
  Q_OBJECT

protected:
  StackedWidget* stackedWidget;
  QVector<Game>* cart;
  QVector<QLabel*>* games;

public:
  CartWindow(StackedWidget* stackedWidget, QVector<Game>* cart, QWidget* parent = 0);
};

#endif // CARTWINDOW_H
