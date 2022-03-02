#ifndef DATAPARSERIG507_H
#define DATAPARSERIG507_H

#include "dataparser.h"

class DataParserIG507 : public DataParser
{
public:
    DataParserIG507();

    RTData parseRTData(const std::string &originData) override;

    std::vector<RTData> parseRTDatas(const std::string& originData) override;

    std::vector<StockBase> parseAllBigAStock(const std::string& originData) override;
};

#endif // DATAPARSERIG507_H
