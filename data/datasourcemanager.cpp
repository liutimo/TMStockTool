#include "datasourcemanager.h"
#include "datasourcesina.h"
#include "dataparsersina.h"

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

    return mDataParser->parserRTData(originData);
}

std::vector<RTData> DataSourceManager::getRTDatas(const std::vector<std::string> &codes)
{
    assert(mDataSource != nullptr);

    auto originData = mDataSource->getBatchRealtimeData(codes);

    return mDataParser->parserRTDatas(originData);
}
