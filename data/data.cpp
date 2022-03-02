#include "data.h"

//////StockBase
StockBase::StockBase(const std::string &code, const std::string &name)
    : mCode(code), mName(name)
{

}

StockBase::StockBase(const StockBase &other)
{
    if (this != &other) {
        mCode = other.mCode;
        mName = other.mName;
    }
}

StockBase::StockBase(const StockBase &&other)
{
    if (this != &other) {
        mCode = std::move(other.mCode);
        mName = std::move(other.mName);
    }
}

StockBase &StockBase::operator=(const StockBase &other)
{
    if (this != &other) {
        mCode = other.mCode;
        mName = other.mName;
    }
    return *this;
}


StockBase &StockBase::operator=(const StockBase &&other)
{
    if (this != &other) {
        mCode = std::move(other.mCode);
        mName = std::move(other.mName);
    }
    return *this;
}

void StockBase::setCode(const std::string& code)
{
    mCode = code;
}

const std::string& StockBase::getCode() const
{
    return mCode;
}

void StockBase::setName(const std::string& name)
{
    mName = name;
}

const std::string & StockBase::getName() const
{
    return mName;
}

std::string StockBase::toString() const
{
    return "StockBase: { Name: " + mName + " Code:" + mCode + "}";
}

/////RTData
RTData::RTData(const std::string &code, const std::string &name, float topen, float yclose, float now, const std::string &updatedTime) :
    StockBase(code, name), mTOpen(topen), mYClose(yclose), mNow(now), mUpdatedTime(updatedTime)
{

}


RTData::RTData(const RTData &other) : StockBase(other)
{
    mTOpen = other.mTOpen;
    mYClose = other.mYClose;
    mNow = other.mNow;
    mUpdatedTime = other.mUpdatedTime;
}


RTData::RTData(const RTData &&other) : StockBase(other)
{
    mTOpen = std::move(other.mTOpen);
    mYClose = std::move(other.mYClose);
    mNow = std::move(other.mNow);
    mUpdatedTime = std::move(other.mUpdatedTime);
}

RTData& RTData::operator=(const RTData &other)
{
    StockBase::operator=(other);
    mTOpen = other.mTOpen;
    mYClose = other.mYClose;
    mNow = other.mNow;
    mUpdatedTime = other.mUpdatedTime;
    return *this;
}

RTData& RTData::operator=(const RTData &&other)
{
    StockBase::operator=(other);
    mTOpen = std::move(other.mTOpen);
    mYClose = std::move(other.mYClose);
    mNow = std::move(other.mNow);
    mUpdatedTime = std::move(other.mUpdatedTime);
    return *this;
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

