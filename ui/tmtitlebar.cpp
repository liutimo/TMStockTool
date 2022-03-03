#include "tmtitlebar.h"
#include "ui_tmtitlebar.h"

TMTitleBar::TMTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TMTitleBar)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowTransparentForInput, true);
}

TMTitleBar::~TMTitleBar()
{
    delete ui;
}
