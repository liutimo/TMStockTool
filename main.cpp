#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "data/datasourcesina.h"
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TimoStockTool_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

//    http_client client(U("https://hq.sinajs.cn/"));
//    uri_builder builder(U("/etag.php"));
//    builder.append_query(U("_list"), U("sz301111"));

//   http_request request(methods::GET);
//   request.headers().add(U("Referer"), U("https://finance.sina.com.cn"));
//   request.set_request_uri(builder.to_string());
//   auto response = client.request(request).get();

    qDebug() << DataSourceSina().getRealtimeData("sz301111").c_str();

    Widget w;
    w.show();


    return a.exec();
}