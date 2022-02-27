#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>

namespace Ui {
class StockWidget;
}

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
    QVector<QString> mRow1 = {"11", "12", "13", "14", "15"};
    QVector<QString> mRow2 = {"21", "22", "23", "24", "25"};
};


class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

private:
    Ui::StockWidget *ui;
};

#endif // STOCKWIDGET_H
