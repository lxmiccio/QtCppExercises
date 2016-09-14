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
  QVector<Game>* selectedGames;

public:
  HomeWindow(StackedWidget* stackedWidget, QWidget* parent = 0);

  // void resizeEvent(QResizeEvent* event ) { };

public slots:
  void filterChanged();
  void gameChanged(QString title);
  void amountChanged(int index);
  void addToCartClicked();
  void goToCartClicked();
};

#endif // HOMEWINDOW_H
