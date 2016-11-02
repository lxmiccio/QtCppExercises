#include "imageloader.h"

#include <QImage>
#include <QPainter>
#include <QSvgRenderer>

#include <QDebug>

ImageLoader::ImageLoader()
{

}



QPixmap ImageLoader::pixmap(const QString &image, const QSize &size, double opacity, QColor color)
{
  if(size.height() < 0 || size.width() < 0) {
    return QPixmap();
  }

  QPixmap pixmap;

  if(image.endsWith(QString(".svg"), Qt::CaseInsensitive)) {
    QSvgRenderer svgRenderer(image);

    /*
    pixmap = QPixmap(size.height() == 0 || size.width() == 0 ? svgRenderer.defaultSize() : size);
    pixmap.fill(Qt::transparent);

    QPainter painter {&pixmap};
    painter.setOpacity(opacity);
    svgRenderer.render(&painter);
    painter.end();

    if(color.alpha() > 0) {
      pixmap = ImageLoader::tint(pixmap, color);
    }
    */

    QPixmap p( size.isNull() || size.height() == 0 || size.width() == 0 ? svgRenderer.defaultSize() : size );
    p.fill( Qt::transparent );

    QPainter pixPainter( &p );
    pixPainter.setOpacity( opacity );
    svgRenderer.render( &pixPainter );
    pixPainter.end();

    if ( color.alpha() > 0 )
        p = ImageLoader::tint(p, color);

    pixmap = p;


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
  /* ??? */
  /*
  QImage image {pixmap.size(), QImage::Format_ARGB32_Premultiplied};

  QPainter painter {&image};
  painter.drawPixmap(0, 0, pixmap);
  */
  /* ??? */
  /*
  painter.setCompositionMode(QPainter::CompositionMode_Screen);
  painter.fillRect(image.rect(), color);
  painter.end();

  image.setAlphaChannel(pixmap.toImage().alphaChannel());

  return QPixmap::fromImage(image);
  */

  QImage resultImage( pixmap.size(), QImage::Format_ARGB32_Premultiplied );
  QPainter painter( &resultImage );
  painter.drawPixmap( 0, 0, pixmap );
  painter.setCompositionMode( QPainter::CompositionMode_Screen );
  painter.fillRect( resultImage.rect(), color );
  painter.end();

  resultImage.setAlphaChannel( pixmap.toImage().alphaChannel() );
  return QPixmap::fromImage( resultImage );
}
