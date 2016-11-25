#include "TrackView.h"

#include <QHeaderView>
#include <QResizeEvent>
#include <QScrollBar>

TrackView::TrackView(QWidget* parent) : QWidget(parent)
{
    m_tableView = new TrackTableView();
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableView->horizontalHeader()->hide();
    m_tableView->verticalHeader()->hide();
    m_tableView->setShowGrid(false);

    m_delegate = new TrackDelegate(m_tableView);
    m_tableView->setItemDelegate(m_delegate);

    m_model = new QStandardItemModel();
    m_tableView->setModel(m_model);

    QObject::connect(m_tableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClicked(const QModelIndex&)));

    m_items = QVector<TrackItem*>();
}

TrackView::~TrackView()
{
    foreach (TrackItem* i_trackItem, m_items)
        delete i_trackItem;

    delete m_model;
    delete m_tableView;
}

void TrackView::onAlbumSelected(const Album& album)
{
    for(QVector<Track>::iterator i_track = album.tracks()->begin(); i_track != album.tracks()->end(); ++i_track)
    {
        TrackItem* item = new TrackItem(i_track);
        m_items.push_back(item);
        m_model->appendRow(item->items());
    }
}

void TrackView::onDoubleClicked(const QModelIndex& index)
{
    const Track* track = m_items.at(index.row())->track();
    emit doubleClicked(*track);
}
