#include <iostream>
#include <string>
using namespace std;
//⼀个抽象的构件， 他是具体构件和抽象装饰类的⽗类。
class Phone
{
public:
    virtual void show() = 0;
};
//具体的构件
class iPhone : public Phone
{
public:
    iPhone(string kind)
    {
        this->kind = kind;
    }
    virtual void show()
    {
        cout << "秀出了	iPhone-" << kind << ":" << endl;
    }

private:
    string kind;
};

//具体的构件
class Mi : public Phone
{
public:
    Mi(string kind)
    {
        this->kind = kind;
    }
    virtual void show()
    {
        cout << "秀出了	Mi-" << kind << ":" << endl;
    }

private:
    string kind;
};
//抽象的⼿机装饰器类，必须包含抽象的构件
class DecoratorPhone : public Phone
{
public:
    DecoratorPhone()
    {
    }
    DecoratorPhone(Phone *phone)
    {
        this->phone = phone;
    }
    virtual void show()
    {
        this->phone->show();
    }

private:
    Phone *phone;
};
//具体的装饰器
class DecoratorPhoneMo : public DecoratorPhone
{
public:
    DecoratorPhoneMo(Phone *phone)
    {
        this->phone = phone;
    }
    virtual void show()
    {
        this->phone->show();
        AddMo();
    }
    void AddMo()
    {
        cout << "装饰：⼿机贴膜" << endl;
    }

private:
    Phone *phone;
};
//具体的装饰器
class DecoratorPhoneTao : public DecoratorPhone
{
public:
    DecoratorPhoneTao(Phone *phone)
    {
        this->phone = phone;
    }
    virtual void show()
    {
        this->phone->show();
        AddTao();
    }
    void AddTao()
    {
        cout << "装饰：⼿机外套" << endl;
    }

private:
    Phone *phone;
};
int main(void)
{
    //定义⼀个iphone	6	plus
    Phone *phone = new iPhone("6plus");
    phone->show();
    //给普通iphone	加上贴膜
    DecoratorPhone *hasMophone = new DecoratorPhoneMo(phone);
    //给普通iphone	加上⽪套
    DecoratorPhone *hasTaophone = new DecoratorPhoneTao(phone);
    hasMophone->show();
    hasTaophone->show();
    //给有⽪套的iphone	加上贴膜
    DecoratorPhone *hasMoTaophone = new DecoratorPhoneMo(hasTaophone);
    hasMoTaophone->show();
    delete hasTaophone;
    delete hasMophone;
    delete hasMoTaophone;
    delete phone;

    return 0;
}