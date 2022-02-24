#ifndef DATAPARSERSINA_H
#define DATAPARSERSINA_H

#include "dataparser.h"

class DataParserSina : public DataParser
{
public:
    DataParserSina();

    RTData parserRTData(const std::string &originData) override;

    const std::string &getHOST() const;

};

#endif // DATAPARSERSINA_H
