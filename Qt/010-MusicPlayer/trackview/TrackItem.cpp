#include "TrackItem.h"

TrackItem::TrackItem(const Track* track)
{
    m_track = track;

    m_items = QList<QStandardItem*>();

    QStandardItem* id = new QStandardItem(QString("%1").arg(m_track->track()));
    QStandardItem* title = new QStandardItem(m_track->title());
    QStandardItem* album = new QStandardItem(m_track->album()->title());
    QStandardItem* artist = new QStandardItem(m_track->artist()->name());
    QStandardItem* durarion = new QStandardItem(m_track->durationInMinutes());

    m_items.append(id);
    m_items.append(title);
    m_items.append(album);
    m_items.append(artist);
    m_items.append(durarion);
}

QList<QStandardItem*> TrackItem::items() const
{
    return m_items;
}

const Track* TrackItem::track() const
{
    return m_track;
}
