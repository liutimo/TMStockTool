#include "datasourcesina.h"
#include <cpprest/http_client.h>


using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

const std::string DataSourceSina::HOST = "https://hq.sinajs.cn/";



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
std::wstring DataSourceSina::getRealtimeData(const std::string &codes)
{
    http_client client(U("https://hq.sinajs.cn/"));
    uri_builder builder(U("/etag.php"));
    builder.append_query(U("_list"), U("sz301111"));

   http_request request(methods::GET);
   request.headers().add(U("Referer"), U("https://finance.sina.com.cn"));
   request.set_request_uri(builder.to_string());
    auto response = client.request(request).get();
//    return response.extract_utf8string(true).get();
    return response.extract_string().get();
}
