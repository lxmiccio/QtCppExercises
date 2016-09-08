#ifndef GAME_H
#define GAME_H

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

public:
  Game();
  Game(QString* title, double price, int amount, QStringList* genres, QStringList* platforms);

  QString* getTitle() { return this->title; }
  double getPrince() { return this->price; }
  int getAmount() { return this->amount; }
  QStringList* getGenres() { return this->genres; }
  QStringList* getPlatforms() { return this->platforms; }

  void setAmount(int amount) { this->amount = amount; }
};

#endif // GAME_H
