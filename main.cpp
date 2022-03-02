#include "widget.h"
#include "mainwidget.h"
#include <QHotkey>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "db/persistentdatadb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TimoStockTool_" + QLocale(locale).name();
        if (translator.load(baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //init db
    if (PersistentDataDB::instance().init("XXX", "XXX", "XXX", "XXX")) {
        qDebug() << "DB init success!";
    } else {
        qDebug() << "DB init error! Process will exit soon!";
        a.exit();
        return 0;
    }

    Widget w;
    w.show();

    QHotkey hotkey(QKeySequence("Ctrl+T"), true, &a);

    QObject::connect(&hotkey, &QHotkey::activated, qApp, [&](){
        if (w.isHidden()) {
            w.show();
        } else {
            w.hide();
        }
    });



//    CREATE TABLE stock.follow_stock (
//        id INT UNSIGNED auto_increment NOT NULL,
//        stock_code varchar(100) NOT NULL COMMENT '股票代码 sz301111',
//        cost_price varchar(100) NULL COMMENT '成本',
//        hold_count INT UNSIGNED NULL COMMENT '持仓数量 单位为股'
//    )
//    ENGINE=InnoDB
//    DEFAULT CHARSET=utf8
//    COLLATE=utf8_general_ci
//    COMMENT='云端保存TMStockTool中的关注股票信息';


    return a.exec();
}
