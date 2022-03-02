#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <regex>
#include "data.h"

//解析各类数据
class DataParser {
public:
    virtual ~DataParser() {}


    virtual RTData parseRTData(const std::string &originData) = 0;

    virtual std::vector<RTData> parseRTDatas(const std::string& originData) = 0;

    virtual std::vector<StockBase> parseAllBigAStock(const std::string& originData) = 0;
};


std::vector<std::string> split(const std::string& s, const std::string& delimiters);

#endif // DATAPARSER_H
