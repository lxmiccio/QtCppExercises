#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QAbstractButton>
#include <QIcon>

class ImageButton : public QAbstractButton
{
  Q_OBJECT

public:
  explicit ImageButton(QWidget* parent = 0);

  virtual QSize sizeHint() const { return this->m_sizeHint; }

  void clear();

  void setPixmap(const QString &path);
  void setPixmap(const QPixmap &pixmap);
  void setPixmap(const QString &path, const QIcon::State state, QIcon::Mode mode = QIcon::Normal);
  void setPixmap(const QPixmap &pixmap, const QIcon::State state, QIcon::Mode mode = QIcon::Normal);

protected:
  virtual void paintEvent(QPaintEvent *event);

private:
  QSize m_sizeHint;

  void init(const QPixmap &pixmap);
};

#endif // IMAGEBUTTON_H
