#include "imagebutton.h"

#include <QPainter>
#include <QPaintEvent>

#include <QDebug>

ImageButton::ImageButton(QWidget *parent) : QAbstractButton(parent)
{
}

ImageButton::ImageButton(const QPixmap &pixmap, QWidget *parent) : QAbstractButton(parent)
{
  init(pixmap);
}

ImageButton::ImageButton(const QString &path, QWidget *parent) : QAbstractButton(parent)
{
  init(QPixmap(path));
}

void ImageButton::init(const QPixmap &pixmap)
{
  this->setPixmap(pixmap, QIcon::Off);
  //this->size = pixmap.size();
  m_sizeHint = pixmap.size();
  this->updateGeometry();
}

void ImageButton::setPixmap(const QString &path)
{
  init(QPixmap(path));
}

void ImageButton::setPixmap(const QPixmap &pixmap)
{
  init(pixmap);
}

void ImageButton::clear()
{
  this->setIcon(QIcon());
}

void ImageButton::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setClipRect(event->rect());

  QIcon::Mode mode = this->isDown() ? QIcon::Active : QIcon::Normal;
  qDebug() << mode;
  QIcon::State state = this->isChecked() ? QIcon::On : QIcon::On;

  if(not this->isEnabled()) {
    /* Button cannot be pressed */
    painter.setOpacity(0.4);
  }

  this->icon().paint(&painter, this->rect(), Qt::AlignCenter, mode, state);
}

void ImageButton::setPixmap(const QString &path, const QIcon::State state, QIcon::Mode mode)
{
  qDebug() << "a11";
  this->setPixmap(QPixmap(path), state, mode);
}

void ImageButton::setPixmap(const QPixmap &pixmap, const QIcon::State state, QIcon::Mode mode)
{
  qDebug() << "a111";
  QIcon icon = this->icon();
  icon.addPixmap(pixmap, mode, state);

  this->setIcon(icon);
}
