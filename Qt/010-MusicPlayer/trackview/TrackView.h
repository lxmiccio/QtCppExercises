#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QStandardItemModel>
#include <QTableView>

#include "SeekSlider.h"
#include "Track.h"
#include "TrackItem.h"

class TrackView : public QTableView
{
  Q_OBJECT

public:
    explicit TrackView(QWidget* parent = 0);
    ~TrackView();

    static const quint8 TRACK = 0;
    static const quint8 TITLE = 1;
    static const quint8 ALBUM = 2;
    static const quint8 ARTIST = 3;
    static const quint8 DURATION = 4;

    static const quint8 TRACK_WIDTH = 100;
    static constexpr double TITLE_WIDTH_PERCENTAGE = 0.4;
    static constexpr double ALBUM_WIDTH_PERCENTAGE = 0.4;
    static constexpr double ARTIST_WIDTH_PERCENTAGE = 0.2;
    static const quint8 DURATION_WIDTH = 100;

    static const quint8 LEFT_MARGIN = 38;
    static const quint8 MARGIN = 10;
    static const quint8 RIGHT_MARGIN = 38;
    static const quint8 RIGHT_MARGIN_SCROLLBAR = RIGHT_MARGIN - SeekSlider::WIDTH;


  public slots:
    void onAlbumSelected(const Album& album);

  signals:
    void doubleClicked(const Track&);

  private slots:
    void onDoubleClicked(const QModelIndex& index);

  protected:
    virtual void resizeEvent(QResizeEvent* event);

  private:
    QStandardItemModel* m_model;

    QVector<TrackItem*> m_trackItems;
};

#endif // TRACKVIEW_H
