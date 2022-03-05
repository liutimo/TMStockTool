#include "aboutwidget.h"
#include "ui_aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent) :
    FramelessWidget(true, parent),
    ui(new Ui::AboutWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("backgroud-color:green;");
}

AboutWidget::~AboutWidget()
{
    delete ui;
}
