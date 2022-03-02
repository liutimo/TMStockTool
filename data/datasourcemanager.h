#ifndef DATASOURCEMANAGER_H
#define DATASOURCEMANAGER_H

#include "data.h"
#include "datasource.h"
#include "dataparser.h"

class DataSourceManagerInterface {
public:
    enum class DataSourceType {
        TYPE_SINA,
    };

public:

    virtual ~DataSourceManagerInterface() {};

    virtual RTData getRTData(const std::string& code) = 0;

    virtual std::vector<RTData> getRTDatas(const std::vector<std::string> &codes) = 0;

    /**
     * @brief getAllBigAStock 获取大A市场上的所有股票
     * @return
     * 目前仅返回包含股票名称和股票代码的StockBase vecotr。
     */
    virtual std::vector<StockBase> getAllBigAStock() = 0;
};



class DataSourceManager : public DataSourceManagerInterface
{
public:
    DataSourceManager();

    void setDataSourceType(DataSourceType type) {
        mDataSourceType = type;
    }

    RTData getRTData(const std::string& code) override;

    std::vector<RTData> getRTDatas(const std::vector<std::string> &codes) override;

    virtual std::vector<StockBase> getAllBigAStock() override;
private:
    DataSourceType mDataSourceType;

    DataSource* mDataSource;
    DataParser* mDataParser;
};

#endif // DATASOURCEMANAGER_H
