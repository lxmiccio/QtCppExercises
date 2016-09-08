#include <algorithm>

#include <QApplication>
#include <QDebug>
#include <QStringList>
#include <QVector>

#include <stackedwidget.h>
#include <game.h>

#define DEBUG 1
#define PERFORMANCE 1

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QVector<Game> games;

  games.push_back(Game(new QString("Bloodborne"), 44.99, 10, new QStringList {"Action", "Rpg"}, new QStringList {"PlayStation 4"}, QPixmap {"bloodborne.png"}));
  games.push_back(Game(new QString("Call Of Duty"), 59.99, 25, new QStringList {"Action", "Fps"}, new QStringList {"Pc", "PlayStation 3", "PlayStation 4", "Xbox 360", "Xbox One"}, QPixmap {"call_pf_duty.png"}));

  QStringList genres;
  QStringList platforms;

  if(PERFORMANCE) {
    for(QVector<Game>::iterator game {games.begin()}; game != games.end(); game++) {
      for(QStringList::iterator genre {game->getGenres()->begin()}; genre != game->getGenres()->end(); genre++) {
        if(genres.indexOf(*genre) == -1) {
          genres.append(*genre);
        }
      }
      for(QStringList::iterator platform {game->getPlatforms()->begin()}; platform != game->getPlatforms()->end(); platform++) {
        if(platforms.indexOf(*platform) == -1) {
          platforms.append(*platform);
        }
      }
    }
  } else {
    for(Game game : games) {
      for(QString genre : *game.getGenres()) {
        if(genres.indexOf(genre) == -1) {
          genres.append(genre);
        }
      }
      for(QString platform : *game.getPlatforms()) {
        if(platforms.indexOf(platform) == -1) {
          platforms.append(platform);
        }
      }
    }
  }

  std::sort(genres.begin(), genres.end());
  std::sort(platforms.begin(), platforms.end());

  if(DEBUG) {
    qDebug() << "*** Genres List ***";
    for(QString genre : genres) {
      qDebug() << genre;
    }
    qDebug() << "\n";
    qDebug() << "*** Platforms List ***";
    for(QString platform : platforms) {
      qDebug() << platform;
    }
  }

  StackedWidget stackedWidget(&games, &genres, &platforms);
  stackedWidget.show();

  return a.exec();
}
