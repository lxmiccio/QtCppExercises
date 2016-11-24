#include "TrackDelegate.h"

#include <QApplication>
#include <QPainter>
#include <QScrollBar>

TrackDelegate::TrackDelegate(const TrackView* trackView, QObject* parent) : QStyledItemDelegate(parent)
{
    m_trackView = trackView;
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
    if(option.state & QStyle::State_Selected)
        painter->fillRect(option.rect, QColor(0, 0, 0, 5));
    else
        painter->fillRect(option.rect, QColor(0, 0, 0, 0));

    QFont font = QApplication::font();
    painter->setFont(font);

    switch(index.column())
    {
        case TrackView::TRACK:
        {
            painter->drawText(option.rect.adjusted(TrackView::LEFT_MARGIN, 0, -TrackView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, index.data().toString());
            break;
        }

        case TrackView::TITLE:
        {
            font.setPointSize(10);
            font.setWeight(QFont::DemiBold);
            painter->setFont(font);
            painter->drawText(option.rect.adjusted(TrackView::MARGIN, 0, -TrackView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, index.data().toString());
            break;
        }

        case TrackView::DURATION:
        {
            if(m_trackView->verticalScrollBar()->isVisible())
                painter->drawText(option.rect.adjusted(TrackView::MARGIN, 0, -TrackView::RIGHT_MARGIN_SCROLLBAR, 0), Qt::AlignVCenter | Qt::AlignRight, index.data().toString());
            else
                painter->drawText(option.rect.adjusted(TrackView::MARGIN, 0, -TrackView::RIGHT_MARGIN, 0), Qt::AlignVCenter | Qt::AlignRight, index.data().toString());
            break;
        }

        default:
        {
            painter->drawText(option.rect.adjusted(TrackView::MARGIN, 0, -TrackView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, index.data().toString());
            break;
        }
    }
}
