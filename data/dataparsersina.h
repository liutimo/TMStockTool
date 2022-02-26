#ifndef DATAPARSERSINA_H
#define DATAPARSERSINA_H

#include "dataparser.h"

class DataParserSina : public DataParser
{
public:
    DataParserSina();

    RTData parserRTData(const std::string &originData) override;

    std::vector<RTData> parserRTDatas(const std::string& originData) override;
};

#endif // DATAPARSERSINA_H
