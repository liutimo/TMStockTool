#ifndef UTILITY_H
#define UTILITY_H
#include <QString>
#include <string>

#ifndef Q_OS_WIN

#include <QTextCodec>

QString gbkStdString2QString(const std::string& gbkStr);

#endif

#endif // UTILITY_H
