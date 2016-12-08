#include "TrackModel.h"

TrackModel::TrackModel(QObject* parent) : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Track" << "Title" << "Duration";

    m_rootItem = new TrackItem(rootData);
}

TrackModel::~TrackModel()
{
    delete m_rootItem;
}

QVariant TrackModel::headerData(int column, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return m_rootItem->data(column);
    }

    return QVariant();
}

QVariant TrackModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    return static_cast<TrackItem*>(index.internalPointer())->data(index.column());
}

QModelIndex TrackModel::parent(const QModelIndex& index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }

    TrackItem* parent = static_cast<TrackItem*>(index.internalPointer())->parent();

    if (parent == m_rootItem)
    {
        return QModelIndex();
    }

    return createIndex(parent->row(), 0, parent);
}

QModelIndex TrackModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    TrackItem *parentItem;

    if (!parent.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TrackItem*>(parent.internalPointer());

    TrackItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

int TrackModel::rowCount(const QModelIndex& parent) const
{
    TrackItem *parentItem;

    if (!parent.isValid())
    {
        parentItem = m_rootItem;
    }
    else
    {
        parentItem = static_cast<TrackItem*>(parent.internalPointer());
    }

    return parentItem->rowCount();
}

int TrackModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TrackItem*>(parent.internalPointer())->columnCount();
    else
        return m_rootItem->columnCount();
}

Qt::ItemFlags TrackModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

void TrackModel::appendItem(const Track* track) {
    beginInsertRows(QModelIndex(), m_rootItem->row(), m_rootItem->row());
    m_rootItem->appendChild(new TrackItem(track, m_rootItem));
    endInsertRows();
}

void TrackModel::removeItem(int row)
{
    if(row < m_rootItem->rowCount())
    {
        this->beginRemoveRows(QModelIndex(), row, row);
        m_rootItem->removeChild(row);
        this->endRemoveRows();
    }
}

void TrackModel::clear()
{
    if(m_rootItem->rowCount() >= 0)
    {
        this->beginRemoveRows(QModelIndex(), 0, m_rootItem->rowCount() - 1);
        m_rootItem->clear();
        this->endRemoveRows();
    }
}
