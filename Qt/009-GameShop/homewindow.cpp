#include "homewindow.h"

#include <QGridLayout>
#include <QStringList>
#include <QPixmap>

HomeWindow::HomeWindow(StackedWidget* stackedWidget, QWidget* parent) : QWidget(parent)
{
  this->stackedWidget = stackedWidget;

  QPixmap image {"qt_logo.png"};

  this->logo = new QLabel();
  this->logo->setPixmap(image);

  this->genres = new QStringList();

  for(QStringList::iterator genre : this->stackedWidget->getGenres()) {

  }

  this->genres = new QComboBox();

  QGridLayout* gridLayout = new QGridLayout();
  gridLayout->addWidget(this->logo, 0, 0, 1, 2);

  this->setLayout(gridLayout);
}
