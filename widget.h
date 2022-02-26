#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "framelesswidget/framelesswidgetimpl.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class RealTimeDataModel;
class QSystemTrayIcon;
class SettingsWidget;

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
    void initSystemTray();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;

    QTimer *mTimer = nullptr;
    RealTimeDataModel *mDataModel = nullptr;
    QSystemTrayIcon *mSystemTray = nullptr;
    SettingsWidget* mSettingsWidget = nullptr;
};
#endif // WIDGET_H
