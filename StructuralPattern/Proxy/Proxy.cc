#include <iostream>
using namespace std;

class GiveGift
{
public:
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};
class Pursuit : public GiveGift
{
private:
    string girlName;

public:
    Pursuit(string name) : girlName(name) {}
    void giveDolls() override
    {
        cout << "给" << girlName << "洋娃娃\n";
    }
    void giveFlowers() override
    {
        cout << "给" << girlName << "花\n";
    }
    void giveChocolate() override
    {
        cout << "给" << girlName << "巧克力\n";
    }
};
class Proxy : public GiveGift
{
private:
    Pursuit p;

public:
    Proxy(Pursuit p) : p(p) {}
    void giveDolls() override
    {
        cout << "帮别人：";
        p.giveDolls();
    }
    void giveFlowers() override
    {
        cout << "帮别人：";
        p.giveFlowers();
    }
    void giveChocolate() override
    {
        cout << "帮别人：";
        p.giveChocolate();
    }
};
int main()
{
    Pursuit pu("yy");
    Proxy p(pu);
    p.giveDolls();
    p.giveFlowers();
    p.giveChocolate();
}