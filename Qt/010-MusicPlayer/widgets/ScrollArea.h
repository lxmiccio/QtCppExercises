#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>

class ScrollArea : public QScrollArea
{
  Q_OBJECT

public:
  ScrollArea(QWidget* parent = 0);
  void resizeEvent(QResizeEvent* event);

signals:
  void resized(QResizeEvent* event);
};

#endif // SCROLLAREA_H
