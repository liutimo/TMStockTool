#ifndef DATA_H
#define DATA_H

#include <string>

class RTData {

public:
    RTData() = default;

    RTData(const std::string &code, const std::string &name,
           float topen, float yclose, float now);

    RTData(const RTData&);

    const std::string &getCode() const;
    void setCode(const std::string &code);

    const std::string &getName() const;
    void setName(const std::string &name);

    void setTOpen(float topen);

    void setYClose(float yclose);

    float getNow() const;
    void setNow(float now);

    bool isValid() const {
        return !mName.empty();
    }

    float getIncRate() const;

    float getIncQuota() const;
private:
    std::string mCode;
    std::string mName;
    float mTOpen;
    float mYClose;
    float mNow;
};


#endif // DATA_H
