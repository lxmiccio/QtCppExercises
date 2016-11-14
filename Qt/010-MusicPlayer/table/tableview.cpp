#include "tableview.h"

TableView::TableView(QWidget* parent) : QTableView(parent)
{
}

void TableView::resizeEvent(QResizeEvent* event)
{
  int width = event->size().width();

  this->setColumnWidth(0, 100);
  width -= 100;

  this->setColumnWidth(4, 100);
  width -= 100;

  this->setColumnWidth(1, width * 0.45);

  this->setColumnWidth(2, width * 0.35);

  this->setColumnWidth(3, width * 0.20);


  QTableView::resizeEvent(event);
}
