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
  QVector<Game>* games;
  QStringList* genres;
  QStringList* platforms;
  QStackedWidget* qStackedWidget;

public:
  StackedWidget(QVector<Game>* games, QStringList* genres, QStringList* platforms, QWidget* parent = 0);

  QVector<Game>* getGames() { return this->games; }
  QStringList* getGenres() { return this->genres; }
  QStringList* getPlatforms() { return this->platforms; }
  QStackedWidget* getQStackedWidget() { return this->qStackedWidget; }

public slots:
  void previousView();
};

#endif // STACKWIDGET_H
