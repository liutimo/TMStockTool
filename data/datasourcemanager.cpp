#include "datasourcemanager.h"
#include "datasourcesina.h"
#include "dataparsersina.h"
#include "datasourceig507.h"
#include "dataparserig507.h"

#include <assert.h>

DataSourceManager::DataSourceManager() :
    mDataSourceType(DataSourceType::TYPE_SINA),  mDataSource(nullptr)
{
    if (mDataSourceType == DataSourceType::TYPE_SINA) {
        mDataSource = new DataSourceSina();
        mDataParser = new DataParserSina();
    }
}

RTData DataSourceManager::getRTData(const std::string &code)
{
    assert(mDataSource != nullptr);

    auto originData = mDataSource->getRealtimeData(code);

    return mDataParser->parseRTData(originData);
}

std::vector<RTData> DataSourceManager::getRTDatas(const std::vector<std::string> &codes)
{
    assert(mDataSource != nullptr);

    auto originData = mDataSource->getBatchRealtimeData(codes);

    return mDataParser->parseRTDatas(originData);
}

std::vector<StockBase> DataSourceManager::getAllBigAStock()
{
    //由于目前sina数据源没有接口直接获取股票列表，通过ig507接口来获取。
    assert(mDataSource != nullptr);

    auto originData = mDataSource->getAllBigAStock();

    auto bigAStocks = mDataParser->parseAllBigAStock(std::move(originData));

    if (bigAStocks.empty()) {
        //TODO:该接口比较重要，更换数据源重新获取。
        originData = DataSourceIG507().getAllBigAStock();
        bigAStocks = DataParserIG507().parseAllBigAStock(originData);
    }
    return bigAStocks;
}
