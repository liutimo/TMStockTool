#include "realtimedatamodel.h"

RealTimeDataModel::RealTimeDataModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int RealTimeDataModel::rowCount(const QModelIndex &parent) const
{
    return mData.size();
}

int RealTimeDataModel::columnCount(const QModelIndex &parent) const
{
    // code -- name -- raise per
    return 4;
}

QVariant RealTimeDataModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (index.row() >= mData.size()) {
        return QVariant();
    }

    const auto &rtData = mData[row];

    //TODO: 如何根据配置文件动态设置列数据
    if (role == Qt::DisplayRole) {
        if (col == 0) {
            return QString::fromStdString(rtData.getCode());
        } else if (col == 1) {
            return QString::fromStdString(rtData.getName());
        } else if (col == 2) {
            return QString("%1%").arg(rtData.getIncQuota(), 0, 'f', 2);
        } else if (col == 3) {
            auto rate = rtData.getIncRate();
            QString formatStr = rate >= 0 ? "+%1%" : "%1%";
            return QVariant(formatStr.arg(rate, 0, 'f', 2));
        }
    }

    return QVariant();
}

void RealTimeDataModel::setData(const QVector<RTData> &data)
{
    mData = data;
}


