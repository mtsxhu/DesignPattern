#include <iostream>
#include <string>
#include <memory>
using namespace std;

class OS
{
public:
    virtual void run() = 0;
};

class IOS : public OS
{
public:
    void run() override
    {
        cout << "运行IOS\n";
    }
};

class SaiBan : public OS
{
public:
    void run() override
    {
        cout << "运行SaiBan\n";
    }
};

class Phone
{
public:
    virtual void setOS(shared_ptr<OS> soft) = 0;
    virtual void run() = 0;
};
class IPhone : public Phone
{
private:
    shared_ptr<OS> os;

public:
    void setOS(shared_ptr<OS> os) override
    {
        this->os = os;
    }
    void run() override
    {
        this->os->run();
    }
};
class Nokia : public Phone
{
private:
    shared_ptr<OS> os;

public:
    void setOS(shared_ptr<OS> os) override
    {
        this->os = os;
    }
    void run() override
    {
        this->os->run();
    }
};