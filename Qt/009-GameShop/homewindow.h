#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include <stackedwidget.h>

class HomeWindow : public QWidget
{
protected:
  StackedWidget* stackedWidget;
  QLabel* logo;
  QComboBox* cmbGenres;
  QStringList* genres;
  QComboBox* cmbPlatforms;
  QStringList* platforms;
  QComboBox* cmbGames;
  QStringList* games;
  QComboBox* amount;
  QLabel* price;
  QPushButton* addToCart;
  QPushButton* goToCart;

public:
  HomeWindow(StackedWidget* stackedWidget, QWidget* parent = 0);

public slots:
  // TO DO
};

#endif // HOMEWINDOW_H
