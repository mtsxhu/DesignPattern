#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

/*饿汉式*/
class Hungry
{
public:
    // 对外提供一个获得Hungry实例的对象
    static shared_ptr<Hungry> getInstance()
    {
        return HungryInstance;
    }

private:
    // 将构造函数设置为私有成员
    Hungry(){};
    static shared_ptr<Hungry> HungryInstance;
};
// 静态对象在类外初始化，程序运行到这里就创建实例
shared_ptr<Hungry> Hungry::HungryInstance(new Hungry);

/*懒汉式*/
class Lazy
{
public:
    static shared_ptr<Lazy> getInstance()
    {
        if (LazyInstance == nullptr)
        {
            LazyInstance = shared_ptr<Lazy>(new Lazy);
        }

        return LazyInstance;
    }

private:
    Lazy(){};
    static shared_ptr<Lazy> LazyInstance;
};
// 懒汉式，在需要时才分配内存，因此初始化为nullptr
shared_ptr<Lazy> Lazy::LazyInstance = nullptr;

/*多线程安全的懒汉式01(double check lock)*/
//double check lock优势在于，减少加锁次数
class SafeLazy01
{
    static shared_ptr<SafeLazy01> getInstance()
    {
        if (SafeLazy01Instance == nullptr)
        {
            // 锁管理类，构造时加锁，析构时解锁
            // lock_guard和unique_lock区别在于unique_lock可以手动加解锁（便于解决异常）
            lock_guard<mutex> lg(m);
            if (SafeLazy01Instance == nullptr)
            {
                SafeLazy01Instance = shared_ptr<SafeLazy01>(new SafeLazy01);
            }
        }

        return SafeLazy01Instance;
    }

private:
    SafeLazy01(){};
    static shared_ptr<SafeLazy01> SafeLazy01Instance;
    // 锁，用于保护SafeLazy01Instance
    static mutex m;
};
shared_ptr<SafeLazy01> SafeLazy01::SafeLazy01Instance = nullptr;

/*多线程安全的懒汉式02(局部静态变量)*/
class SafeLazy02
{
    static SafeLazy02 *getInstance()
    {
        // c++ 保证静态局部变量只会被初始化一次
        static SafeLazy02 SafeLazy02Instance;
        return &SafeLazy02Instance;
    }

private:
    SafeLazy02(){};
};