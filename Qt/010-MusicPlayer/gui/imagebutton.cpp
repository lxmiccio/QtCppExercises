#include "imagebutton.h"

#include <QPainter>
#include <QPaintEvent>

ImageButton::ImageButton(QWidget* parent) : QAbstractButton(parent)
{

}

void ImageButton::clear()
{
  this->setIcon(QIcon());
}

void ImageButton::setPixmap(const QString& path)
{
  init(QPixmap(path));
}

void ImageButton::setPixmap(const QPixmap& pixmap)
{
  init(pixmap);
}

void ImageButton::setPixmap(const QString& path, const QIcon::State state, QIcon::Mode mode)
{
  this->setPixmap(QPixmap(path), state, mode);
}

void ImageButton::setPixmap(const QPixmap& pixmap, const QIcon::State state, QIcon::Mode mode)
{
  QIcon icon = this->icon();
  icon.addPixmap(pixmap, mode, state);

  this->setIcon(icon);
}

void ImageButton::paintEvent(QPaintEvent* event)
{
  QPainter painter(this);
  painter.setClipRect(event->rect());

  QIcon::Mode mode = this->isDown() ? QIcon::Active : QIcon::Normal;
  QIcon::State state = this->isChecked() ? QIcon::On : QIcon::On;

  if(not this->isEnabled()) {
    painter.setOpacity(0.3);
  }

  this->icon().paint(&painter, this->rect(), Qt::AlignCenter, mode, state);
}

void ImageButton::init(const QPixmap& pixmap)
{
  this->m_sizeHint = pixmap.size();

  this->setPixmap(pixmap, QIcon::Off);
  this->updateGeometry();
}

QSize ImageButton::sizeHint() const
{
  return this->m_sizeHint;
}
