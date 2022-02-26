#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "framelesswidget/framelesswidgetimpl.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class RealTimeDataModel;

class Widget : public FramelessWidgetImpl
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void initUI();
    void initTimer();
    void initTableView();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;

    QTimer *mTimer = nullptr;
    RealTimeDataModel *mDataModel = nullptr;
};
#endif // WIDGET_H
