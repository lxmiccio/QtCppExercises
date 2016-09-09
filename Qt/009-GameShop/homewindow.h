#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QWidget>

#include <stackedwidget.h>

class HomeWindow : public QWidget
{
    Q_OBJECT

protected:
  StackedWidget* stackedWidget;
  QLabel* logo;
  QComboBox* genres;
  QComboBox* platforms;
  QComboBox* games;
  QComboBox* amount;
  QLabel* price;
  QLabel* cover;
  QPushButton* addToCart;
  QPushButton* goToCart;
  QVector<Game>* cart;

public:
  HomeWindow(StackedWidget* stackedWidget, QWidget* parent = 0);

public slots:
  void filterChanged();
  void gameChanged();
  void amountChanged();
  void addToCartClicked();
};

#endif // HOMEWINDOW_H
