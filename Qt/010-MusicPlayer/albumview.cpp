#include "albumview.h"

#include <QDebug>
#include <QLabel>

AlbumView::AlbumView(QWidget* parent) : QWidget(parent)
{
  this->covers = QVector<Cover*>();

  this->mainLayout = new QGridLayout(this);

  this->currCol = 0;
  this->currRow = 0;
}

void AlbumView::addCover(Album* album)
{
  Cover* cover = new Cover(album);
  this->covers.push_back(cover);

  this->currCol++;
  if(currCol!= 0 && currCol % 4 == 0) {
    currRow++;
    currCol = 0;
  }


  qDebug() << "row:"<<this->currRow;
  qDebug() << "col:"<<this->currCol;
  this->mainLayout->addWidget(cover, currRow, currCol, 1, 1);
  QWidget::update();
}

void AlbumView::resizeEvent(QResizeEvent * event)
{
  qDebug()<<event->size().width();

  QWidget::resizeEvent(event);

  /*
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
  *
  */
}
