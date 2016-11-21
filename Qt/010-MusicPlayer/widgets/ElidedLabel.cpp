#include "ElidedLabel.h"

#include <QApplication>
#include <QEvent>
#include <QFontMetrics>
#include <QPainter>
#include <QRect>
#include <QTextLayout>

ElidedLabel::ElidedLabel(QWidget* parent, Qt::WindowFlags flags) : QFrame(parent, flags)
{
  this->init();
}


ElidedLabel::ElidedLabel(const QString& text, QWidget* parent, Qt::WindowFlags flags) : QFrame(parent, flags)
{
  this->init(text);
}

QString ElidedLabel::text() const
{
  return this->m_text;
}

Qt::Alignment ElidedLabel::alignment() const
{
  return this->m_align;
}

void ElidedLabel::setAlignment(Qt::Alignment alignment)
{
  if(this->m_align != alignment) {
    this->m_align = alignment;
    this->update();
  }
}

Qt::TextElideMode ElidedLabel::elideMode() const
{
  return this->m_mode;
}

void ElidedLabel::setElideMode(Qt::TextElideMode mode)
{
  if(this->m_mode != mode ) {
    this->m_mode = mode;
    this->updateLabel();
  }
}

void ElidedLabel::setFont(const QFont& font)
{
  QWidget::setFont(font);
  this->updateLabel();
}

int ElidedLabel::margin() const
{
  return this->m_margin;
}

void ElidedLabel::setMargin(int margin)
{
  this->m_margin = margin;
}

QSize ElidedLabel::sizeHint() const
{
  const QFontMetrics& metrics = this->fontMetrics();
  return QSize(metrics.width(this->m_text) + this->m_margin * 2, metrics.height() + this->m_margin * 2);
}

QSize ElidedLabel::minimumSizeHint() const
{
  switch(this->m_mode) {
    case Qt::ElideNone: {
      return this->sizeHint();
      break;
    }

    default: {
      const QFontMetrics& metrics = this->fontMetrics();
      return QSize(metrics.width( "..." ), metrics.height());
    }
  }
}

void ElidedLabel::updateLabel()
{
  this->updateGeometry();
  this->update();
}

void ElidedLabel::setText(const QString& text)
{
  if(this->m_text != text) {
    this->m_text = text;
    this->updateLabel();

    emit textChanged(text);
  }
}

void ElidedLabel::setWordWrap(bool b)
{
  this->m_multiLine = b;
}

void ElidedLabel::init(const QString& txt)
{
  this->m_text = txt;
  this->m_align = Qt::AlignLeft;
  this->m_mode = Qt::ElideRight;
  this->m_margin = 0;
  this->m_multiLine = false;

  this->setContentsMargins(0, 0, 0, 0);
}

void ElidedLabel::paintEvent(QPaintEvent* event)
{
  QFrame::paintEvent(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::TextAntialiasing);

  QRect rect = this->contentsRect();
  rect.adjust(this->m_margin, this->m_margin, -this->m_margin, -this->m_margin);

  if(this->m_multiLine) {
    QTextLayout textLayout(this->m_text);
    textLayout.setFont(painter.font());

    int widthUsed = 0;
    int lineCount = 0;
    int lineLimit = rect.height() / this->fontMetrics().height();

    textLayout.beginLayout();

    while(++lineCount < lineLimit) {
      QTextLine line = textLayout.createLine();

      if(!line.isValid()) {
        break;
      }

      line.setLineWidth(rect.width());
      widthUsed += line.naturalTextWidth();
    }

    textLayout.endLayout();
    widthUsed += rect.width();

    const QString elidedText = this->fontMetrics().elidedText(this->m_text, Qt::ElideRight, widthUsed);
    painter.drawText(rect, this->m_align | Qt::TextWordWrap, elidedText);
  } else {
    const QString elidedText = this->fontMetrics().elidedText(this->m_text, this->m_mode, rect.width());
    painter.drawText(rect, this->m_align, elidedText);
  }
}

void ElidedLabel::changeEvent(QEvent* event)
{
  QFrame::changeEvent(event);

  switch(event->type()) {
    case QEvent::ApplicationFontChange:
    case QEvent::FontChange: {
      this->updateLabel();
      break;
    }
    default:
      break;
  }
}

void ElidedLabel::mousePressEvent(QMouseEvent* event)
{
  QFrame::mousePressEvent(event);
  this->m_time.start();
}

void ElidedLabel::mouseReleaseEvent(QMouseEvent* event)
{
  QFrame::mouseReleaseEvent(event);

  if(m_time.elapsed() < qApp->doubleClickInterval()) {
    emit clicked();
  }
}
