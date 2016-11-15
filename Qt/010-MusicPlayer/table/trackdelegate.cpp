#include "trackdelegate.h"

#include <QPainter>
#include <QScrollBar>

TrackDelegate::TrackDelegate(TrackView *trackView, QObject *parent) : QStyledItemDelegate(parent)
{
  this->trackView = trackView;
}

QWidget* TrackDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
  Q_UNUSED(parent);
  Q_UNUSED(option);
  Q_UNUSED(index);

  return NULL;
}

void TrackDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
  if(option.showDecorationSelected && (option.state & QStyle::State_Selected)) {
    painter->fillRect(option.rect, QColor(0, 0, 0, 5));
  } else {
    painter->fillRect(option.rect, QColor(0, 0, 0, 0));
  }

  QFont font = QFont();
  QPen pen = QPen();

  if(index.column() == TrackView::TITLE) {
    font.setBold(true);
  }

  painter->setFont(font);
  painter->setPen(pen);

  if(index.column() == TrackView::TRACK) {
    painter->drawText(option.rect.adjusted(38, 0, -10, 0), Qt::AlignVCenter | Qt::AlignLeft, index.data().toString());
  }
  else if(index.column() == TrackView::DURATION)
  {
    if(this->trackView->verticalScrollBar()->isVisible()) {
      painter->drawText(option.rect.adjusted(10, 0, -28, 0), Qt::AlignVCenter | Qt::AlignRight, index.data().toString());
    } else {
      painter->drawText(option.rect.adjusted(10, 0, -38, 0), Qt::AlignVCenter | Qt::AlignRight, index.data().toString());
    }
  }
  else {
    painter->drawText(option.rect.adjusted(10, 0, -10, 0), Qt::AlignVCenter | Qt::AlignLeft, index.data().toString());
  }
}
