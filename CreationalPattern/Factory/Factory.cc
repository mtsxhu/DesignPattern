#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Fruit
{
public:
    virtual string getName() = 0;
};
class Apple : public Fruit
{
public:
    string getName() override
    {
        return "苹果";
    }
};
class Banana : public Fruit
{
public:
    string getName() override
    {
        return "香蕉";
    }
};
class Factory
{
public:
    virtual shared_ptr<Fruit> createFruit() = 0;
};
class AppleFactory : public Factory
{
public:
    shared_ptr<Fruit> createFruit() override { return shared_ptr<Fruit>(new Apple); }
};
class BananaFactory : public Factory
{
public:
    shared_ptr<Fruit> createFruit() override { return shared_ptr<Fruit>(new Banana); }
};
