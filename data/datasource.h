#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <string>
#include <vector>

class DataSource {
public:
    virtual std::string getRealtimeData(const std::string& code) = 0;

    virtual std::string getBatchRealtimeData(const std::vector<std::string>& codes) = 0;
};

#endif // DATASOURCE_H
