#include "homewindow.h"

#include <QDebug>
#include <QFont>
#include <QGridLayout>
#include <QPixmap>
#include <QSizePolicy>
#include <QStringList>

#include <cartwindow.h>

#define DEBUG 1

HomeWindow::HomeWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  QFont font = QFont();
  font.setFamily("sniglet");
  font.setPointSize(30);


  this->logo = new QLabel("GameShop", this);
  this->logo->setFont(font);
  this->logo->setAlignment(Qt::AlignCenter);

  this->genres = new QComboBox();
  this->genres->addItem("All Genres");
  this->genres->addItems(*this->stackedWidget->getGenres());
  QObject::connect(this->genres, SIGNAL(currentIndexChanged(QString)), this, SLOT(filterChanged()));

  this->platforms = new QComboBox();
  this->platforms->addItem("All Platforms");
  this->platforms->addItems(*this->stackedWidget->getPlatforms());
  QObject::connect(this->platforms, SIGNAL(currentIndexChanged(QString)), this, SLOT(filterChanged()));

  this->games = new QComboBox();
  this->games->addItem("Games");
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    this->games->addItem(*game->getTitle());
  }
  QObject::connect(this->games, SIGNAL(currentIndexChanged(QString)), this, SLOT(gameChanged(QString)));

  this->amount = new QComboBox();
  this->amount->addItem("Select a Game");
  QObject::connect(this->amount, SIGNAL(currentIndexChanged(int)), this, SLOT(amountChanged(int)));

  this->price = new QLabel("Price: € 0");
  this->price->setAlignment(Qt::AlignCenter);

  QPixmap* pixmap = new QPixmap {"placeholder.png"};
  this->cover = new QLabel();
  this->cover->setAlignment(Qt::AlignCenter);
  this->cover->setPixmap(pixmap->scaled(QSize(260, 320), Qt::IgnoreAspectRatio, Qt::FastTransformation));

  this->addToCart = new QPushButton("Add to Cart");
  QObject::connect(this->addToCart, SIGNAL(clicked()), this, SLOT(addToCartClicked()));

  this->goToCart = new QPushButton("Go to Cart");
  QObject::connect(this->goToCart, SIGNAL(clicked()), this, SLOT(goToCartClicked()));

  QGridLayout* gridLayout = new QGridLayout();

  gridLayout->setSpacing(15);

  gridLayout->addWidget(this->logo, 0, 0, 1, 2);
  gridLayout->addWidget(this->genres, 1, 0, 1, 1);
  gridLayout->addWidget(this->platforms, 1, 1, 1, 1);
  gridLayout->addWidget(this->games, 2, 0, 1, 1);
  gridLayout->addWidget(this->amount, 3, 0, 1, 1);
  gridLayout->addWidget(this->price, 4, 0, 1, 1);
  gridLayout->addWidget(this->cover, 2, 1, 5, 1);
  gridLayout->addWidget(this->addToCart, 5, 0, 1, 1);
  gridLayout->addWidget(this->goToCart, 6, 0, 1, 1);

  this->setLayout(gridLayout);

  this->selectedGames = new QVector<Game>();
}

void HomeWindow::filterChanged()
{
  QStringList* gamesList = new QStringList();

  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    bool isSelectedGenre {false};
    bool isForSelectedPlatform {false};

    if(this->genres->currentIndex() == 0) {
      isSelectedGenre = true;
    }
    else {
      if(game->getGenres()->indexOf(this->genres->currentText()) != -1) {
        isSelectedGenre = true;
      }
    }

    if(this->platforms->currentIndex() == 0) {
      isForSelectedPlatform = true;
    }
    else  {
      if(game->getPlatforms()->indexOf(this->platforms->currentText()) != -1) {
        isForSelectedPlatform = true;
      }
    }

    if(isSelectedGenre and isForSelectedPlatform) {
      gamesList->push_back(*game->getTitle());
    }
  }

  this->games->clear();
  this->games->addItem("Games");
  this->games->addItems(*gamesList);

  this->amount->clear();
  this->amount->addItem("Select a Game");

  this->price->setText("Price: € 0");

  QPixmap* pixmap = new QPixmap {"placeholder.png"};
  this->cover->setPixmap(pixmap->scaled(QSize(260, 320), Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void HomeWindow::gameChanged(QString title)
{
  if(this->games->currentIndex() == 0) {
    this->amount->clear();
    this->amount->addItem("Select a Game");

    this->price->setText("Price: € 0");

    QPixmap* pixmap = new QPixmap {"placeholder.png"};
    this->cover->setPixmap(pixmap->scaled(QSize(260, 320), Qt::IgnoreAspectRatio, Qt::FastTransformation));
  }
  else {
    for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
      if(*game->getTitle() == title) {
        QStringList* numbers = new QStringList();

        for(int i = 1; i <= game->getAmount(); i++) {
          numbers->push_back(QString("%1").arg(i));
        }

        this->amount->clear();
        this->amount->addItems(*numbers);

        this->price->setText(QString("Price: € %1").arg(game->getPrice()));

        this->cover->setPixmap(game->getPixmap()->scaled(QSize(260, 320), Qt::IgnoreAspectRatio, Qt::FastTransformation));
      }
    }
  }
}

void HomeWindow::amountChanged(int index)
{
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    if(*game->getTitle() == this->games->currentText()) {
      this->price->setText(QString("Price: € %1").arg(game->getPrice() * (index + 1)));
    }
  }
}

void HomeWindow::addToCartClicked()
{
  for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
    if(*game->getTitle() == this->games->currentText()) {
      bool found {false};

      for(QVector<Game>::iterator selectedGame {this->selectedGames->begin()}; selectedGame != this->selectedGames->end(); selectedGame++) {
        if(*selectedGame->getTitle() == *game->getTitle()) {
          game->setAmount(game->getAmount() - (amount->currentIndex() + 1));
          selectedGame->setAmount(selectedGame->getAmount() + amount->currentIndex() + 1);

          found = true;
        }
      }

      if(not found) {
        game->setAmount(game->getAmount() - (amount->currentIndex() + 1));

        Game selectedGame = *game;
        selectedGame.setAmount(amount->currentIndex() + 1);
        this->selectedGames->push_back(selectedGame);
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
    for(QVector<Game>::iterator game {this->selectedGames->begin()}; game != this->selectedGames->end(); game++) {
      qDebug() << *game->getTitle() << "   " << game->getAmount();
    }
  }
}

void HomeWindow::goToCartClicked()
{
  CartWindow* cart = new CartWindow(this->stackedWidget, this->selectedGames);

  this->stackedWidget->getQStackedWidget()->addWidget(cart);
  this->stackedWidget->getQStackedWidget()->setCurrentWidget(cart);
}
