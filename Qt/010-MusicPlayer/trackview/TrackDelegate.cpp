#include "TrackDelegate.h"

#include <QApplication>
#include <QPainter>
#include <QScrollBar>

TrackDelegate::TrackDelegate(const TrackList* trackList, QObject* parent) : QStyledItemDelegate(parent)
{
    c_trackList = trackList;
}

QWidget* TrackDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(parent);
    Q_UNUSED(option);
    Q_UNUSED(index);

    return NULL;
}

#include <QDebug>

void TrackDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if(option.state & QStyle::State_Selected)
    {
        QRect rect;

        if(index.column() == TrackList::TRACK)
            rect = QRect(QPoint(option.rect.topLeft().x() + SeekSlider::WIDTH, option.rect.topLeft().y()), option.rect.bottomRight());
        else if(index.column() == TrackList::DURATION)
            rect = QRect(option.rect.topLeft(), QPoint(option.rect.bottomRight().x() - SeekSlider::WIDTH, option.rect.bottomRight().y()));
        else
            rect = option.rect;

        painter->fillRect(rect, QColor(0, 0, 0, 10));
    }
    else
    {
        painter->fillRect(option.rect, QColor(0, 0, 0, 0));
    }

    QFont font = QApplication::font();
    painter->setFont(font);

    QPen pen;
    pen.setColor(Qt::white);
    painter->setPen(pen);

    QString text = index.data().toString();

    switch(index.column())
    {
    case TrackList::TRACK:
    {
        painter->drawText(option.rect.adjusted(TrackList::LEFT_MARGIN, 0, -TrackList::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
        break;
    }

    case TrackList::DURATION:
    {
        painter->drawText(option.rect.adjusted(TrackList::MARGIN, 0, -(c_trackList->verticalScrollBar()->isVisible() ? TrackList::RIGHT_MARGIN_SCROLLBAR : TrackList::RIGHT_MARGIN), 0), Qt::AlignVCenter | Qt::AlignRight, text);
        break;
    }

    default:
    {
        painter->drawText(option.rect.adjusted(TrackList::MARGIN, 0, -TrackList::MARGIN, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
        break;
    }
    }
}
