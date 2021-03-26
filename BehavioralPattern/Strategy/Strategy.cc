#include <iostream>
using namespace std;
//武器装备策略
class WeaponStrategy
{
public:
    virtual void useWeapon() = 0;
};
//武器装备策略1	-	使⽤AK47	机枪
class AK47 : public WeaponStrategy
{
public:
    virtual void useWeapon()
    {
        cout << "Use	AK47	to	shoot!" << endl;
    }
};
//武器装备策略2	-	使⽤⼔⾸
class Knife : public WeaponStrategy
{
public:
    virtual void useWeapon()
    {
        cout << "Use	Knife	to	kill" << endl;
    }
};
//相当于Context	， 使⽤抽象的武器⻛格，挥出不同的装备
class Character
{
public:
    void setWeapon(WeaponStrategy *strategy)
    {
        wStrategy = strategy;
    }
    void fight()
    {
        wStrategy->useWeapon();
    }

private:
    WeaponStrategy *wStrategy;
};
int main(void)
{
    WeaponStrategy *strategy = new Knife;
    Character *c = new Character;
    //使⽤⼔⾸策略
    c->setWeapon(strategy);
    c->fight();
    delete strategy;

    //AK47	装备策略
    strategy = new AK47;
    c->setWeapon(strategy);
    c->fight();
    delete strategy;
    delete c;
    return 0;
}