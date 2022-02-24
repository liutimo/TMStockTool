#ifndef DATASOURCESINA_H
#define DATASOURCESINA_H

#include "datasource.h"
#include <cpprest/http_client.h>

class DataSourceSina : public DataSource
{
public:
    DataSourceSina();

    std::string getRealtimeData(const std::string &codes) override;

private:
    static const std::string HOST;
    web::json::value REQUEST_PARAM;
};

#endif // DATASOURCESINA_H
