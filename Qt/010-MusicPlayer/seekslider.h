#ifndef SEEKSLIDER_H
#define SEEKSLIDER_H

#include <QSlider>
#include <QTimeLine>

namespace GuiUtils
{
  class SeekSlider : public QSlider
  {
  public:
    explicit SeekSlider(Qt::Orientation orientation, QWidget* parent = 0);

    void setAcceptWheelEvents(bool accept);
    void setTimeLine(QTimeLine* timeline);

  public slots:
    void setValue(int value);

  protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);

  private:
      bool m_acceptWheelEvents;
      bool m_isScrubbing;
      QTimeLine* m_timeLine;
  };
}

#endif // SEEKSLIDER_H
