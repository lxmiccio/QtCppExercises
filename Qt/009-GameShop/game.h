#ifndef GAME_H
#define GAME_H

#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QVector>

class Game
{
protected:
  QString* title;
  double price;
  int amount;
  QStringList* genres;
  QStringList* platforms;
  QPixmap pixmap;

public:
  Game();
  Game(QString* title, double price, int amount, QStringList* genres, QStringList* platforms, QPixmap pixmap);

  QString* getTitle() { return this->title; }
  double getPrince() { return this->price; }
  int getAmount() { return this->amount; }
  QStringList* getGenres() { return this->genres; }
  QStringList* getPlatforms() { return this->platforms; }
  QPixmap getPixmap() {return this->pixmap; }

  void setAmount(int amount) { this->amount = amount; }
};

#endif // GAME_H
