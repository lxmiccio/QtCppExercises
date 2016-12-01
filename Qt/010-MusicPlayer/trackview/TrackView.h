#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QStandardItemModel>
#include <QHBoxLayout>

#include "AlbumWidget.h"
#include "BackgroundWidget.h"
#include "Track.h"
#include "TrackDelegate.h"
#include "TrackItem.h"
#include "TrackTableView.h"

class TrackView : public QWidget
{
    Q_OBJECT

public:
    explicit TrackView(QWidget* parent = 0);
    ~TrackView();

public slots:
    void onAlbumSelected(const Album& album);

signals:
    void doubleClicked(const Track&);

private slots:
    void onDoubleClicked(const QModelIndex& index);

private:
    void clear();

    AlbumWidget* m_albumView;

    TrackTableView* m_tableView;
    QStandardItemModel* m_model;
    TrackDelegate* m_delegate;

    QVector<TrackItem*> m_items;

    QHBoxLayout* m_layout;
};

#endif // TRACKVIEW_H
