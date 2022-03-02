#include "persistentdatadb.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

PersistentDataDB PersistentDataDB::mInstance;

PersistentDataDB::~PersistentDataDB()
{
    if (mDb) {
        mDb->close();
        delete mDb;
    }
}

bool PersistentDataDB::init(const QString &host, const QString &dbname, const QString &username, const QString &password)
{
    mDb = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
    mDb->setHostName(host);
    mDb->setDatabaseName(dbname);
    mDb->setUserName(username);
    mDb->setPassword(password);
    if (!mDb->open()) {
        qDebug() << mDb->lastError().text();
        delete mDb;
        mDb = nullptr;
        return false;
    }
    return true;
}

int PersistentDataDB::getHoldCount(const QString &code) const
{
    QString sqlGetHoldCount = "select hold_count from follow_stocks where code = ?";

    QSqlQuery query;
    if (query.prepare(sqlGetHoldCount)) {
        query.addBindValue(code);
    }

    if (query.exec()) {
        if (query.next()) {
            return query.value("hold_count").toInt();
        }
    }

    return -1;
}

float PersistentDataDB::getCostPrice(const QString &code) const
{
    QString sqlGetCostPrice = "select cost_price from follow_stocks where code = ?";

    QSqlQuery query;
    if (query.prepare(sqlGetCostPrice)) {
        query.addBindValue(code);
    }

    if (query.exec()) {
        if (query.next()) {
            return query.value("cost_price").toFloat();
        }
    }

    //FIX COST PRICE CAN BE 0?
    return 0.0f;
}

bool PersistentDataDB::setFollowStockInfo(const QString &code, float costPirce, int holdCount) const
{
    QString sqlSetFollowStockInfo = "insert into follow_stocks (code, hold_count, cost_price) values(?, ?, ?)";

    QSqlQuery query;
    if (query.prepare(sqlSetFollowStockInfo)) {
        query.addBindValue(code);
        query.addBindValue(costPirce);
        query.addBindValue(holdCount);
    }

    if (query.exec()) {
        return true;
    }
    qDebug() << query.lastError().text();
    return false;
}

QVector<QString> PersistentDataDB::getFollowStockList() const
{
    QString sqlGetHoldCount = "select code from follow_stocks";

    QSqlQuery query;
    if (query.exec(sqlGetHoldCount)) {
        QVector<QString>  result;
        while (query.next()) {
            result.emplace_back(query.value("code").toString());
        }
        return result;
    }

    return {};
}
