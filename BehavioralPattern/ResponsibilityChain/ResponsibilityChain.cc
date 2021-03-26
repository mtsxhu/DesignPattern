#include <iostream>
#include <memory>
using namespace std;

struct Request
{
    string name;        //消息来源
    string requestType; // 消息类型，如请假
    int count;          // 数量，如请假天数
};

class Manager
{
private:
    /* data */
public:
    Manager(string name) : name(name) {}
    void setSuperior(shared_ptr<Manager> super) { superior = super; };
    virtual void requestApplication(Request request) = 0;

protected:
    string name;
    shared_ptr<Manager> superior; //管理者上级
};

class CommonManager : public Manager
{
public:
    CommonManager(string name) : Manager(name) {}
    void requestApplication(Request request) override
    {
        // 当前管理者只能批两天的假
        if (request.requestType == "请假" && request.count <= 2)
        {
            cout << request.name << " : " << request.requestType << " " << request.count << endl;
        }
        else //权限不足，交给上级处理
        {
            superior->requestApplication(request);
        }
    }
};
class Majordomo : public Manager
{
public:
    Majordomo(string name) : Manager(name) {}
    void requestApplication(Request request) override
    {
        // 当前管理者只能批五天的假
        if (request.requestType == "请假" && request.count <= 5)
        {
            cout << request.name << " : " << request.requestType << " " << request.count << endl;
        }
        else //权限不足，交给上级处理
        {
            superior->requestApplication(request);
        }
    }
};
// 还需要个管理者，能够处理所有请求

int main()
{
    shared_ptr<Manager> m1(new CommonManager("m1"));
    shared_ptr<Manager> m2(new Majordomo("m2"));
    m1->setSuperior(m2);
    Request r1{"lcx", "请假", 2};
    Request r2{"yy", "请假", 5};

    m1->requestApplication(r1);
    m1->requestApplication(r2);
}