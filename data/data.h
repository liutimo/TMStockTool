#ifndef DATA_H
#define DATA_H

#include <string>

typedef struct  {
    std::string code;
    std::string name;
    float topen;  //今日开盘
    float yclose; //昨日收盘
    float now;
} RTData;


#endif // DATA_H
