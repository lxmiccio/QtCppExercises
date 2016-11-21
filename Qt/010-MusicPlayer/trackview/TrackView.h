#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QResizeEvent>
#include <QTableView>

class TrackView : public QTableView
{
  public:
    explicit TrackView(QWidget * parent = 0);

    void resizeEvent(QResizeEvent* event);

    static const quint8 TRACK = 0;
    static const quint8 TITLE = 1;
    static const quint8 ALBUM = 2;
    static const quint8 ARTIST = 3;
    static const quint8 DURATION = 4;

    static const quint8 TRACK_WIDTH = 100;
    static const quint8 DURATION_WIDTH = 100;

    static constexpr double TITLE_WIDTH_PERCENTAGE = 0.4;
    static constexpr double ALBUM_WIDTH_PERCENTAGE = 0.4;
    static constexpr double ARTIST_WIDTH_PERCENTAGE = 0.2;
};

#endif // TRACKVIEW_H
