#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <string>
#include <vector>

class DataSource {
public:
    /**
     * @brief getRealtimeData
     * @param code 股票代码
     * @return 未解析的交易数据。
     */
    virtual std::string getRealtimeData(const std::string& codes) = 0;
};

#endif // DATASOURCE_H
