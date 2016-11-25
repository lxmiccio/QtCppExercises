#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QStandardItemModel>

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
    TrackTableView* m_tableView;
    TrackDelegate* m_delegate;
    QStandardItemModel* m_model;

    QVector<TrackItem*> m_items;
};

#endif // TRACKVIEW_H
