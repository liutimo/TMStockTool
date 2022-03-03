#include "widget.h"
#include "ui_widget.h"
#include "realtimedatamodel.h"
#include <QPainter>
#include <QPalette>
#include <QTimer>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMenu>
#include "mainwidget.h"
#include "aboutwidget.h"
#include "data/datasourcemanager.h"
#include "db/persistentdatadb.h"

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
    initSystemTray();
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
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
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
        std::vector<std::string> stocks;
        auto qstocks = PersistentDataDB::instance().getFollowStockList();
        for (auto const & stock : qstocks) {
            stocks.push_back(stock.toStdString());
        }

        auto datas = DataSourceManager().getRTDatas(stocks);
        if (datas.size() > 0) {
            ui->labelUpdateTime->setText(QString::fromStdString(datas[0].getUpdatedTime()));
            mDataModel->setData(datas);
        }
    });

    mTimer->start();
}

void Widget::initTableView()
{
    mDataModel = new RealTimeDataModel(this);
    ui->tableView->setModel(mDataModel);
//    ui->tableView->setAttribute(Qt::WA_TransparentForMouseEvents,true);
}

void Widget::initSystemTray()
{
    mSystemTray = new QSystemTrayIcon(this);
    mSystemTray->setIcon(QIcon(":/imgs/imgs/stock.png"));


    QMenu *menu = new QMenu(this);
    QAction* actionExit             = new QAction(tr("Exit"), this);
    QAction* actionAbout            = new QAction(tr("About"), this);
    QAction* actionSettings         = new QAction(tr("Settings"), this);
    QAction* actionShowMainWidget   = new QAction(tr("Show Main Widget"), this);


    menu->addAction(actionShowMainWidget);
    menu->addAction(actionSettings);
    menu->addAction(actionAbout);
    menu->addAction(actionExit);

    mSystemTray->setContextMenu(menu);
    mSystemTray->show();

    connect(actionShowMainWidget, &QAction::triggered, this, [this](){
        if (isHidden()) {
            show();
        } else {
            hide();
        }
    });

    connect(actionSettings, &QAction::triggered, this, [this](){
        if (mMainWidget == nullptr) {
            mMainWidget = new MainWidget();
        }
        mMainWidget->show();
    });

    connect(actionAbout, &QAction::triggered, this, [this](){
        if (mAboutWidget == nullptr) {
            mAboutWidget = new AboutWidget();
        }
        mAboutWidget->show();
    });

    connect(actionExit, &QAction::triggered, this, [this]() {
        qApp->quit();
    });
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255, 1));

    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}

