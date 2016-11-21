#include "ClickableLabel.h"

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>

ClickableLabel::ClickableLabel( QWidget* parent )
  : QLabel( parent )
  , m_pressed( false )
  , m_moved( false )
  , m_opacity( 0.5 )
{
  setCursor( Qt::PointingHandCursor );
}


ClickableLabel::~ClickableLabel()
{
}


void ClickableLabel::setOpacity( float opacity )
{
  m_opacity = opacity;
  //repaint();
}


void
ClickableLabel::mousePressEvent( QMouseEvent* event )
{
  QLabel::mousePressEvent( event );

  if ( !m_moved )
  {
    m_time.start();

    m_pressed = true;
    m_dragPoint = event->pos();
  }
}


void
ClickableLabel::mouseReleaseEvent( QMouseEvent* event )
{
  QLabel::mouseReleaseEvent( event );

  if ( event->button() == Qt::LeftButton &&
       !m_moved && m_time.elapsed() < qApp->doubleClickInterval() )
  {
    emit clicked();
  }

  m_pressed = false;
  m_moved = false;
}


void
ClickableLabel::mouseMoveEvent( QMouseEvent* event )
{
  if ( m_pressed )
  {
    QPoint delta = m_dragPoint - event->pos();
    if ( abs( delta.y() ) > 3 )
    {
      m_moved = true;
      emit resized( delta );
    }
  }
}


void
ClickableLabel::paintEvent( QPaintEvent*  event  )
{
    /*
  QPainter painter( this );
  painter.setRenderHint( QPainter::TextAntialiasing );
  painter.setOpacity( m_opacity );

  const QString elidedText = fontMetrics().elidedText( text(), Qt::ElideRight, contentsRect().width() );
  painter.drawText( contentsRect(), alignment(), elidedText );
*/
  QLabel::paintEvent(event);
}
