#ifndef TRACKDELEGATE_H
#define TRACKDELEGATE_H

#include <QStyledItemDelegate>

#include "trackview.h"

class TrackDelegate : public QStyledItemDelegate
{
  public:
    TrackDelegate(TrackView* trackView, QObject* parent = 0);

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

  protected:
    TrackView* trackView;
};

#endif // TRACKDELEGATE_H
