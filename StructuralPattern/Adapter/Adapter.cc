#include <iostream>
using namespace std;
//target
class V5
{
public:
    virtual void useV5() = 0;
};
//	Adaptee
class V220
{
public:
    virtual void useV220()
    {
        cout << "	⽤220V电压进⾏充电" << endl;
    }
};
//	Adapter	充电器
class ChargerAdapter : public V5
{
public:
    virtual void useV5()
    {
        cout << "充电器对电压进⾏适配	" << endl;
        m_p220v.useV220();
    }

private:
    V220 m_p220v;
};
class Phone
{
public:
    Phone()
    {
        v5Adapter = new ChargerAdapter;
    }
    ~Phone()
    {
        if (v5Adapter != NULL)
        {
            delete v5Adapter;
        }
    }
    //充电
    void charge()
    {
        cout << "⼿机进⾏充电" << endl;
        v5Adapter->useV5();
    }

private:
    //5v⼿机充电器
    V5 *v5Adapter;
};
int main(void)
{
    Phone iphone;
    //⼿机进⾏充电
    iphone.charge();
    return 0;
}