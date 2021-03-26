#include <iostream>
using namespace std;
//制作饮料
class Beverage
{
public:
    //	煮⽔
    void BoilWater()
    {
        cout << "烧开⽔" << endl;
    }
    //	冲泡		特殊接⼝
    virtual void Brew() = 0;
    //	倒⼊杯中
    void PourInCup()
    {
        cout << "倒⼊杯中" << endl;
    }
    //	添加料 特殊接⼝
    virtual void AddCondiments() = 0;
    //	hook	⽅法，决定某些算法步骤是否挂钩在算法中
    virtual bool CustomWantsCondiments()
    {
        return true;
    }
    //	模板⽅法
    void PrepareBeverage()
    {
        BoilWater();
        Brew();
        PourInCup();
        if (CustomWantsCondiments())
        {
            AddCondiments();
        }
    }
};

class Coffee : public Beverage
{
public:
    virtual void Brew()
    {
        cout << "冲泡咖啡⾖" << endl;
    }
    virtual void AddCondiments()
    {
        cout << "添加糖和⽜奶	" << endl;
    }
};

class Tea : public Beverage
{
public:
    virtual void Brew()
    {
        cout << "冲泡茶叶	" << endl;
    }
    virtual void AddCondiments()
    {
        cout << "添加柠檬	" << endl;
    }
};
int main(void)
{
    Beverage *pTea = new Tea;
    pTea->PrepareBeverage();
    delete pTea;
    cout << "---------------------" << endl;
    Beverage *pCoffee = new Coffee;
    pCoffee->PrepareBeverage();
    delete pCoffee;
    return 0;
}