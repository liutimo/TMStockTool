#ifndef DATASOURCEIG507_H
#define DATASOURCEIG507_H

#include "data.h"
#include "datasource.h"

class DataSourceIG507 : public DataSource
{
public:
    DataSourceIG507();

    std::string getRealtimeData(const std::string &code) override;

    std::string getBatchRealtimeData(const std::vector<std::string>& codes) override;

    std::string getAllBigAStock() override;
private:
    static const std::string LICENCE;
    static const std::string BASE_URI;
};

#endif // DATASOURCEIG507_H
