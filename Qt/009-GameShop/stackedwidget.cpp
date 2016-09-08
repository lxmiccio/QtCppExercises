#include "stackedwidget.h"

#include "homewindow.h"

StackedWidget::StackedWidget(QVector<Game>* games, QStringList* genres, QStringList* platforms, QWidget *parent) : QMainWindow(parent)
{
  this->games = games;
  this->genres = genres;
  this->platforms = platforms;

  this->qStackedWidget = new QStackedWidget();
  this->qStackedWidget->addWidget(new HomeWindow(this));

  setCentralWidget(this->qStackedWidget);

  QObject::connect(this->qStackedWidget, SIGNAL(currentChanged(int)), this, SLOT(goToNewWindow(int)));
}

void StackedWidget::goToNewWindow(int index)
{
  //TO DO
}

void StackedWidget::returnToPreviousWindow()
{
  //TO DO
}