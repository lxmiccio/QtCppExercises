#include "TrackDelegate.h"

#include <QApplication>
#include <QPainter>
#include <QScrollBar>

TrackDelegate::TrackDelegate(const TrackTableView* trackTableView, QObject* parent) : QStyledItemDelegate(parent)
{
    c_trackTableView = trackTableView;
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

    QString text = index.data().toString();

    QFont font = QApplication::font();
    painter->setFont(font);

    switch(index.column())
    {
        case TrackTableView::TRACK:
        {
            painter->drawText(option.rect.adjusted(TrackTableView::LEFT_MARGIN, 0, -TrackTableView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
            break;
        }

        case TrackTableView::TITLE:
        {
            font.setWeight(QFont::DemiBold);
            painter->setFont(font);
            painter->drawText(option.rect.adjusted(TrackTableView::MARGIN, 0, -TrackTableView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
            break;
        }

        case TrackTableView::DURATION:
        {
            painter->drawText(option.rect.adjusted(TrackTableView::MARGIN, 0, -(c_trackTableView->verticalScrollBar()->isVisible() ? TrackTableView::RIGHT_MARGIN_SCROLLBAR : TrackTableView::RIGHT_MARGIN), 0), Qt::AlignVCenter | Qt::AlignRight, text);
            break;
        }

        default:
        {
            painter->drawText(option.rect.adjusted(TrackTableView::MARGIN, 0, -TrackTableView::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
            break;
        }
    }
}
