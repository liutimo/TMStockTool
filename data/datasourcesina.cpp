#include "datasourcesina.h"
#include <cpprest/http_client.h>


using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


DataSourceSina::DataSourceSina()
{
    REQUEST_PARAM = web::json::value::object();
    REQUEST_PARAM[U("Referer")] = web::json::value::string(U("https://finance.sina.com.cn"));
}


/**
 *
 * @brief DataSourceSina::getRealtimeData
 * @param code
 * @return
 */
std::string DataSourceSina::getRealtimeData(const std::string &code)
{
    return getBatchRealtimeData({code});
}

std::string DataSourceSina::getBatchRealtimeData(const std::vector<std::string>& codes)
{
    if (codes.size() < 1) {
        return "";
    }

    string_t codesStr = conversions::to_string_t(codes[0]);
    for (int i = 1; i < codes.size(); ++i) {
        codesStr += U(",");
        codesStr += conversions::to_string_t(codes[i]);
    }


    http_client client(U("https://hq.sinajs.cn/"));
    uri_builder builder(U("/etag.php"));
    builder.append_query(U("_list"), codesStr);

    http_request request(methods::GET);
    request.headers().add(U("Referer"), U("https://finance.sina.com.cn"));
    request.set_request_uri(builder.to_string());
    auto response = client.request(request).get();
#ifdef win32
    return response.extract_utf8string(true).get();
#else
    return response.extract_string(true).get();
#endif
}
