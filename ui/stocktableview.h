#ifndef STOCKTABLEVIEW_H
#define STOCKTABLEVIEW_H

#include <QTableView>

class StockTableView : public QTableView
{
    Q_OBJECT
public:
    StockTableView(QWidget *parent = nullptr, bool showMenu = true);

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    void initMenu();

private:
    int mCurrentRow = -1;
    QMenu *mContextMenu = nullptr;
};

#endif // STOCKTABLEVIEW_H
