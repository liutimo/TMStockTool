#include "tmtitlebar.h"
#include "ui_tmtitlebar.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>

TMTitleBar::TMTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TMTitleBar)
{
    ui->setupUi(this);
    ui->btnMax->hide();
    ui->btnMin->hide();
    connect(ui->btnClose, &QPushButton::clicked, this, [this](){
        QWidget* parent = qobject_cast<QWidget*>(this->parent());
        if (parent != nullptr) {
            parent->close();
        } else {
            close();
        }
    });
}

TMTitleBar::~TMTitleBar()
{
    delete ui;
}
void TMTitleBar::mousePressEvent(QMouseEvent *p_event)
{
    QWidget::mousePressEvent(p_event);

    mPressed = true;
    mPressPoint = p_event->pos();
}



void TMTitleBar::mouseReleaseEvent(QMouseEvent *p_event)
{
    QWidget::mouseReleaseEvent(p_event);
    mPressed = false;
}

void TMTitleBar::mouseMoveEvent(QMouseEvent *p_event)
{
    QWidget::mouseMoveEvent(p_event);

    if (!mPressed) {
        return;
    }

    QWidget* pWidget = qobject_cast<QWidget*>(parent());
    if (pWidget != nullptr) {
        pWidget->move(QCursor::pos() - mPressPoint);
    }
}

void TMTitleBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

