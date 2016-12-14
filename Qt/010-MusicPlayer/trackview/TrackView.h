#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QHBoxLayout>
#include <QSpacerItem>
#include <QStandardItemModel>

#include "AlbumWidget.h"
#include "BackgroundWidget.h"
#include "Track.h"
#include "TrackDelegate.h"
#include "TrackItem.h"
#include "TrackList.h"
#include "TrackModel.h"

class TrackView : public QWidget
{
    Q_OBJECT

public:
    explicit TrackView(QWidget* parent = 0);
    ~TrackView();

    static const quint16 WIDGET_HEIGHT = 415;

public slots:
    void onAlbumSelected(const Album& album);

signals:
    void doubleClicked(const Track&);

private slots:
    void onDoubleClicked(const QModelIndex& index);

private:
    void clear();

    AlbumWidget* m_albumView;

    QSpacerItem* m_spacer;

    TrackList* m_trackList;
    TrackModel* m_model;
    TrackDelegate* m_delegate;

    QVector<TrackItem*> m_items;

    QHBoxLayout* m_layout;
};

#endif // TRACKVIEW_H
