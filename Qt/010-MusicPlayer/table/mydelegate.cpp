#include "mydelegate.h"

#include <QPainter>
#include <QApplication>

MyDelegate::MyDelegate(QObject *parent) : QStyledItemDelegate(parent) {
  f_focus_border_enabled = false;
}

void MyDelegate::setFocusBorderEnabled(bool enabled) {
  //f_focus_border_enabled = enabled;
}

void MyDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& i ) const
{
  QFont font = QFont();
  QPen pen = QPen();

  if(option.showDecorationSelected && (option.state & QStyle::State_Selected)) {
    font.setBold(true);

    pen.setColor(QColor(0, 0, 0));

    //QPen p = QPen();
    //p.setColor(QColor(0,0,0));
    //QFont f = QFont();
    //f.setBold(true);
    font.setPointSize(10);

    painter->setFont(font);
    painter->setPen(pen);

    painter->fillRect(option.rect, QColor(0, 0, 0, 5));
    if(i.column() == 0)
      painter->drawText(option.rect.adjusted(38,0,-10,0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
    else if(i.column() == 4)
      painter->drawText(option.rect.adjusted(10,0,-38,0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
    else
      painter->drawText(option.rect, Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
  }


  else {
    painter->fillRect(option.rect, QColor(0,0,0,0));
    QPen p = QPen();
    p.setColor(QColor(0,0,0, 255));
    QFont f = QFont();
    f.setPointSize(10);
    f.setBold(false);
    painter->setFont(f);
    painter->setPen(p);
    if(i.column() == 0)
      painter->drawText(option.rect.adjusted(38,0,-10,0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
    else if(i.column() == 4)
      painter->drawText(option.rect.adjusted(10,0,-38,0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
    else
      painter->drawText(option.rect, Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
  }
  //draw the cell with myOption:
  QPen p = QPen();
  p.setColor(QColor(0,0,0));
  painter->setPen(p);
  painter->setBackground(QBrush(QColor(0,0,0)));

}
