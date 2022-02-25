#include "widget.h"
#include "ui_widget.h"
#include "realtimedatamodel.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : FramelessWidgetImpl(true, parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    RealTimeDataModel *model = new RealTimeDataModel();

    QVector<RTData> data;
    data.append(RTData("301111", "11", 100.00f, 50.00f, 100.00f));
    data.append(RTData("302222", "222", 100.00f, 50.00f, 100.00f));
    data.append(RTData("303333", "333", 100.00f, 50.00f, 100.00f));
    model->setData(data);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QBrush brush(QColor::fromRgb(255, 255, 255, 122));

    painter.setBrush(brush);
    painter.fillRect( 10, 10, 300, 300, Qt::SolidPattern );
}

