#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QTime>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:

    explicit ClickableLabel(QWidget* parent = 0);
    virtual ~ClickableLabel();

    void setOpacity( float opacity );

signals:
    void clicked();
    void resized( const QPoint& delta );

protected:
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void mouseMoveEvent( QMouseEvent* event );

    void paintEvent( QPaintEvent* event );

private:
    QPoint m_dragPoint;
    bool m_pressed;
    bool m_moved;
    QTime m_time;
    float m_opacity;
};

#endif // CLICKABLELABEL_H
