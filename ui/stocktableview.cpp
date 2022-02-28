#include "stocktableview.h"
#include <QHeaderView>
#include <QDebug>
#include <QEvent>
#include <QMenu>
StockTableView::StockTableView(QWidget *parent) : QTableView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    horizontalHeader()->hide();
    verticalHeader()->hide();

    setSelectionMode(QAbstractItemView::NoSelection);
//    setSelectionBehavior(QAbstractItemView::SelectRows);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setShowGrid(false);
    setFocusPolicy(Qt::NoFocus);
    setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);

    installEventFilter(this);

    initMenu();
}

bool StockTableView::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj == this) {
        if (ev->type() == QEvent::ContextMenu) {
            if (indexAt(mapFromGlobal(cursor().pos())).isValid()) {
                mContextMenu->exec(cursor().pos());
            }
        }
    }
    return QWidget::eventFilter(obj, ev);
}

void StockTableView::initMenu()
{
    mContextMenu = new QMenu(this);
    auto *actionEdit = mContextMenu->addAction(tr("Edit"));
    auto *actionDelete = mContextMenu->addAction(tr("Delete"));
    auto *actionMore = mContextMenu->addAction(tr("More Info"));

    connect(actionEdit, &QAction::triggered, this, [&]() {
        int row = indexAt(mapFromGlobal(cursor().pos())).row();
        //TODO: 如何将管理的数据和UI解耦呢
    });

    connect(actionDelete, &QAction::triggered, this, [&](){

    });

    connect(actionMore, &QAction::triggered, this, [&](){

    });
}


