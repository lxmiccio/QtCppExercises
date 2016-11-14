#include "mydelegate.h"

#include <QPainter>
#include <QApplication>

#include <QScrollBar>

MyDelegate::MyDelegate(TableView *tableView, QObject *parent) : QStyledItemDelegate(parent) {
  this->tw = tableView;
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
    font.setPointSize(10);
    font.setBold(true);

    pen.setColor(QColor(0, 0, 0));

    painter->setFont(font);
    painter->setPen(pen);

    painter->fillRect(option.rect, QColor(0, 0, 0, 5));
  }
  else {
    font.setPointSize(10);
    font.setBold(false);

    pen.setColor(QColor(0, 0, 0));

    painter->setFont(font);
    painter->setPen(pen);

    painter->fillRect(option.rect, QColor(0,0,0,0));
  }

  tw->verticalScrollBar()->setStyleSheet(QString(" QScrollBar:vertical{border: 0px solid grey; background: %1; width: 10px; margin: "
                                                 "0px 0 0px 0;}QScrollBar::handle:vertical{border-image: url(images/rect.svg);border-radius: 4px;}QScrollBar::add-line:vertical{border: 0px solid grey; background: #F00; height: 0px; subcontrol-position: bottom; subcontrol-origin: margin;}QScrollBar::sub-line:vertical{border: 0px solid grey; background: #32CC99; height: 0px; subcontrol-position: top; subcontrol-origin: none;}QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical{border: 0px solid grey; width: 0px; height: 0px; background: white;} QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{background: none;}")
                                         .arg(QColor(255,255,255).name()));

  if(i.column() == 0) {
    painter->drawText(option.rect.adjusted(38,0,-10,0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
  }
  else if(i.column() == 4) {
    if(this->tw->verticalScrollBar()->isVisible()) {
      painter->drawText(option.rect.adjusted(10,0,-16,0), Qt::AlignVCenter | Qt::AlignRight, i.data().toString());
    } else {
      painter->drawText(option.rect.adjusted(10,0,-38,0), Qt::AlignVCenter | Qt::AlignRight, i.data().toString());
    }
  }
  else {
    painter->drawText(option.rect.adjusted(10, 0, -10, 0), Qt::AlignVCenter | Qt::AlignLeft, i.data().toString());
  }


}
