#include "stockwidget.h"
#include "ui_stockwidget.h"

#include <QCompleter>
#include <QStandardItemModel>
#include <QStringList>
#include <QStringListModel>
#include <QTableView>

StockWidget::StockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockWidget)
{
    ui->setupUi(this);

    QCompleter *mCompleter = new QCompleter(this);

    auto* model = new StockInfoModel();
    model->updateData();
    mCompleter->setModel(model);
    mCompleter->setFilterMode(Qt::MatchContains);
    mCompleter->setPopup(new QTableView());
    ui->lineEdit->setCompleter(mCompleter);
}

StockWidget::~StockWidget()
{
    delete ui;
}

StockInfoModel::StockInfoModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int StockInfoModel::rowCount(const QModelIndex &parent) const
{
    return mRow1.size();
}

int StockInfoModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant StockInfoModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole || Qt::DisplayRole) {
        return mRow1[row];
    }

    return {};
}

void StockInfoModel::updateData()
{
    for (int i = 0; i < mRow1.size(); ++i) {
        QModelIndex col1 = index(i, 0);
        QModelIndex col2 = index(i, 1);
        setData(col1, QString::number(i) + "222");
        setData(col2, QString::number(i) + "333");
    }
}
