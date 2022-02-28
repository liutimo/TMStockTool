#include "utility.h"
#include <QObject>

#ifndef Q_OS_WIN
QString gbkStdString2QString(const std::string &gbkStr)
{
    QTextCodec* pCodec = QTextCodec::codecForName("GB18030");
    if (!pCodec) {
        return "";
    }
    return pCodec->toUnicode(gbkStr.c_str(), gbkStr.size());
}

#endif
