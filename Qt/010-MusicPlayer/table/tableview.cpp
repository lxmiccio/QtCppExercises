#include "tableview.h"

TableView::TableView(QWidget* parent) : QTableView(parent)
{
}

void TableView::resizeEvent(QResizeEvent* event)
{

  int width = event->size().width();

  this->setColumnWidth(TableView::TRACK, 75);
  width -= 75;

  this->setColumnWidth(TableView::DURATION, 100);
  width -= 100;

  this->setColumnWidth(TableView::TITLE, width * 0.40);

  this->setColumnWidth(TableView::ALBUM, width * 0.45);

  this->setColumnWidth(TableView::ARTIST, width * 0.15);

  QTableView::resizeEvent(event);
}
