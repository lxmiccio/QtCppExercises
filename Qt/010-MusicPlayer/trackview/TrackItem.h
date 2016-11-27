#ifndef TRACKITEM_H
#define TRACKITEM_H

#include <QStandardItem>

#include "track.h"

class TrackItem
{
    public:
        explicit TrackItem(const Track* track);
        ~TrackItem();

        const Track* track() const;
        QList<QStandardItem*> items() const;

    private:
        const Track* c_track;
        QList<QStandardItem*> m_items;
};

#endif // TRACKITEM_H
