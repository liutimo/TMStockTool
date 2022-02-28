#include "widget.h"
#include "mainwidget.h"
#include <QHotkey>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

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


    return a.exec();
}
