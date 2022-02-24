#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>

namespace Ui {
class StockWidget;
}

class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

private:
    Ui::StockWidget *ui;
};

#endif // STOCKWIDGET_H
