﻿#include "customtablemodel.h"

#include <QVector>
#include <QTime>
#include <QRect>
#include <QColor>

CustomTableModel::CustomTableModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    m_columnCount = 4;
    m_rowCount = 16;

    for(int i = 0; i < m_rowCount; i++) {
        QVector<qreal> * dataVec = new QVector<qreal> (m_columnCount);
        for(int k = 0; k < dataVec->size(); k++) {
            if(k % 2 == 0) {
                dataVec->replace(k, i * 50 + qrand() % 20);
            } else {
                dataVec->replace(k,  qrand() % 100);
            }
        }
        m_data.append(dataVec);
    }
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_rowCount;
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole) {
        return QVariant();
    }
    if(orientation == Qt::Horizontal) {
        if(section % 2 == 0) {
            return "x";
        } else {
            return "y";
        }
    } else {
        return QString("%1").arg(section + 1);
    }
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) {
        return m_data[index.row()]->at(index.column());
    } else if(role == Qt::EditRole) {
        return m_data[index.row()]->at(index.column());
    } else if(role == Qt::BackgroundRole) {
        foreach (QRect rect, m_mapping) {
            if(rect.contains(index.column(), index.row())) {
                return QColor(m_mapping.key(rect));
            }
        }
        return QColor(Qt::white);
    }

    return QVariant();
}

bool CustomTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole) {
        m_data[index.row()]->replace(index.column(), value.toDouble());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) |Qt::ItemIsEditable;
}

void CustomTableModel::addMapping(QString color, QRect area)
{
    m_mapping.insert(color, area);
}
