#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "stockwidget.h"
#include "settingswidget.h"
#include <QLabel>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget), mCurrentWidget(nullptr)
{
    ui->setupUi(this);

    initUI();
}

MainWidget::~MainWidget()
{
    delete ui;
}

int MainWidget::addNavItem(const QString &name, QWidget *w)
{
    auto id = ui->navPanel->addNavItem(name);
    mWidgets.insert(id, w);
    return id;
}


void MainWidget::switchToWidgetByID(int id)
{
    if (!mWidgets.contains(id)) {
        return;
    }
    layout()->addWidget(mWidgets[id]);
    mWidgets[id]->show();

    if (mCurrentWidget && mCurrentWidget != mWidgets[id]) {
        layout()->removeWidget(mCurrentWidget);
        mCurrentWidget->hide();
    }

    mCurrentWidget = mWidgets[id];
}

void MainWidget::initUI()
{
    //1. Stock Widget
    int defaultId = addNavItem("Stock", new StockWidget());
    ui->navPanel->setCheckNavItemByID(defaultId);
    switchToWidgetByID(defaultId);


    // Settings Widget
    addNavItem("Settings", new SettingsWidget);



    // init NavPanel
    ui->navPanel->setFixedWidth(150);
    ui->navPanel->setOrientation(TMNavPanel::NavOrientation::VERTIAL);
    connect(ui->navPanel, &TMNavPanel::navItemChanged, this, &MainWidget::switchToWidgetByID);
}
