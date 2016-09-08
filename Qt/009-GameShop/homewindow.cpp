#include "homewindow.h"

#include <QGridLayout>
#include <QStringList>
#include <QPixmap>

HomeWindow::HomeWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  QPixmap image {"qt_logo.png"};

  this->logo = new QLabel();
  this->logo->setAlignment(Qt::AlignCenter);
  this->logo->setPixmap(image);

  this->genres = new QComboBox();
  this->genres->addItems(*this->stackedWidget->getGenres());

  this->platforms = new QComboBox();
  this->platforms->addItems(*this->stackedWidget->getPlatforms());

  this->games = new QComboBox();
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    this->games->addItem(*game->getTitle());
  }

  this->amount = new QComboBox();

  this->price = new QLabel("Price: € 0");
  this->price->setAlignment(Qt::AlignCenter);

  this->cover = new QLabel();
  this->cover->setAlignment(Qt::AlignCenter);
  Game game {stackedWidget->getGames()->at(0)};
  this->cover->setPixmap(game.getPixmap());

  this->addToCart = new QPushButton("Add to Cart");

  this->goToCart = new QPushButton("Go to Cart");

  QGridLayout* gridLayout = new QGridLayout();
  gridLayout->addWidget(this->logo, 0, 0, 1, 2);
  gridLayout->addWidget(this->genres, 1, 0, 1, 1);
  gridLayout->addWidget(this->platforms, 1, 1, 1, 1);
  gridLayout->addWidget(this->games, 2, 0, 1, 1);
  gridLayout->addWidget(this->amount, 3, 0, 1, 1);
  gridLayout->addWidget(this->price, 4, 0, 1, 1);
  gridLayout->addWidget(this->cover, 2, 1, 4, 1);
  gridLayout->addWidget(this->addToCart, 5, 0, 1, 1);
  gridLayout->addWidget(this->goToCart, 6, 0, 1, 1);

  this->setLayout(gridLayout);
}
