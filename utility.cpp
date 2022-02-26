#include "utility.h"
#include <QObject>

QString gbkStdString2QString(const std::string &gbkStr)
{
    QTextCodec* pCodec = QTextCodec::codecForName("GB18030");
    if (!pCodec) {
        return "";
    }
    return pCodec->toUnicode(gbkStr.c_str(), gbkStr.size());
}
