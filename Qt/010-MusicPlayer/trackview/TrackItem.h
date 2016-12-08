#ifndef TRACKITEM_H
#define TRACKITEM_H

#include "track.h"

class TrackItem
{
    public:
        explicit TrackItem(const QList<QVariant>& data, TrackItem* parent = 0);
        explicit TrackItem(const Track* track, TrackItem* parent = 0);
        ~TrackItem();

        TrackItem* parent() const;
        int row() const;

        TrackItem* child(int row) const;
        int columnCount() const;
        int rowCount() const;

        QVariant data(int column) const;

        void appendChild(TrackItem* child);
        void removeChild(int row);
        void clear();

        const Track* track() const;

    private:
        const Track* c_track;

        TrackItem* m_parent;
        QList<TrackItem*> m_childs;

        QList<QVariant> m_data;
};

#endif // TRACKITEM_H
