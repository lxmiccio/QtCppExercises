#include "TrackView.h"

#include <QHeaderView>
#include <QResizeEvent>
#include <QScrollBar>

#include "ImageUtils.h"

TrackView::TrackView(QWidget* parent) : QWidget(parent)
{
    m_albumView = new AlbumWidget();

    m_spacer = new QSpacerItem(16, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_tableList = new TrackList();
    m_tableList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableList->setShowGrid(false);
    m_tableList->horizontalHeader()->hide();
    m_tableList->verticalHeader()->hide();
    QObject::connect(m_tableList, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClicked(const QModelIndex&)));

    m_layout = new QHBoxLayout();
    m_layout->setContentsMargins(40, 16, 40, 8);
    m_layout->addWidget(m_albumView);
    m_layout->addItem(m_spacer);
    m_layout->addWidget(m_tableList);
    setLayout(m_layout);

    m_delegate = new TrackDelegate(m_tableList);
    m_tableList->setItemDelegate(m_delegate);

    m_model = new QStandardItemModel();
    m_tableList->setModel(m_model);

    m_items = QVector<TrackItem*>();

    setMinimumHeight(TrackView::WIDGET_HEIGHT);
}

TrackView::~TrackView()
{
    /*
    foreach (TrackItem* i_trackItem, m_items)
        delete i_trackItem;

    delete m_model;
    delete m_tableList;
    delete m_layout;
    */
}

void TrackView::onAlbumSelected(const Album& album)
{
    clear();

    foreach(Track* i_track, album.tracks())
    {
        TrackItem* item = new TrackItem(i_track);
        m_items.push_back(item);
        m_model->appendRow(item->items());
    }

    m_albumView->setAlbum(&album);
}

void TrackView::onDoubleClicked(const QModelIndex& index)
{
    const Track* track = m_items.at(index.row())->track();
    emit doubleClicked(*track);
}

void TrackView::clear()
{
    foreach(TrackItem* i_item, m_items)
        delete i_item;
    m_items.clear();

    m_model->clear();
}
