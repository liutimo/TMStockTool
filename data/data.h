#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>


class StockBase {
public:
    StockBase() {}

    StockBase(const std::string &code, const std::string &name);

    StockBase(const StockBase&);
    StockBase(const StockBase&&);
    virtual StockBase &operator=(const StockBase&);
    virtual StockBase &operator=(const StockBase&&);

    void setCode(const std::string& code);
    const std::string & getCode() const;

    void setName(const std::string& name);
    const std::string & getName() const;

    bool isValid() const {
        return !mName.empty();
    }

    virtual std::string toString() const;
protected:
    std::string mCode;
    std::string mName;
};


class RTData : public StockBase{

public:
    RTData() = default;

    RTData(const std::string &code, const std::string &name,
           float topen, float yclose, float now, const std::string &updatedTime = "");

    RTData(const RTData&);
    RTData(const RTData&&);

   virtual RTData &operator=(const RTData&);
   virtual RTData &operator=(const RTData&&);


    void setTOpen(float topen);

    void setYClose(float yclose);

    float getNow() const;
    void setNow(float now);



    float getIncRate() const;

    float getIncQuota() const;

    const std::string &getUpdatedTime() const;

    void setUpdatedTime(const std::string &updatedTime);

private:
    float mTOpen;
    float mYClose;
    float mNow;
    std::string mUpdatedTime;
};


#endif // DATA_H
