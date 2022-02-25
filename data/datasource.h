#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <string>
#include <vector>

class DataSource {
public:
    virtual std::wstring getRealtimeData(const std::string& codes) = 0;
};

#endif // DATASOURCE_H
