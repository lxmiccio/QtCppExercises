#include "backgroundwidget.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

#include "imageloader.h"
#include "imageutils.h"

BackgroundWidget::BackgroundWidget(QWidget* parent) : QWidget(parent), m_blurred(false)
{
  this->setAutoFillBackground(false);
  this->setBackgroundColor(Qt::transparent);
}

void BackgroundWidget::setBackgroundColor(const QColor& color)
{
  this->m_backgroundColor = color;
}

void BackgroundWidget::setBackgroundImage(const QPixmap& pixmap, bool blurred, bool blackWhite)
{
  this->m_blurred = blurred;

  if(this->m_blurred) {
    this->m_background = QPixmap::fromImage(ImageUtils::blur(pixmap.toImage(), pixmap.rect(), 10, false, blackWhite));
  } else {
    this->m_background = pixmap;
  }

  this->m_backgroundSlice = QPixmap();

  this->repaint();
}

void BackgroundWidget::paintEvent(QPaintEvent* event)
{
  QPainter painter(this);

  if(this->m_backgroundSlice.isNull() and not this->m_background.isNull()) {
    this->m_backgroundSlice = this->m_background.scaledToWidth(this->contentsRect().width(), Qt::SmoothTransformation);
    this->m_backgroundSlice = this->m_backgroundSlice.copy(0, this->m_backgroundSlice.height()/2 - this->contentsRect().height()/2, this->m_backgroundSlice.width(), this->contentsRect().height());
  }

  if(not this->m_backgroundSlice.isNull()) {
    painter.drawPixmap(event->rect(), m_backgroundSlice.copy(event->rect()));

    if(this->m_blurred) {
      painter.save();
      painter.setBrush(Qt::black);
      painter.setPen(Qt::transparent);
      painter.setOpacity(0.25);
      painter.drawRect(event->rect());
      painter.restore();
    }
  } else {
    painter.save();
    painter.setBrush(this->m_backgroundColor);
    painter.setPen(this->m_backgroundColor);
    painter.drawRect(event->rect());
    painter.restore();
  }

  QWidget::paintEvent(event);
}

void BackgroundWidget::resizeEvent(QResizeEvent* event)
{
  this->m_backgroundSlice = QPixmap();

  QWidget::resizeEvent(event);
}
