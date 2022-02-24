#include "dataparsersina.h"

DataParserSina::DataParserSina()
{

}

/**
 * var hq_str_sh601006="大秦铁路, 27.55, 27.25, 26.91, 27.55, 26.20, 26.91, 26.92, 22114263, 589824680, 4695, 26.91, 57590, 26.90, 14700, 26.89, 14300, 26.88, 15100, 26.87, 3100, 26.92, 8900, 26.93, 14230, 26.94, 25150, 26.95, 15220, 26.96, 2008-01-11, 15:05:32";
 * @brief DataParserSina::parserRTData
 * @param originData
 * @return
 */
RTData DataParserSina::parserRTData(const std::string &originData)
{
    RTData rtdata;

    std::smatch m;
    std::regex regex("^.*hq_str_(.*)=\"(.*)\";$");

    auto found = std::regex_search(originData, m, regex);
    if (!found || m.size() < 3) {
        return rtdata;
    }
    rtdata.code = m.str(1);

    std::string stockInfoStr = m.str(2).c_str();

    auto array = split(stockInfoStr, ",");

    rtdata.name = array[0];
    rtdata.topen = std::stof(array[1]);
    rtdata.yclose = std::stof(array[2]);
    rtdata.now = std::stof(array[3]);


    return RTData();
}