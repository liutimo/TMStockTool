#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>

namespace Ui {
class StockWidget;
}

#include "data/data.h"
#include <QAbstractTableModel>
#include <QVector>


class StockInfoModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit StockInfoModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void updateData();
private:
    std::vector<StockBase> mStocks;
};


class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

private:

    void initFollow();

    Ui::StockWidget *ui;
};

#endif // STOCKWIDGET_H
