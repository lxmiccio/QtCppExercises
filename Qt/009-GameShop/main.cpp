#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QFontDatabase>
#include <QStringList>
#include <QVector>

#include <game.h>
#include <stackedwidget.h>

#define DEBUG 1

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QApplication::setApplicationName("GameShop");

  QFontDatabase::addApplicationFont("sniglet.ttf");

  QVector<Game>* games = new QVector<Game>;

  games->push_back(Game(new QString("Bloodborne"), 44.99, 10, new QStringList {"Action", "Rpg"}, new QStringList {"PlayStation 4"}, new QPixmap {"bloodborne.png"}));
  games->push_back(Game(new QString("Call Of Duty"), 59.99, 25, new QStringList {"Action", "Fps"}, new QStringList {"Pc", "PlayStation 3", "PlayStation 4", "Xbox 360", "Xbox One"}, new QPixmap {"call_of_duty.png"}));

  QStringList* genres = new QStringList();
  QStringList* platforms = new QStringList();

  for(QVector<Game>::iterator game {games->begin()}; game != games->end(); game++) {
    for(QStringList::iterator genre {game->getGenres()->begin()}; genre != game->getGenres()->end(); genre++) {
      if(genres->indexOf(*genre) == -1) {
        genres->append(*genre);
      }
    }
    for(QStringList::iterator platform {game->getPlatforms()->begin()}; platform != game->getPlatforms()->end(); platform++) {
      if(platforms->indexOf(*platform) == -1) {
        platforms->append(*platform);
      }
    }
  }

  std::sort(genres->begin(), genres->end());
  std::sort(platforms->begin(), platforms->end());

  if(DEBUG) {
    qDebug() << "*** Genres List";
    for(QStringList::iterator genre {genres->begin()}; genre != genres->end(); genre++) {
      qDebug() << "***" << *genre;
    }
    qDebug() << "\n";
    qDebug() << "*** Platforms List";
    for(QStringList::iterator platform {platforms->begin()}; platform != platforms->end(); platform++) {
      qDebug() << "***" << *platform;
    }
  }

  StackedWidget stackedWidget(games, genres, platforms);
  stackedWidget.setMinimumSize(QSize(560, 450));
  stackedWidget.show();

  return a.exec();
}
