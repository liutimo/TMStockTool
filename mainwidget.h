#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMap>
#include "framelesswidget/framelesswidgetimpl.h"
namespace Ui {
class MainWidget;
}

class MainWidget : public FramelessWidgetImpl
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    int addNavItem(const QString& name, QWidget*w);

    void switchToWidgetByID(int id);


    void initTitleBar();
private:
    Ui::MainWidget *ui;

    void initUI();


    QWidget *mCurrentWidget;
    QMap<int, QWidget*> mWidgets;

};

#endif // MAINWIDGET_H
