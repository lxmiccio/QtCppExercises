#include "imageloader.h"

#include <QImage>
#include <QPainter>
#include <QSvgRenderer>

ImageLoader::ImageLoader()
{

}

QPixmap ImageLoader::pixmap(const QString& image, const QSize& size, double opacity, QColor color)
{
  if(size.height() < 0 || size.width() < 0) {
    return QPixmap();
  }

  QPixmap pixmap;

  if(image.endsWith(QString(".svg"), Qt::CaseInsensitive)) {
    QSvgRenderer svgRenderer(image);

    pixmap = QPixmap(size.height() == 0 || size.width() == 0 ? svgRenderer.defaultSize() : size);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setOpacity(opacity);
    svgRenderer.render(&painter);
    painter.end();

    if(color.alpha() > 0) {
      pixmap = ImageLoader::tint(pixmap, color);
    }
  } else {
    pixmap = QPixmap(image);
  }

  if(not pixmap.isNull() and not size.isNull() and pixmap.size() != size) {
    if(size.height() == 0) {
      pixmap = pixmap.scaledToWidth(size.width(), Qt::SmoothTransformation);
    } else if(size.width() == 0) {
      pixmap = pixmap.scaledToHeight(size.height(), Qt::SmoothTransformation);
    } else {
      pixmap = pixmap.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
  }

  return pixmap;
}

QPixmap ImageLoader::tint(const QPixmap &pixmap, const QColor &color)
{
  QImage image(pixmap.size(), QImage::Format_ARGB32);

  QPainter painter(&image);
  painter.drawPixmap(0, 0, pixmap);
  painter.fillRect(image.rect(), color);
  painter.setCompositionMode(QPainter::CompositionMode_Screen);
  painter.end();

  image.setAlphaChannel(pixmap.toImage().alphaChannel());

  return QPixmap::fromImage(image);
}
