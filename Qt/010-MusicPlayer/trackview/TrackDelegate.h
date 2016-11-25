#ifndef TRACKDELEGATE_H
#define TRACKDELEGATE_H

#include <QStyledItemDelegate>

#include "TrackTableView.h"

class TrackDelegate : public QStyledItemDelegate
{
    public:
        explicit TrackDelegate(const TrackTableView* trackTableView, QObject* parent = 0);

        virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
        virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    private:
        const TrackTableView* c_trackTableView;
};

#endif // TRACKDELEGATE_H
