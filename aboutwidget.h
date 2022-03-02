#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>

#include "framelesswidget/framelesswidgetimpl.h"

namespace Ui {
class AboutWidget;
}

class AboutWidget : public FramelessWidget
{
    Q_OBJECT

public:
    explicit AboutWidget(QWidget *parent = nullptr);
    ~AboutWidget();

private:
    Ui::AboutWidget *ui;
};

#endif // ABOUTWIDGET_H
