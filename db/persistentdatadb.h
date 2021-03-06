#ifndef PERSISTENTDATADB_H
#define PERSISTENTDATADB_H

#include "persistentdata.h"

class QSqlDatabase;

class PersistentDataDB : public PersistentDataInterface
{

private:
    PersistentDataDB() = default;

public:

    ~PersistentDataDB();

    static PersistentDataDB& instance() {
        return mInstance;
    }


    bool init(const QString& host, const QString& dbname, const QString& username, const QString& password);

    int getHoldCount(const QString &code) const override;

    float getCostPrice(const QString &code) const override;

    bool setFollowStockInfo(const QString& code, float costPirce = 0.0f, int holdCount = 0) const override;

    QVector<QString> getFollowStockList() const override;


    bool deleteOneFollowStock(const QString& code) const override;

    bool stickyOneFollowStock(const QString& code, bool sticky) const override;
private:
    QSqlDatabase* mDb;

    static PersistentDataDB mInstance;
};

#endif // PERSISTENTDATADB_H
