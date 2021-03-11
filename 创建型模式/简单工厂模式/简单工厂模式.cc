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
enum class FruitType
{
    BANANA,
    APPLE
};
class Factory
{
public:
    shared_ptr<Fruit> createFruit(FruitType fruit)
    {
        switch (fruit)
        {
        case FruitType::APPLE:
            return shared_ptr<Fruit>(new Apple);
            break;

        case FruitType::BANANA:
            return shared_ptr<Fruit>(new Banana);
            break;
        }
    }
};
