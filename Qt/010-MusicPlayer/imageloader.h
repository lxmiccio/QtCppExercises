#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QColor>
#include <QImage>
#include <QPixmap>

class ImageLoader
{
public:
  explicit ImageLoader();

  static QPixmap pixmap(const QString& image, const QSize& size, double opacity = 1.0, QColor color = QColor(0, 0, 0, 0));

  static QImage blur(const QImage& image, const QRect& rect, int radius, bool alphaOnly = false, bool blackWhite = false);
  static QPixmap tint(const QPixmap& pixmap, const QColor& color);
};

#endif // IMAGELOADER_H
