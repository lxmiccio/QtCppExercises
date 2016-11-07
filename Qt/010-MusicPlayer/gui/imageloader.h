#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QColor>
#include <QImage>
#include <QPixmap>

class ImageLoader
{
public:
  static QPixmap pixmap(const QString& image, const QSize& size, double opacity = 1.0, QColor color = QColor(0, 0, 0, 0));
};

#endif // IMAGELOADER_H
