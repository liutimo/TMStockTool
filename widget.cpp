#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    this->setWindowFlags(Qt::FramelessWindowHint);
//       this->setAttribute(Qt::WA_TranslucentBackground, true);
//    ui->tableWidget->setStyleSheet("background-color:rgba(0,0,0,0)");

//    ui->tableWidget->setWindowFlags(Qt::FramelessWindowHint);

//    ui->tableWidget->setAttribute(Qt::WA_TranslucentBackground, true);


//    ui->tableView->setModel();

}

Widget::~Widget()
{
    delete ui;
}

