#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QStackedWidget>
#include <QVector>

#include <game.h>

class StackedWidget : public QMainWindow
{
  Q_OBJECT

protected:
  QStackedWidget* qStackedWidget;
  QVector<Game>* games;
  QStringList* genres;
  QStringList* platforms;

public:
  StackedWidget(QVector<Game>* games, QStringList* genres, QStringList* platforms, QWidget* parent = 0);

  QStackedWidget* getQStackedWidget() { return this->qStackedWidget; }
  QVector<Game>* getGames() { return this->games; }
  QStringList* getGenres() { return this->genres; }
  QStringList* getPlatforms() { return this->platforms; }

public slots:
  void goToNewWindow(int index);
  void returnToPreviousWindow();
};

#endif // STACKWIDGET_H
