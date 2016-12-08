#include "TrackItem.h"

TrackItem::TrackItem(const QList<QVariant>& data, TrackItem* parent)
{
    c_track = NULL;
    m_parent = parent;
    m_data = data;
}

TrackItem::TrackItem(const Track* track, TrackItem* parent)
{
    c_track = track;
    m_parent = parent;
    m_data << QVariant(track->track()) << QVariant(track->title()) << QVariant(track->durationInMinutes());
}

TrackItem::~TrackItem()
{
    qDeleteAll(m_childs);
}

TrackItem *TrackItem::parent() const
{
    return m_parent;
}

int TrackItem::row() const
{
    if(m_parent)
    {
        return m_parent->m_childs.indexOf(const_cast<TrackItem*>(this));
    }

    return 0;
}

TrackItem *TrackItem::child(int row) const
{
    return m_childs.at(row);
    return m_childs.value(row);
}

int TrackItem::columnCount() const
{
    return m_data.count();
}

int TrackItem::rowCount() const
{
    return m_childs.count();
}

QVariant TrackItem::data(int column) const
{
    return m_data.value(column);
}

void TrackItem::appendChild(TrackItem* item)
{
    m_childs.append(item);
}

void TrackItem::removeChild(int row)
{
    delete m_childs.at(row);
    m_childs.removeAt(row);
}

void TrackItem::clear()
{
    qDeleteAll(m_childs);
    m_childs.clear();
}

const Track* TrackItem::track() const
{
    return c_track;
}
