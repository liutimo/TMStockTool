#include "data.h"


RTData::RTData(const std::string &code, const std::string &name, float topen, float yclose, float now, const std::string &updatedTime) :
    mCode(code), mName(name), mTOpen(topen), mYClose(yclose), mNow(now), mUpdatedTime(updatedTime)
{

}


RTData::RTData(const RTData &rtData)
{
    mCode = rtData.mCode;
    mName = rtData.mName;
    mTOpen = rtData.mTOpen;
    mYClose = rtData.mYClose;
    mNow = rtData.mNow;
    mUpdatedTime = rtData.mUpdatedTime;
}

const std::string &RTData::getCode() const
{
    return mCode;
}

void RTData::setCode(const std::string &code)
{
    mCode = code;
}

const std::string &RTData::getName() const
{
    return mName;
}

void RTData::setName(const std::string &name)
{
    mName = name;
}

void RTData::setTOpen(float topen)
{
    mTOpen = topen;
}

void RTData::setYClose(float yclose)
{
    mYClose = yclose;
}

float RTData::getNow() const
{
    return mNow;
}

void RTData::setNow(float now)
{
    mNow = now;
}

float RTData::getIncRate() const
{
    return (mNow - mYClose) / mYClose * 100;
}

float RTData::getIncQuota() const
{
    return mNow - mYClose;
}

const std::string &RTData::getUpdatedTime() const
{
    return mUpdatedTime;
}

void RTData::setUpdatedTime(const std::string &updatedTime)
{
    mUpdatedTime = updatedTime;
}
