#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QAbstractButton>
#include <QIcon>

class ImageButton : public QAbstractButton
{
  Q_OBJECT

public:
  explicit ImageButton(QWidget* parent = 0);
  explicit ImageButton(const QPixmap &pixmap, QWidget* parent = 0);
  explicit ImageButton(const QString &path, QWidget* parent = 0);

  void setPixmap(const QString &path);
  void setPixmap(const QPixmap &pixmap);

  void setPixmap(const QString &path, const QIcon::State state, QIcon::Mode mode = QIcon::Normal);
  void setPixmap(const QPixmap &pixmap, const QIcon::State state, QIcon::Mode mode = QIcon::Normal);

  void clear();

  // virtual QSize getSize() const { return this->size; }
  virtual QSize sizeHint() const { return m_sizeHint; }

protected:
  virtual void paintEvent(QPaintEvent *event);

private:
  void init(const QPixmap &pixmap);

  //QSize size;
  QSize m_sizeHint;
};

#endif // IMAGEBUTTON_H
