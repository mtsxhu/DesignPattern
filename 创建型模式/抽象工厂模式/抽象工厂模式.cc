#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Appler
{
public:
    virtual string getName() = 0;
};
class Bananaer
{
public:
    virtual string getName() = 0;
};
class ChinaApple : public Appler
{
public:
    string getName() override
    {
        return "中国苹果";
    }
};
class ChinaBanana : public Bananaer
{
public:
    string getName() override
    {
        return "中国香蕉";
    }
};
class USAApple : public Appler
{
public:
    string getName() override
    {
        return "美国苹果";
    }
};
class USABanana : public Bananaer
{
public:
    string getName() override
    {
        return "美国香蕉";
    }
};
class Factory
{
public:
    virtual shared_ptr<Appler> createApple() = 0;
    virtual shared_ptr<Bananaer> createBanana() = 0;
};
class ChinaFactory : public Factory
{
public:
    shared_ptr<Appler> createApple() override { return shared_ptr<Appler>(new ChinaApple); }
    shared_ptr<Bananaer> createBanana() override { return shared_ptr<Bananaer>(new ChinaBanana); }
};
class USAFactory : public Factory
{
public:
    shared_ptr<Appler> createApple() override { return shared_ptr<Appler>(new USAApple); }
    shared_ptr<Bananaer> createBanana() override { return shared_ptr<Bananaer>(new USABanana); }
};