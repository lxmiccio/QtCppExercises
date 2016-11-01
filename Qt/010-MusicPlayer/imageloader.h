#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QColor>
#include <QPixmap>

class ImageLoader
{
public:
  explicit ImageLoader();

  QPixmap pixmap(const QString &image, const QSize &size, double opacity = 1.0, QColor color = QColor(0, 0, 0, 0));

private:
  QPixmap tint(const QPixmap &pixmap, const QColor &color);
};

#endif // IMAGELOADER_H
