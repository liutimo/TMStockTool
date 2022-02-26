#ifndef DATASOURCESINA_H
#define DATASOURCESINA_H

#include "datasource.h"
#include <cpprest/http_client.h>

class DataSourceSina : public DataSource
{
public:
    DataSourceSina();

    std::string getRealtimeData(const std::string &code) override;

    std::string getBatchRealtimeData(const std::vector<std::string>& codes) override;

private:
    web::json::value REQUEST_PARAM;
};

#endif // DATASOURCESINA_H
