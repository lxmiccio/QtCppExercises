#include "cartwindow.h"

#include <QGridLayout>
#include <QString>

CartWindow::CartWindow(StackedWidget* stackedWidget, QVector<Game>* selectedGames, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;
  this->selectedGames = selectedGames;

  this->games = new QVector<QLabel*>();

  QGridLayout* gridLayout = new QGridLayout();

  for(QVector<Game>::iterator game {this->selectedGames->begin()}; game != this->selectedGames->end(); game++) {
    QLabel* label = new QLabel(QString("%1          %2          € %3").arg(*game->getTitle(), QString::number(game->getAmount()), QString::number(game->getPrice() * game->getAmount())));
    label->setAlignment(Qt::AlignCenter);
    this->games->push_back(label);
  }

  int i {0};
  for(QVector<QLabel>::iterator *label {this->games->begin()}; label != this->games->end(); i++, label++) {
    gridLayout->addWidget(*label, i, 0, 1, 1);
  }

  setLayout(gridLayout);
}
