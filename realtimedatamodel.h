#ifndef REALTIMEDATAMODEL_H
#define REALTIMEDATAMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QVariant>
#include "data/data.h"

class RealTimeDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit RealTimeDataModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void setData(const QVector<RTData>& data);
private:
    QVector<RTData> mData;
};

#endif // REALTIMEDATAMODEL_H
