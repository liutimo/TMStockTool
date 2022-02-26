#include "realtimedatamodel.h"
#include <QColor>
#include <QTextCodec>
#include "utility.h"

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
            //可能有中文，需要转换编码
#ifdef Q_OS_WIN
            return QString::fromLocal8Bit(rtData.getName());
#else
            return gbkStdString2QString(rtData.getName());
#endif
        } else if (col == 2) {
            return QString("%1").arg(rtData.getIncQuota(), 0, 'f', 2);
        } else if (col == 3) {
            auto rate = rtData.getIncRate();
            QString formatStr = rate >= 0 ? "+%1%" : "%1%";
            return QVariant(formatStr.arg(rate, 0, 'f', 2));
        }
    } else if (role == Qt::ForegroundRole) {
        if (col == 3 || col == 2) {
            if (rtData.getIncRate() > 0.0f) {
                return QColor::fromRgb(255, 0, 0);
            } else {
                return QColor::fromRgb(0, 255, 0);
            }
        }
    }

    return QVariant();
}

void RealTimeDataModel::setData(const std::vector<RTData> &data)
{
    beginResetModel();
    mData = data;
    endResetModel();
    //为什么不行呢
//    emit dataChanged(index(0, 0), index(mData.size(), columnCount()));
}


