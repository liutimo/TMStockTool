#ifndef DATAPARSERSINA_H
#define DATAPARSERSINA_H

#include "dataparser.h"

class DataParserSina : public DataParser
{
public:
    DataParserSina();

    RTData parseRTData(const std::string &originData) override;

    std::vector<RTData> parseRTDatas(const std::string& originData) override;

    std::vector<StockBase> parseAllBigAStock(const std::string& originData) override;
};

#endif // DATAPARSERSINA_H
