#include "datasourceig507.h"
#include <cpprest/http_client.h>


using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


const std::string DataSourceIG507::LICENCE = "2VT7Fu5fG3nGxeAkoLitnx+AzI5lnfnGopB4mvoZVw";
const std::string DataSourceIG507::BASE_URI = "https://ig507.com";

DataSourceIG507::DataSourceIG507()
{

}

std::string DataSourceIG507::getRealtimeData(const std::string &code)
{
    return {};
}

std::string DataSourceIG507::getBatchRealtimeData(const std::vector<std::string> &codes)
{
    return {};
}

std::string DataSourceIG507::getAllBigAStock()
{
    http_client client(conversions::to_string_t(BASE_URI));
    uri_builder builder(U("/data/base/gplist"));
    builder.append_query(U("licence"), conversions::to_string_t(LICENCE));

    http_request request(methods::GET);
    request.set_request_uri(builder.to_string());
    auto response = client.request(request).get();
#ifdef WIN32
    return response.extract_utf8string(true).get();
#else
    return response.extract_string(true).get();
#endif
}
