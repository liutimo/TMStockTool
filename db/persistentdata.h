#ifndef PERSISTENTDATA_H
#define PERSISTENTDATA_H

#include <QObject>
#include <QVector>
#include <QString>

class PersistentDataInterface {
public:

//    virtual ~PersistentDataInterface() = 0;

    virtual int getHoldCount(const QString &code) const = 0;

    virtual float getCostPrice(const QString &code) const = 0;

    virtual bool setFollowStockInfo(const QString& code, float costPirce, int holdCount) const = 0;

    virtual QVector<QString> getFollowStockList() const = 0;

    virtual bool deleteOneFollowStock(const QString& code) const = 0;
};

#endif // PERSISTENTDATA_H
