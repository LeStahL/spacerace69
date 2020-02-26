#ifndef FONTMODEL_HPP
#define FONTMODEL_HPP

#include <QAbstractTableModel>
#include <QObject>
#include <QModelIndex>
#include <QVariant>

#include "Font.hpp"

class FontModel : public QAbstractTableModel
{
public:
    FontModel(QObject *parent = nullptr);
    virtual ~FontModel() = default;
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

#endif
