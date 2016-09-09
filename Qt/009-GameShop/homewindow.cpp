#include "homewindow.h"

#include <QGridLayout>
#include <QPixmap>
#include <QSizePolicy>
#include <QStringList>
#include <QDebug>

#include <cartwindow.h>

#define DEBUG 1

HomeWindow::HomeWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  QPixmap image {"qt_logo.png"};

  this->logo = new QLabel();
  this->logo->setAlignment(Qt::AlignCenter);
  this->logo->setPixmap(image);

  this->genres = new QComboBox();
  this->genres->addItem("All Genres");
  this->genres->addItems(*this->stackedWidget->getGenres());

  //QGridLayout::setContentsMargins (10, 10, 10, 10 );

//  QSizePolicy* genresSizePolicy = new QSizePolicy();
//  QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
//  spLeft.setHorizontalStretch(1);
//  left->setSizePolicy(spLeft);


  QObject::connect(this->genres, SIGNAL(currentIndexChanged(int)), this, SLOT(filterChanged()));

  this->platforms = new QComboBox();
  this->platforms->setContentsMargins(10, 10, 10, 10);
  this->platforms->addItem("All Platforms");
  this->platforms->addItems(*this->stackedWidget->getPlatforms());
  QObject::connect(this->platforms, SIGNAL(currentIndexChanged(int)), this, SLOT(filterChanged()));

  this->games = new QComboBox();
  this->games->addItem("Games");
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    this->games->addItem(*game->getTitle());
  }
  QObject::connect(this->games, SIGNAL(currentIndexChanged(int)), this, SLOT(gameChanged()));

  this->amount = new QComboBox();
  QObject::connect(this->amount, SIGNAL(currentIndexChanged(int)), this, SLOT(amountChanged()));

  this->price = new QLabel("Price: € 0");
  this->price->setContentsMargins(10, 10, 10, 10);
  this->price->setAlignment(Qt::AlignCenter);

  this->cover = new QLabel();
  this->cover->setAlignment(Qt::AlignCenter);

  this->addToCart = new QPushButton("Add to Cart");
  QObject::connect(this->addToCart, SIGNAL(clicked()), this, SLOT(addToCartClicked()));

  this->goToCart = new QPushButton("Go to Cart");
  QObject::connect(this->goToCart, SIGNAL(clicked()), this, SLOT(goToCartClicked()));

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

  this->cart = new QVector<Game>();
}

void HomeWindow::filterChanged()
{
  QStringList* gamesList = new QStringList();

  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    bool isSelectedGenre {false};
    bool isForSelectedPlatform {false};

    if(this->genres->currentIndex() == 0) {
      isSelectedGenre = true;
    } else {
      for(QStringList::iterator genre {game->getGenres()->begin()}; genre != game->getGenres()->end(); genre++) {
        if(*genre == this->genres->currentText()) {
          isSelectedGenre = true;
        }
      }
    }

    if(this->platforms->currentIndex() == 0) {
      isForSelectedPlatform = true;
    } else  {
      for(QStringList::iterator platform {game->getPlatforms()->begin()}; platform != game->getPlatforms()->end(); platform++) {
        if(*platform == this->platforms->currentText()) {
          isForSelectedPlatform = true;
        }
      }
    }

    if(isSelectedGenre and isForSelectedPlatform) {
      gamesList->push_back(*game->getTitle());
    }
  }

  this->games->clear();
  this->games->addItem("Games");
  this->games->addItems(*gamesList);
}

void HomeWindow::gameChanged()
{
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    if(*game->getTitle() == this->games->currentText()) {
      QStringList* numbers = new QStringList();

      for(int i = 1; i <= game->getAmount(); i++) {
        numbers->push_back(QString("%1").arg(i));
      }

      this->amount->clear();
      this->amount->addItems(*numbers);

      this->price->setText(QString("Price: € %1").arg(game->getPrice()));

      this->cover->setPixmap(game->getPixmap());
    }
  }
}

void HomeWindow::amountChanged()
{
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    if(*game->getTitle() == this->games->currentText()) {
      this->price->setText(QString("Price: € %1").arg(game->getPrice() * (this->amount->currentIndex()+ 1)));
    }
  }
}

void HomeWindow::addToCartClicked()
{
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    if(*game->getTitle() == this->games->currentText()) {
      bool found {false};

      for(QVector<Game>::iterator iter {this->cart->begin()}; iter != this->cart->end(); iter++) {
        if(*iter->getTitle() == *game->getTitle()) {
          game->setAmount(game->getAmount() - (amount->currentIndex() + 1));
          iter->setAmount(iter->getAmount() + amount->currentIndex() + 1);

          found = true;
        }
      }

      if(not found) {
        game->setAmount(game->getAmount() - (amount->currentIndex() + 1));

        Game newGame = *game;
        newGame.setAmount(amount->currentIndex() + 1);

        this->cart->push_back(newGame);
      }

      QStringList* numbers = new QStringList();

      for(int i = 1; i <= game->getAmount(); i++) {
        numbers->push_back(QString("%1").arg(i));
      }

      this->amount->clear();
      this->amount->addItems(*numbers);
    }
  }

  if(DEBUG) {
    for(QVector<Game>::iterator game {this->cart->begin()}; game != this->cart->end(); game++) {
      qDebug() << *game->getTitle() << "   " << game->getAmount();
    }
  }
}

void HomeWindow::goToCartClicked()
{
  CartWindow* secondWidget = new CartWindow(this->stackedWidget, this->cart);

  this->stackedWidget->getQStackedWidget()->addWidget(secondWidget);
  this->stackedWidget->getQStackedWidget()->setCurrentWidget(secondWidget);
}
