#include "scrollarea.h"
#include <QDebug>
#include <QScrollBar>

ScrollArea::ScrollArea(QWidget *parent) : QScrollArea(parent)
{
  verticalScrollBar()->setStyleSheet(QString("QScrollBar:vertical {"
                                               "background: %1;"
                                               "border: 0;"
                                               "margin: 0 0 0 0;"
                                               "width: 10px;"
                                             "}"
                                             "QScrollBar::handle:vertical {"
                                               "margin: 2px 2px 2px 0px;"
                                               "border-image: url(images/scrollbar.jpg);"
                                               "border-radius: 2px;"
                                             "}"
                                             "QScrollBar::add-line:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                             "}"
                                             "QScrollBar::sub-line:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                             "}"
                                             "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
                                               "border: 0;"
                                               "height: 0;"
                                               "width: 0;"
                                             "}")
                                     .arg(QColor(255, 255, 255, 255).name()));
}

void ScrollArea::resizeEvent(QResizeEvent* event)
{
  emit resized(event);

  QScrollArea::resizeEvent(event);
}
