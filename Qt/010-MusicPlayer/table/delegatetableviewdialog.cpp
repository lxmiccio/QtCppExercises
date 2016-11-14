#include "delegatetableviewdialog.h"

#include <QDebug>
#include <QGridLayout>
#include <QHeaderView>

DelegateTableViewDialog
::DelegateTableViewDialog(QWidget *parent) :
  QDialog(parent)
{

  // Create a new model
  // QStandardItemModel(int rows, int columns, QObject * parent = 0)
  model = new QStandardItemModel(4,4,this);
  // Generate data
  for(int row = 0; row < 4; row++)
  {
    for(int col = 0; col < 4; col++)
    {
      QModelIndex index
          = model->index(row,col,QModelIndex());

      // 0 for all data
      model->setData(index,0);
    }
  }
  // Attach (tie) the model to the view
  //ui->tableView->setModel(model);
  //ui->tableView->setShowGrid(false);
  //ui->tableView->horizontalHeader()->setVisible(false);
  //ui->tableView->verticalHeader()->setVisible(false);
  //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableView = new TableView(this);
  tableView->setStyleSheet("QHeaderView {background-color: transparent;}");
  //tableView->hideColumn(0);
  tableView->horizontalHeader()->hide();
  tableView->verticalHeader()->hide();
  tableView->setModel(model);
  tableView->setShowGrid(false);
  tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

  QList<QStandardItem*> t = QList<QStandardItem*>();
  QStandardItem * si = new QStandardItem("tove");
  t.append(si);
  t.append(new QStandardItem("evot"));
  model->appendRow(t);
  QList<QStandardItem*> t2 = QList<QStandardItem*>();
  QStandardItem * si2 = new QStandardItem("tove");
  t2.append(si2);
  t2.append(new QStandardItem("ol ewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwot"));
  model->appendRow(t2);

  this->myDelegate = new MyDelegate(tableView);
  tableView->setItemDelegate(myDelegate);
  //ui->tableView->setItemDelegate(myDelegate);

  //connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex &)));
  connect(tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(itemClicked(const QModelIndex &)));
tableView->setFixedSize(300, 150);

  // Tie the View with the new MyDelegate instance
  // If we don not set this, it will use default delegate
  //ui->tableView->resizeColumnsToContents();
  //ui->tableView->setFixedSize(100,100);

  QGridLayout *gl = new QGridLayout();
  gl->setMargin(30);
  gl->addWidget(tableView,0,0,1,1);

  this->setLayout(gl);
}

void DelegateTableViewDialog::itemClicked(const QModelIndex& tove)
{
  qDebug() << tove.sibling(tove.row(), 0).data();
  qDebug() << tove.sibling(tove.row(), 1).data();

}

