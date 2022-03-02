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

    bool setFollowStockInfo(const QString& code, float costPirce, int holdCount) const override;

    QVector<QString> getFollowStockList() const override;

private:
    QSqlDatabase* mDb;

    static PersistentDataDB mInstance;
};

#endif // PERSISTENTDATADB_H
