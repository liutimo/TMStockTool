#include "widget.h"
#include "mainwidget.h"
#include <QHotkey>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "db/persistentdatadb.h"
#include "data/datasourcemanager.h"
#include "data/datasourceig507.h"
#include <QSqlDatabase>

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
    if (PersistentDataDB::instance().init("119.91.147.106", "stock", "liutimo", "lz779564531")) {
        qDebug() << "DB init success!";
    } else {
        qDebug() << "DB init error! Process will exit soon!";
        a.exit();
        return 0;
    }

//    FramelessWidgetImpl w(true);

//    w.show();

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
    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
