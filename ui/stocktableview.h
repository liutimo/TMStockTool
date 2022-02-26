#ifndef STOCKTABLEVIEW_H
#define STOCKTABLEVIEW_H

#include <QTableView>

class StockTableView : public QTableView
{
    Q_OBJECT
public:
    StockTableView(QWidget *parent = nullptr);
};

#endif // STOCKTABLEVIEW_H
