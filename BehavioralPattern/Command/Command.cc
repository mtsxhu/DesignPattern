#include <queue>
#include <string>
#include <iostream>
using namespace std;
class Barbecuer
{
public:
    void bakeMutton()
    {
        cout << "烤羊肉串" << endl;
    }
    void bakeChicken()
    {
        cout << "烤鸡翅" << endl;
    }
};
class Command
{
protected:
    Barbecuer revicer; //烧烤师傅
    // TODO 使用enum
    string type; // 命令类型

public:
    Command(Barbecuer revicer, string type) : revicer(revicer), type(type) {}
    virtual void ExcuteCommand() = 0;
    string getType() { return type; }
};
class BakeMuttonCommand : public Command
{
private:
public:
    BakeMuttonCommand(Barbecuer revicer, string type) : Command(revicer, type) {}
    void ExcuteCommand() override
    {
        revicer.bakeMutton();
    }
};
class BakeChickenCommand : public Command
{
private:
public:
    BakeChickenCommand(Barbecuer revicer, string type) : Command(revicer, type) {}
    void ExcuteCommand() override
    {
        revicer.bakeChicken();
    }
};

class Waiter
{
private:
    queue<Command *> coms;

public:
    void setOrder(Command *com)
    {
        if (com->getType() == "BakeChickenCommand")
        {
            cout << "鸡翅没有了" << endl;
        }
        else
        {
            coms.push(com);
            cout << "创建订单烤羊肉串\n";
        }
    }
    void CancelOrder()
    {
    }
    void notify()
    {
        while (!coms.empty())
        {
            coms.front()->ExcuteCommand();
            coms.pop();
        }
    }
};
int main()
{
    Barbecuer b;
    Command *c1 = new BakeMuttonCommand(b, "BakeMuttonCommand");
    Command *c2 = new BakeMuttonCommand(b, "BakeMuttonCommand");
    Command *c3 = new BakeChickenCommand(b, "BakeChickenCommand");
    Waiter w;
    w.setOrder(c1);
    w.setOrder(c2);
    w.setOrder(c3);
    w.notify();
}