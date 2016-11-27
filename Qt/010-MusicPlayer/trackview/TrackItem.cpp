#include "TrackItem.h"

TrackItem::TrackItem(const Track* track)
{
    c_track = track;

    QStandardItem* id = new QStandardItem(QString::number(c_track->track()));
    QStandardItem* title = new QStandardItem(c_track->title());
    QStandardItem* album = new QStandardItem(c_track->album()->title());
    QStandardItem* artist = new QStandardItem(c_track->artist()->name());
    QStandardItem* durarion = new QStandardItem(c_track->durationInMinutes());

    m_items = QList<QStandardItem*>();
    m_items.append(id);
    m_items.append(title);
    m_items.append(album);
    m_items.append(artist);
    m_items.append(durarion);
}

TrackItem::~TrackItem()
{
    foreach(QStandardItem* i_item, m_items)
    delete i_item;
}

const Track* TrackItem::track() const
{
    return c_track;
}


QList<QStandardItem*> TrackItem::items() const
{
    return m_items;
}
