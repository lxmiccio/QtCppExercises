#ifndef ELIDEDLABEL_H
#define ELIDEDLABEL_H

#include <QFrame>
#include <QTime>

class ElidedLabel : public QFrame
{
  Q_OBJECT

  public:
    explicit ElidedLabel(QWidget* parent = 0, Qt::WindowFlags flags = 0);
    explicit ElidedLabel(const QString& text, QWidget* parent = 0, Qt::WindowFlags flags = 0);

    QString text() const;

    Qt::Alignment alignment() const;
    void setAlignment(Qt::Alignment alignment);

    Qt::TextElideMode elideMode() const;
    void setElideMode(Qt::TextElideMode mode);

    void setFont(const QFont& font);

    int margin() const;
    void setMargin(int margin);

    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;

    void init(const QString& txt = QString());
    void updateLabel();

  public slots:
    void setText(const QString& text);
    void setWordWrap(bool b);

  signals:
    void clicked();
    void textChanged(const QString& text);

  protected:
    virtual void changeEvent(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void paintEvent(QPaintEvent* event);

  private:
    QString m_text;

    Qt::Alignment m_align;
    Qt::TextElideMode m_mode;

    QTime m_time;

    int m_margin;
    bool m_multiLine;
};

#endif // ELIDEDLABEL_H
