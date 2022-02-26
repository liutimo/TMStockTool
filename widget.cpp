#include "widget.h"
#include "ui_widget.h"
#include "realtimedatamodel.h"
#include <QPainter>
#include <QPalette>
#include <QTimer>
#include <QDebug>
#include "data/datasourcemanager.h"

Widget::Widget(QWidget *parent)
#ifdef USB_FRAMELESS_WIDGET
    : FramelessWidgetImpl(true, parent)
#else
    : FramelessWidgetImpl(parent)
#endif
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUI();
    initTimer();
    initTableView();
}

Widget::~Widget()
{
    delete ui;

    if (mTimer != nullptr && mTimer->isActive()) {
        mTimer->stop();
    }
}

void Widget::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->label->setText(tr("Updated Time:"));
}

void Widget::initTimer()
{
    mTimer = new QTimer(this);
    //TODO: 修改为可动态配置
    mTimer->setInterval(1000);

    connect(mTimer, &QTimer::timeout, this, [this](){
        //更新 UI 数据
        auto datas = DataSourceManager().getRTDatas({"sz301111", "sz300750"});
        if (datas.size() > 0) {
            ui->labelUpdateTime->setText(QString::fromStdString(datas[0].getUpdatedTime()));
        }
        mDataModel->setData(datas);
        qDebug() << "Data Updated";
    });

    mTimer->start();
}

void Widget::initTableView()
{
    mDataModel = new RealTimeDataModel(this);
    ui->tableView->setModel(mDataModel);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255, 1));

    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}

