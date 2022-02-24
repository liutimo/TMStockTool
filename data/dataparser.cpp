#include "dataparser.h"

#include <string>
#include <vector>
#include <iterator>

#define CHECK_NE(a, b) \
    if ((a) == (b)) abort();

static void trim_left(std::string &str) {
  str.erase(std::begin(str),
            std::find_if(std::begin(str), std::end(str),
                         [](int ch) { return !std::isspace(ch); }));
}

static void trim_right(std::string &str) {
  str.erase(std::find_if(str.rbegin(), str.rend(),
                         [](int ch) { return !std::isspace(ch); })
                .base(),
            std::end(str));
}

static void trim(std::string &str) {
  trim_left(str);
  trim_right(str);
}


std::vector<std::string> split(const std::string& s, const std::string& delimiters) {
    CHECK_NE(delimiters.size(), 0);

    std::vector<std::string> result;

    size_t base = 0;
    size_t found;

    while (true) {
        found = s.find_first_of(delimiters, base);
        std::string substr = s.substr(base, found - base);
        trim(substr);
        result.push_back(substr);
        if (found == s.npos) break;
        base = found + 1;
    }
    return result;
}
