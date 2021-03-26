#include <iostream>
#include <string>
#include <list>
using namespace std;
//	抽象的观察者， 被动监听⽼师的动向。
class TeacherListenner
{
public:
    //当⽼师来了之后，应该做的具体动作。
    virtual void onTecherComming() = 0;
    virtual void doBadThing() = 0;
    virtual void stopBadThing() = 0;
};
//具体的观察者， 发现通知者来消息，做出相应的动作
class Student : public TeacherListenner
{
public:
    Student(string name, string badthing)
    {
        this->name = name;
        this->badthing = badthing;
    }
    virtual void onTecherComming()
    {
        stopBadThing();
    }
    void doBadThing()
    {
        cout << name << "，开始" << badthing << endl;
    }
    void stopBadThing()
    {
        cout << name << ",	发现⽼师来了，停⽌" << badthing << endl;
    }

private:
    string name;
    string badthing;
};
//主题， 这⾥为抽象的通知者。
class INotifier
{
public:
    virtual void addListenner(TeacherListenner *listenner) = 0;
    virtual void removeListenner(TeacherListenner *listenner) = 0;
    virtual void notify() = 0;
};
//班⻓,	作为具体的通知者， 这⾥为 具体的主题，和具体的被观察对象
//	同学们不是观察⽼师，⽽是观察班⻓的动作，来间接知道⽼师是否有来
class Monitor : public INotifier
{
public:
    virtual void addListenner(TeacherListenner *listenner)
    {
        m_list.push_back(listenner);
    }
    virtual void removeListenner(TeacherListenner *listenner)
    {
        m_list.remove(listenner);
    }
    //班⻓发现⽼师来了， 通知所有 已经观察⾃⼰动作的学⽣。
    virtual void notify()
    {
        list<TeacherListenner *>::iterator it = m_list.begin();
        for (; it != m_list.end(); it++)
        {
            (*it)->onTecherComming(); //通知⼤家 ⽼师来了。
        }
    }

private:
    list<TeacherListenner *> m_list;
};
int main(void)
{
    Monitor monitor;
    Student xiaowang("⼩王", "抄作业");
    Student xiaoli("⼩李", "打游戏");
    monitor.addListenner(&xiaowang);
    monitor.addListenner(&xiaoli);
    xiaowang.doBadThing();
    xiaoli.doBadThing();
    cout << "这个时候⽼师来了，班⻓通知所有的观察者..." << endl;
    monitor.notify();
    return 0;
}