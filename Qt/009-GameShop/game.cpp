#include "game.h"

Game::Game()
{

}

Game::Game(QString* title, double price, int amount, QStringList* genres,QStringList* platforms)
{
  this->title = title;
  this->price = price;
  this->amount = amount;
  this->genres = genres;
  this->platforms = platforms;
}
