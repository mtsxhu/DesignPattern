#include <iostream>
using namespace std;
/*这⾥定义四个⼦类系统*/
class SubSystem1
{
public:
    void Methor1()
    {
        cout << "⼦系统⽅法⼀" << endl;
    }
};
class SubSystem2
{
public:
    void Methor2()
    {
        cout << "⼦系统⽅法⼆" << endl;
    }
};
class SubSystem3
{
public:
    void Methor3()
    {
        cout << "⼦系统⽅法三" << endl;
    }
};
class SubSystem4
{
public:
    void Methor4()
    {
        cout << "⼦系统⽅法四" << endl;
    }
};
/*
			外观类，接⼝
	*/
class Facade
{
    SubSystem1 *one;
    SubSystem2 *two;
    SubSystem3 *three;
    SubSystem4 *four;
    /*构造函数*/
public:
    Facade()
    {
        one = new SubSystem1();
        two = new SubSystem2();
        three = new SubSystem3();
        four = new SubSystem4();
    }
    ~Facade()
    {
        delete one;
        delete two;
        delete three;
        delete four;
    }
    void MethorA()
    {
        cout << "⽅法组A()" << endl;
        one->Methor1();
        two->Methor2();
    }
    void MethorB()
    {
        cout << "⽅法组B()" << endl;
        three->Methor3();
        four->Methor4();
    }
};
/*
			客户端调⽤，客户端只需要与接⼝Facade交互就可以访问四个⼦类系统了
	*/
int main()
{
    Facade facade;
    facade.MethorA();
    facade.MethorB();
}