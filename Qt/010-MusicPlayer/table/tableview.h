#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QResizeEvent>
#include <QTableView>

class TableView : public QTableView
{
public:
  explicit TableView(QWidget * parent = 0);

  void resizeEvent(QResizeEvent* event);
};

#endif // TABLEVIEW_H
