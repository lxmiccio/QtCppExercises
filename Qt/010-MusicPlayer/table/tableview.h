#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QResizeEvent>
#include <QTableView>

class TableView : public QTableView
{
  static const quint8 TRACK = 0;
  static const quint8 TITLE = 1;
  static const quint8 ALBUM = 2;
  static const quint8 ARTIST = 3;
  static const quint8 DURATION = 4;

public:
  explicit TableView(QWidget * parent = 0);

  void resizeEvent(QResizeEvent* event);
};

#endif // TABLEVIEW_H
