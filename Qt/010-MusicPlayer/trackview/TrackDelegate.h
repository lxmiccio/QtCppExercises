#ifndef TRACKDELEGATE_H
#define TRACKDELEGATE_H

#include <QStyledItemDelegate>

#include "trackview.h"

class TrackDelegate : public QStyledItemDelegate
{
    public:
        explicit TrackDelegate(const TrackView* trackView, QObject* parent = 0);

        virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
        virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    private:
        const TrackView* m_trackView;
};

#endif // TRACKDELEGATE_H
