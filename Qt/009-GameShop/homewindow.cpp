#include "homewindow.h"

#include <QGridLayout>
#include <QStringList>
#include <QPixmap>

#include <QDebug>
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
    QObject::connect(this->genres, SIGNAL(currentIndexChanged(int)), this, SLOT(filterChanged(int)));

    this->platforms = new QComboBox();
    this->platforms->addItem("All Platforms");
    this->platforms->addItems(*this->stackedWidget->getPlatforms());
    QObject::connect(this->platforms, SIGNAL(currentIndexChanged(int)), this, SLOT(filterChanged(int)));

    this->games = new QComboBox();
    for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
        this->games->addItem(*game->getTitle());
    }
    QObject::connect(this->games, SIGNAL(currentIndexChanged(int)), this, SLOT(gameChanged()));

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

void HomeWindow::filterChanged()
{
    this->games->clear();

    QStringList* gamesList = new QStringList();

    for(QVector<Game>::iterator game {this->stackedWidget->getGames()->begin()}; game != this->stackedWidget->getGames()->end(); game++) {
        bool isSelectedGenre {false};
        bool isForSelectedPlatform {false};

        if(this->genres->currentIndex() == 0) {
            isSelectedGenre = true;
        } else {
            qDebug() << this->genres->currentText();
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

    this->games->addItems(*gamesList);
}

void HomeWindow::gameChanged()
{
    // qDebug() << "sdaaf";
}
