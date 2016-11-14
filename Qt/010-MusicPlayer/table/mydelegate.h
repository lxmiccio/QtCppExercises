#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>


class MyDelegate : public QStyledItemDelegate
{
  Q_OBJECT
public:
  MyDelegate(QObject *parent = 0);
  void setFocusBorderEnabled(bool enabled);
  void paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& i ) const;
  QWidget* createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
  { return Q_NULLPTR; }
protected:
  bool f_focus_border_enabled;


};

#endif // MYDELEGATE_H
