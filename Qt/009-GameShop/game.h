#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QVector>

class Game
{
protected:
  QString* title;
  double price;
  int amount;

  QVector<QString>* genres;
  QVector<QString>* platforms;

public:
  Game();
  Game(QString* title, double price, int amount, QVector<QString>* genres, QVector<QString>* platforms);

  QString* getTitle() { return this->title; }
  double getPrince() { return this->price; }
  int getAmount() { return this->amount; }
  QVector<QString>* getGenres() { return this->genres; }
  QVector<QString>* getPlatforms() { return this->platforms; }

  void setAmount(int amount) { this->amount = amount; }
};

#endif // GAME_H
