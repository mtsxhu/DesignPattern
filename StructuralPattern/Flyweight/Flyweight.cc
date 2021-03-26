#include <iostream>
#include <map>
using namespace std;

/*
    共享的是存放网站分类的map（外部状态）
    不共享的是使用用户user（内部状态）
*/
class User
{
private:
    string name;

public:
    User(string name) : name(name) {}
    string getName() { return name; }
};
class WebSite
{
public:
    virtual void Use(User use) = 0;
};
class ConcreteWebSite : public WebSite
{
private:
    string name;

public:
    ConcreteWebSite(string name) : name(name) {}
    void Use(User user) override
    {
        cout << "网站分类：" << name << " 用户：" << user.getName() << endl;
    }
};

class WebSiteFactory
{
private:
    map<string, shared_ptr<WebSite>> m;

public:
    shared_ptr<WebSite> getWebSiteCategory(string key)
    {
        if (m.find(key) == m.end())
        {
            m.insert(make_pair(key, new ConcreteWebSite(key)));
        }
        return m[key];
    }
    int getWebSiteCount()
    {
        return m.size();
    }
};

int main()
{
    User u1("yy");
    User u2("lcx");
    WebSiteFactory f;
    shared_ptr<WebSite> w1 = f.getWebSiteCategory("产品展示");
    w1->Use(u1);
    shared_ptr<WebSite> w2 = f.getWebSiteCategory("产品展示");
    w2->Use(u2);
    shared_ptr<WebSite> w3 = f.getWebSiteCategory("博客");
    w2->Use(u1);
    shared_ptr<WebSite> w4 = f.getWebSiteCategory("博客");
    w4->Use(u2);

    cout << "网站分类总数为：" << f.getWebSiteCount() << endl;
}