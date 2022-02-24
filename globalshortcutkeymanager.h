#ifndef GLOBALSHORTCUTKEYMANAGER_H
#define GLOBALSHORTCUTKEYMANAGER_H

#include <QObject>

class GlobalShortCutKeyManager : public QObject
{
    Q_OBJECT

private:
    explicit GlobalShortCutKeyManager(QObject *parent = nullptr);


    GlobalShortCutKeyManager(const GlobalShortCutKeyManager&) = delete;
    GlobalShortCutKeyManager& operator=(const GlobalShortCutKeyManager&) = delete;

};

#endif // GLOBALSHORTCUTKEYMANAGER_H
