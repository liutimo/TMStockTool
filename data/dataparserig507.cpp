#include "dataparserig507.h"
#include <cpprest/json.h>

using namespace web;

DataParserIG507::DataParserIG507()
{

}

RTData DataParserIG507::parseRTData(const std::string &originData)
{
    return {};
}

std::vector<RTData> DataParserIG507::parseRTDatas(const std::string &originData)
{
    return {};
}

std::vector<StockBase> DataParserIG507::parseAllBigAStock(const std::string &originData)
{
    json::value values = json::value::parse(originData);

    json::array arr = values.as_array();

    std::vector<StockBase> stockBases;
    for (const json::value& value : arr) {
        std::string mc  = utility::conversions::to_utf8string(value.at(U("mc")).as_string());
        std::string dm  = utility::conversions::to_utf8string(value.at(U("dm")).as_string());
        std::string jys = utility::conversions::to_utf8string(value.at(U("jys")).as_string());
        stockBases.emplace_back(jys + dm, mc);
    }
    return stockBases;
}


