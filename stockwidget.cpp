#include "stockwidget.h"
#include "ui_stockwidget.h"

#include "data/datasourcemanager.h"
#include <QCompleter>
#include <QStandardItemModel>
#include <QStringList>
#include <QStringListModel>
#include <QTableView>
#include "ui/stocktableview.h"
#include "db/persistentdatadb.h"

StockWidget::StockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockWidget)
{
    ui->setupUi(this);

    initFollow();

    QCompleter *mCompleter = new QCompleter(this);

    auto* model = new StockInfoModel();
    model->updateData();
    mCompleter->setModel(model);
    mCompleter->setFilterMode(Qt::MatchContains);
    mCompleter->setPopup(new StockTableView(nullptr, false));
    ui->lineEdit->setCompleter(mCompleter);
}

StockWidget::~StockWidget()
{
    delete ui;
}

void StockWidget::initFollow()
{
    connect(ui->btnFollow, &QPushButton::clicked, this, [this](){
        QString code = ui->lineEdit->text();
        //TODO: 正则判断code是否合法
        PersistentDataDB::instance().setFollowStockInfo(code);
        ui->lineEdit->clear();
    });
}

StockInfoModel::StockInfoModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    mStocks = DataSourceManager().getAllBigAStock();
}

int StockInfoModel::rowCount(const QModelIndex &parent) const
{
    return mStocks.size();
}

int StockInfoModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant StockInfoModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole || role == Qt::DisplayRole) {
        if (col == 0) {
            return QString::fromStdString(mStocks[row].getCode());
        } else if (col == 1) {
            return QString::fromStdString(mStocks[row].getName());
        }
    }

    return {};
}

void StockInfoModel::updateData()
{
    for (int i = 0; i < mStocks.size(); ++i) {
        QModelIndex col1 = index(i, 0);
        QModelIndex col2 = index(i, 1);
        setData(col1, QString::fromStdString(mStocks[i].getCode()));
        setData(col2, QString::fromStdString(mStocks[i].getName()));
    }
}
